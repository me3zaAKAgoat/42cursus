CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g
# CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus

HEADERS = philo_bonus.h

SOURCES = main.c ft_atoi.c util.c ft_strlen.c init.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(OBJECTS) $(NAME)

re : fclean all

.PHONY : fclean re clean all bonus