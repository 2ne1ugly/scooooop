CC=clang
CFLAGS=-Werror -Wextra -Wall -g -I. -Imlx -Iincludes
LFLAGS=-L mlx/ -lmlx -L lib/ -framework OpenGL -framework AppKit
GLEW=lib/libGLEW.a lib/libGLEW.2.1.0.dylib
SRC=$(wildcard src/*)
NAME=scop
OBJ=$(SRC:src/%.c=%.o)
SHELL := /bin/bash

.PHONY: clean fclean all re norm norme debug test norman update libft

VPATH = src obj include

$(NAME): $(OBJ)
	@make -C mlx
	@$(CC) -o $(NAME) obj/* $(GLEW) $(LFLAGS)
	@echo "$(NAME) build complete!"

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o obj/$@ -c $<

clean:
	@make -C mlx clean
	@rm -rf obj/

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	norminette src/. includes/.

norme: norm

norman:
	-norminette * | grep -iv warning