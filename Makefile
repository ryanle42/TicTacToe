NAME = tictactoe

HEADERS = ./includes/

all: $(NAME)

$(NAME):
	gcc ./srcs/*.c -o $(NAME) -I $(HEADERS)

clean:
	rm tictactoe

re: clean
	make $(NAME)
