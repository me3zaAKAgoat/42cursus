CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

IMPLEMENTATIONS = ft_printf.o ft_printf_utils.o


all : $(NAME)

$(NAME) : $(IMPLEMENTATIONS)
	ar -rsc $(NAME) $(IMPLEMENTATIONS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f *.o

fclean :
	rm -f *.a *.o

re : fclean all

.PHONY : fclean re clean all 