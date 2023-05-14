#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>


//time in milliseconds
typedef	unsigned long msecond;

typedef struct s_philosopher
{
	int				philo_id;
	pthread_t		thread_id;
	pthread_mutex_t	fork;
	unsigned long	last_ate;
	int				meals_count;
} t_philosopher;

typedef struct s_meta
{
	int				nbr_philosophers;
	msecond			time_eat;
	msecond			time_die;
	msecond			time_sleep;
	int				meal_threshold;
	msecond			program_start;
	t_philosopher	*philosophers;
} t_meta;

typedef struct s_thread_args
{
	t_meta	*meta;
	int		philo_id;
} t_thread_args;

msecond get_time()
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec * 1000);
}

void	*routine(void	*ptr)
{
	int				philo_id;
	t_meta			*meta;
	t_thread_args	*args;

	args = (t_thread_args*) ptr;
	philo_id = args->philo_id;
	meta = args->meta;
	while (1)
	{
		pthread_mutex_lock(&meta->philosophers[philo_id].fork);
		printf("%lu: %d has taken fork", get_time() - meta->program_start, philo_id + 1);
		pthread_mutex_lock(&meta->philosophers[(philo_id + 1) % meta->nbr_philosophers].fork);
		printf("%lu: %d has taken fork", get_time() - meta->program_start, philo_id + 1);
		printf("%lu: %d is eating", get_time() - meta->program_start, philo_id + 1);
		usleep(meta->time_eat * 1000);
		meta->philosophers[philo_id].last_ate = get_time();
		meta->philosophers[philo_id].meals_count++;
		pthread_mutex_unlock(&meta->philosophers[philo_id].fork);
		pthread_mutex_unlock(&meta->philosophers[(philo_id + 1) % meta->nbr_philosophers].fork);
		if (meta->philosophers[philo_id].meals_count >= meta->meal_threshold)
			break ;
		printf("%lu: %d is sleeping", get_time() - meta->program_start, philo_id + 1);
		usleep(meta->time_sleep * 1000);
		printf("%lu: %d is thinking", get_time() - meta->program_start, philo_id + 1);
	}
	return (NULL);

}


/* check wether mutex init can fail*/
int	init_philosophers(t_meta *meta, t_philosopher *philosophers)
{
	int	i;

	i = 0;
	philosophers = malloc(meta->nbr_philosophers * sizeof(t_philosopher));
	if (!philosophers)
		return (-1);
	while (i < meta->nbr_philosophers)
	{
		pthread_mutex_init(&philosophers[i].fork, NULL);
		philosophers[i].last_ate = get_time();
		philosophers[i].meals_count = 0;
		philosophers[i].philo_id = i;
	}
	return (0);
}

void	init_meta(t_meta *meta, char **av)
{
	meta->program_start = get_time();
	meta->nbr_philosophers = atoi(av[1]);
	meta->time_die = atoi(av[2]);
	meta->time_eat = atoi(av[3]);
	meta->time_sleep = atoi(av[4]);
}

/* need to handle optinal 5th argument*/
int main(int ac, char **av)
{
	t_philosopher	*philosophers;
	t_meta			meta;
	t_thread_args	thread_args;
	int	i;

	init_meta(&meta, av);
	if (init_philosophers(&meta, philosophers) == -1)
		exit(1);
	meta.philosophers = philosophers;
	i = 0;
	while (i < meta.nbr_philosophers)
	{
		thread_args.philo_id = i;
		thread_args.meta = &meta;
		pthread_create(&philosophers[i].thread_id, NULL, routine, &thread_args);
		pthread_detach(philosophers[i].thread_id);
	}
	exit(0);
}