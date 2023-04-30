CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

HEADERS = ./includes/linked_list.h ./includes/push_swap.h

DEPENDENCY_SOURCES =  ./src/main.c ./src/cursus_functions/ft_atoi.c ./src/cursus_functions/ft_split.c ./src/cursus_functions/ft_strlen.c \
./src/cursus_functions/ft_substr.c ./src/linked_list/lst_push.c ./src/linked_list/lst_unshift.c \
./src/linked_list/lst_clear.c ./src/linked_list/lst_del_one.c ./src/linked_list/lst_iter.c \
./src/linked_list/lst_last.c ./src/linked_list/lst_map.c ./src/linked_list/lst_new.c ./src/linked_list/lst_size.c ./src/linked_list/lst_fill_int.c\
./src/linked_list/lst_atindex.c ./src/linked_list/lst_get_index.c ./src/linked_list/lst_value_atindex.c
DEPENDENCY_OBJECTS = $(DEPENDENCY_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(DEPENDENCY_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(DEPENDENCY_OBJECTS)

bonus :

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	rm -f $(DEPENDENCY_OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : fclean re clean all bonus