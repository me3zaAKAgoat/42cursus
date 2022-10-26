CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

implementations = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_itoa.o\
 ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o\
 ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_strmapi.o\
 ft_memcmp.o ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_split.o\
 ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o\
 ft_strnstr.o ft_strtrim.o

all : $(NAME)

$(NAME) : $(implementations) libft.h
	ar -rsc $(NAME) $(implementations)

clean :
	rm *.o

fclean :
	rm *.a *.o

re : fclean all

.PHONY : fclean re clean all