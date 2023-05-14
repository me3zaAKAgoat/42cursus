#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

//time in milliseconds
typedef	long long time;

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
	int		nbr_philosophers;
	time	time_eat;
	time	time_die;
	time	time_sleep;
	int		meal_count_threshold;
} t_meta;

time get_time()
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec * 1000);
}

void	routine(t_philosopher philosopher, int philo_id)
{
	while (1)
	{
		pthread_mutex_lock(philosopher)
	}

}


/* check wether mutex init can fail*/
int	init_philosophers(t_meta *meta, t_philosopher *philosophers)
{
	int	i;

	i = 0;
	philosophers = malloc(atoi(meta->nbr_philosophers) * sizeof(t_philosopher));
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
	int	i;

	init_meta(&meta, av);
	if (init_philosophers(&meta, philosophers) == -1)
		exit(1);
	i = 0;
	while (i < meta.nbr_philosophers)
	{
		pthread_create(&philosophers[i].thread_id, NULL, routine, &philosophers[i]);
	}
	exit(0);
}