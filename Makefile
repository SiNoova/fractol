NAME = fractol

SRC_fractol = mandatory/helpers.c mandatory/helpers2.c mandatory/helpers3.c mandatory/fractol.c 

HEADER = mandatory/fractol.h

CC = cc
FLAGS = -Wall -Wextra -Werror 
OBJ_fractol = $(SRC_fractol:.c=.o)


all: $(NAME) 

$(NAME): $(OBJ_fractol)
	$(CC) $(FLAGS) -O3 -lmlx -framework OpenGL -framework AppKit $^ -o $@

mandatory/%.o : mandatory/%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_fractol) 

fclean: clean
	rm -f $(NAME) 

re : fclean all

.PHONY: clean
