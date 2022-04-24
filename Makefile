NAME = so_long

CC = gcc
CFLAGS = -Werror -Wextra -fsanitize=address -g3
CFLAG2 = -ldl -lmlx -lm -lbsd -lX11 -lXext
LINKMIN = -Lminilibx-linux/ -lmlx -Iminilibx-linux
RM = rm -f
OBJ = $(FILES:.c=.o)

FILES = main.c\
		Parsing/parser.c\
		gnl/get_next_line_utils.c\
		gnl/gnl.c




$(NAME): $(OBJ)
		$(CC) $(OBJ) $(CFLAG2) $(LINKMIN)  $(CFLAGS) -o $(NAME)


all: $(NAME)


clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	rm -f $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
