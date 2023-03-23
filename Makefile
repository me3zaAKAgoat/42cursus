CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = FdF
BONUS_NAME = FdF_BONUS

HEADERS = ./includes/get_next_line.h ./includes/fdf.h

SHARED_SOURCES = ./src/ft_split.c ./src/get_next_line/get_next_line.c ./src/get_next_line/get_next_line_utils.c ./src/perspective.c\
		./src/menu.c ./src/ft_dtoa.c ./src/pixel_logic.c ./src/ft_substr.c ./src/ft_itoa.c ./src/miscellaneous.c\
		./src/perspective_2.c ./src/map.c ./src/event_handlers2.c ./src/ft_atoi_base.c ./src/miscellaneous_2.c ./src/gradient.c

MANDATORY_SOURCES = ./src/event_handlers.c ./src/mandatory.c

BONUS_SOURCES = ./src/event_handlers_bonus.c ./src/bonus.c

SHARED_OBJECTS = $(SHARED_SOURCES:.c=.o)

MANDATORY_OBJECTS = $(MANDATORY_SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

LDLIBRARIES = -Imlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(SHARED_OBJECTS) $(MANDATORY_OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(SHARED_OBJECTS) $(MANDATORY_OBJECTS) $(LDLIBRARIES)

bonus : $(SHARED_OBJECTS) $(BONUS_OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(SHARED_OBJECTS) $(BONUS_OBJECTS) $(LDLIBRARIES)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	rm -f $(MANDATORY_OBJECTS) $(BONUS_OBJECTS) $(SHARED_OBJECTS)

fclean :
	rm -f $(MANDATORY_OBJECTS) $(BONUS_OBJECTS) $(SHARED_OBJECTS) $(BONUS_NAME) $(NAME)

re : fclean all

.PHONY : fclean re clean all bonus