CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

HEADERS = ./includes/linked_list.h ./includes/push_swap.h

DEPENDENCY_SOURCES =  ./src/main.c ./src/cursus_functions/ft_atoi.c ./src/cursus_functions/ft_split.c ./src/cursus_functions/ft_strlen.c \
./src/cursus_functions/ft_substr.c ./src/linked_list/ll_push.c ./src/linked_list/ll_unshift.c \
./src/linked_list/ll_clear.c ./src/linked_list/ll_del_one.c ./src/linked_list/ll_iter.c \
./src/linked_list/ll_last.c ./src/linked_list/ll_map.c ./src/linked_list/ll_new.c ./src/linked_list/ll_size.c\
./src/linked_list/ll_fill_int.c ./src/linked_list/ll_atindex.c ./src/linked_list/ll_get_index.c ./src/linked_list/ll_value_atindex.c\
./src/linked_list/ll_pop.c ./src/linked_list/ll_shift.c ./src/stack_utils/pa.c ./src/stack_utils/pb.c ./src/stack_utils/ra.c\
./src/stack_utils/rb.c ./src/stack_utils/rr.c ./src/stack_utils/sb.c ./src/stack_utils/sa.c ./src/stack_utils/rrr.c\
./src/stack_utils/rra.c ./src/stack_utils/rrb.c

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