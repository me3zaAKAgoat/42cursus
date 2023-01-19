CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

HEADERS = ./includes/pipex.h ./includes/get_next_line.h

MANDATORY_SOURCES = ./src/mandatory.c

BONUS_SOURCES = ./src/bonus.c ./src/cursus_functions/gnl/get_next_line.c ./src/cursus_functions/gnl/get_next_line_utils.c \
 ./src/utility/here_doc.c ./src/utility/open_inout.c

SHARED_SOURCES =  ./src/utility/fork_core.c ./src/utility/free_struct.c ./src/utility/get_cmdpath.c ./src/utility/get_pathenv.c \
 ./src/cursus_functions/ft_split.c ./src/cursus_functions/ft_strjoin.c ./src/cursus_functions/ft_strlen.c \
 ./src/cursus_functions/ft_strnstr.c ./src/cursus_functions/ft_substr.c

all : $(NAME)

$(NAME) : $(MANDATORY_SOURCES) $(SHARED_SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -o $(NAME) $(MANDATORY_SOURCES) $(SHARED_SOURCES)

bonus : $(BONUS_SOURCES) $(SHARED_SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -o $(NAME) $(BONUS_SOURCES) $(SHARED_SOURCES)

clean :
	rm -f $(NAME)

fclean :
	rm -f $(NAME)

re : fclean all

.PHONY : fclean re clean all bonus