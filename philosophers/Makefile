CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g
# CFLAGS = -Wall -Wextra -Werror
NAME = philo
BONUS_NAME = philo_bonus

HEADERS = ./includes/philo.h

MANDATORY_SOURCES = ./src/philo/main.c ./src/philo/ft_atoi.c ./src/philo/util.c ./src/philo/ft_strlen.c ./src/philo/init.c

MANDATORY_OBJECTS = $(MANDATORY_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(MANDATORY_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJECTS)

bonus : $(BONUS_NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	rm -f $(MANDATORY_OBJECTS)

fclean : clean
	rm -f $(MANDATORY_OBJECTS) $(NAME)

re : fclean all

.PHONY : fclean re clean all bonus