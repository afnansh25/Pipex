NAME = pipex

SRC = main.c ft_split.c str_utils.c path.c pipex.c execute.c validate.c clean.c error.c	

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Werror -Wextra

DEL = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	
clean: 
	$(DEL) $(OBJ)

fclean: clean
	$(DEL) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
