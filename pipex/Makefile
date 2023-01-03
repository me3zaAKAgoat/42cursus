CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SOURCE_FILES = main.c ./util/free.c ./util/ft_split.c ./util/get_cmd.c \
 ./util/get_paths.c ./customlib/ft_strjoin.c ./customlib/ft_strlen.c \
 ./customlib/ft_strnstr.c ./customlib/ft_substr.c


all : $(NAME)

$(NAME) : $(SOURCE_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCE_FILES)

# bonus : $(SOURCE_FILES)
# 	ar -rsc $(NAME) $(BONUS_IMPLEMENTATIONS)

clean :
	rm -f $(NAME)

fclean :
	rm -f $(NAME)

re : fclean all

.PHONY : fclean re clean all bonus