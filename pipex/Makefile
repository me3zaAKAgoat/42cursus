CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

HEADERS = ./includes/pipex.h ./includes/get_next_line.h

MANDATORY_SOURCES = ./src/mandatory.c
MANDATORY_OBJECTS = $(MANDATORY_SOURCES:.c=.o)

BONUS_SOURCES = ./src/bonus.c ./src/cursus_functions/gnl/get_next_line.c ./src/cursus_functions/gnl/get_next_line_utils.c \
 ./src/utility/here_doc.c ./src/utility/open_inout.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

SHARED_SOURCES =  ./src/utility/error_funcs.c ./src/utility/fork_core.c ./src/utility/free_struct.c ./src/utility/get_cmdpath.c ./src/utility/get_pathenv.c \
 ./src/cursus_functions/ft_split.c ./src/cursus_functions/ft_strjoin.c ./src/cursus_functions/ft_strlen.c \
 ./src/cursus_functions/ft_strnstr.c ./src/cursus_functions/ft_substr.c
SHARED_OBJECTS = $(SHARED_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(MANDATORY_OBJECTS) $(SHARED_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJECTS) $(SHARED_OBJECTS)

bonus : $(BONUS_OBJECTS) $(SHARED_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJECTS) $(SHARED_OBJECTS)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	rm -f $(MANDATORY_OBJECTS) $(BONUS_OBJECTS) $(SHARED_OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : fclean re clean all bonus