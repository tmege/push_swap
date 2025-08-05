NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c indexing.c parsing.c parsing_utils.c sort.c sort_small.c sort_utils.c operations.c ops.c optimize_ops.c
OBJ			= $(SRC:.c=.o)

LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I. -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME) $(INCLUDES)

%.o: %.c Makefile push_swap.h libft/includes/*.h libft/Makefile libft/srcs/ft_printf/Makefile
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

