CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SOURCE_FILES =  ./src/util/children_core.c ./src/util/free.c ./src/util/ft_split.c ./src/util/get_cmd.c \
 ./src/util/get_paths.c ./src/customlib/ft_strjoin.c ./src/customlib/ft_strlen.c \
 ./src/customlib/ft_strnstr.c ./src/customlib/ft_substr.c

MANDATORY = ./src/mandatory.c

BONUS = ./src/bonus.c

HEADER = ./includes/pipex.h

all : $(NAME)

$(NAME) : $(MANDATORY) $(SOURCE_FILES) $(HEADER)
	$(CC) $(CFLAGS) -I./includes -o $(NAME) $(MANDATORY) $(SOURCE_FILES)

bonus : $(BONUS) $(SOURCE_FILES) $(HEADER)
	$(CC) $(CFLAGS) -I./includes -o $(NAME) $(BONUS) $(SOURCE_FILES)

clean :
	rm -f $(NAME)

fclean :
	rm -f $(NAME)

re : fclean all

.PHONY : fclean re clean all bonus