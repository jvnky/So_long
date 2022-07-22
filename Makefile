NAME = so_long

CC = gcc
CFLAGS = -Werror -Wall -Wextra
CFLAG2 = -ldl -lmlx -lm -lbsd -lX11 -lXext
LEAKS = -fsanitize=address -g3
LINKMIN = -Lminilibx-linux/ -lmlx -Iminilibx-linux
RM = rm -f
OBJ = $(FILES:.c=.o)

FILES = main.c\
		Parsing/parser.c\
		gnl/get_next_line_utils.c\
		gnl/gnl.c\
		graphic/render.c\
		graphic/Frame.c\
		Parsing/move.c\
		Parsing/itoa.c


$(NAME): $(OBJ)
		$(CC) $(OBJ) $(CFLAG2) $(LINKMIN) $(CFLAG) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	rm -f $(NAME)

re: clean all

leaks: $(OBJ)
	$(CC) $(OBJ) $(CFLAG2) $(LINKMIN) $(CFLAG) $(LEAKS) -o $(NAME)

.PHONY: bonus all clean fclean re leaks
