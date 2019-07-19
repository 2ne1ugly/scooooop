CC=gcc
CFLAGS=-Werror -Wextra -Wall -g -Iinclude
LIB=-Llib/glew-2.1.0/lib -Llib/glfw-3.3/src -lglfw3 ./lib/glew-2.1.0/lib/libGLEW.a
FRAMEWORK=-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
SRC=$(shell find sources -type f -name '*.c')
NAME=scop
OBJ=$(SRC:sources/%.c=objects/%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIB) $(FRAMEWORK) -o $(NAME) $(OBJ)
	
	@echo "$(NAME) build complete!"

all: $(NAME)

$(OBJ): objects/%.o : sources/%.c
	@mkdir -p $(shell dirname $@) 
	$(CC) $(CFLAGS) -o $@ -c $^
clean:
	@rm -rf objects/

fclean: clean
	@rm -f $(NAME)

re: fclean all
