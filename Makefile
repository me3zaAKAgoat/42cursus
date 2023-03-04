CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf

HEADERS = ./includes/get_next_line.h ./includes/fdf.h

SOURCES = ./src/ft_split.c ./src/get_next_line/get_next_line.c ./src/get_next_line/get_next_line_utils.c ./src/perspective.c\
		./src/menu.c ./src/ft_dtoa.c ./src/pixel_logic.c ./src/ft_substr.c ./src/ft_itoa.c ./src/miscellaneous.c\
		./src/perspective_2.c ./src/map.c ./src/event_handlers.c ./src/event_handlers2.c ./src/ft_atoi_base.c ./src/main.c

OBJECTS = $(SOURCES:.c=.o)

LDLIBRARIES = -Imlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LDLIBRARIES)

bonus : $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean :
	rm -f $(OBJECTS) $(NAME)

re : fclean all

.PHONY : fclean re clean all bonus