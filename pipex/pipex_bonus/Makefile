NAME = pipex

SRC = main_bonus.c \
		init_bonus.c \
		fork_bonus.c \
		pipe_bonus.c \
		here_doc_bonus.c \
		cmd_utils_bonus.c \
		error_bonus.c \
		str_utils_bonus.c \
		get_next_line.c \
		ft_split.c \

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
