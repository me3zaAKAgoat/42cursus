CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker

HEADERS = ./includes/linked_list.h ./includes/push_swap.h

MAIN_SOURCE = ./src/main.c

LINKED_LIST_SOURCES = ./src/linked_list/ll_push.c ./src/linked_list/ll_unshift.c \
./src/linked_list/ll_clear.c ./src/linked_list/ll_del_one.c ./src/linked_list/ll_iter.c ./src/linked_list/ll_is_in.c \
./src/linked_list/ll_last.c ./src/linked_list/ll_map.c ./src/linked_list/ll_new.c ./src/linked_list/ll_size.c\
./src/linked_list/ll_min.c ./src/linked_list/ll_max.c ./src/linked_list/ll_fill_int.c ./src/linked_list/ll_atindex.c\
./src/linked_list/ll_get_index.c ./src/linked_list/ll_value_atindex.c ./src/linked_list/ll_pop.c ./src/linked_list/ll_shift.c\

UTIL_SOURCES = ./src/util/ft_atol.c ./src/util/ft_split.c ./src/util/ft_strlen.c \
./src/util/ft_substr.c ./src/util/ft_memcpy.c ./src/util/ft_strlcpy.c\
./src/util/ft_strncmp.c ./src/util/exit_gracefully.c

CORE_MODULES_SOURCES = ./src/sorting/best_move.c ./src/sorting/lis.c ./src/sorting/rotate.c ./src/sorting/util.c ./src/parsing/parse.c\
./src/parsing/util.c ./src/parsing/wrexit.c ./src/sorting/edge_cases.c ./src/sorting/check_sorted.c

STACK_UTIL_SOURCES = ./src/stack_util/pa.c ./src/stack_util/pb.c ./src/stack_util/ra.c ./src/stack_util/rb.c ./src/stack_util/rr.c\
./src/stack_util/sb.c ./src/stack_util/sa.c ./src/stack_util/ss.c ./src/stack_util/rrr.c ./src/stack_util/rra.c ./src/stack_util/rrb.c

BONUS_SOURCES = ./src/bonus/checker.c ./src/bonus/gnl/get_next_line.c ./src/bonus/gnl/get_next_line_utils.c

MAIN_OBJECT = $(MAIN_SOURCE:.c=.o)

LINKED_LIST_OBJECTS = $(LINKED_LIST_SOURCES:.c=.o)

UTIL_OBJECTS = $(UTIL_SOURCES:.c=.o)

CORE_MODULES_OBJECTS = $(CORE_MODULES_SOURCES:.c=.o)

STACK_UTIL_OBJECTS = $(STACK_UTIL_SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(MAIN_OBJECT) $(LINKED_LIST_OBJECTS) $(UTIL_OBJECTS) $(CORE_MODULES_OBJECTS) $(STACK_UTIL_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJECT) $(LINKED_LIST_OBJECTS) $(UTIL_OBJECTS) $(CORE_MODULES_OBJECTS) $(STACK_UTIL_OBJECTS)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJECTS) $(LINKED_LIST_OBJECTS) $(UTIL_OBJECTS) $(CORE_MODULES_OBJECTS) $(STACK_UTIL_OBJECTS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJECTS) $(LINKED_LIST_OBJECTS) $(UTIL_OBJECTS) $(CORE_MODULES_OBJECTS) $(STACK_UTIL_OBJECTS)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	rm -f $(MAIN_OBJECT) $(BONUS_OBJECTS) $(LINKED_LIST_OBJECTS) $(UTIL_OBJECTS) $(CORE_MODULES_OBJECTS) $(STACK_UTIL_OBJECTS)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME) $(MAIN_OBJECT) $(BONUS_OBJECTS) $(LINKED_LIST_OBJECTS) $(UTIL_OBJECTS) $(CORE_MODULES_OBJECTS) $(STACK_UTIL_OBJECTS)

re : fclean all

.PHONY : fclean re clean all bonus