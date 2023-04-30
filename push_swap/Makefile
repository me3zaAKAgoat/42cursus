CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

HEADERS = ./includes/linked_list.h ./includes/push_swap.h

DEPENDENCY_SOURCES =  ./src/main.c ./src/cursus_functions/ft_atoi.c ./src/cursus_functions/ft_split.c ./src/cursus_functions/ft_strlen.c \
./src/cursus_functions/ft_substr.c ./src/linked_list/ft_lstadd_back.c ./src/linked_list/ft_lstadd_front.c \
./src/linked_list/ft_lstclear.c ./src/linked_list/ft_lstdelone.c ./src/linked_list/ft_lstiter.c \
./src/linked_list/ft_lstlast.c ./src/linked_list/ft_lstmap.c ./src/linked_list/ft_lstnew.c ./src/linked_list/ft_lstsize.c ./src/linked_list/ft_lstfilled_w_int.c\
./src/linked_list/ft_lstatindex.c ./src/linked_list/ft_lstgetindex.c ./src/linked_list/ft_lstvalueatindex.c
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