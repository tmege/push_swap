NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src
INC_DIR		= inc
OBJ_DIR		= obj

SRCS		= main.c indexing.c parsing.c parsing_utils.c turk_sort.c turk_cost.c \
			  turk_exec.c sort_small.c sort_utils.c ops.c ops_utils.c optimize_ops.c
CHECKER_SRCS = checker.c indexing.c parsing.c parsing_utils.c sort_utils.c \
			  sort_small.c ops.c ops_utils.c

SRC			= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
CHECKER_SRC	= $(addprefix $(SRC_DIR)/, $(CHECKER_SRCS))
CHECKER_OBJ	= $(addprefix $(OBJ_DIR)/, $(CHECKER_SRCS:.c=.o))

LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I$(INC_DIR) -I. -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME) $(INCLUDES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h libft/includes/*.h libft/Makefile libft/srcs/ft_printf/Makefile Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

bonus: checker

checker: $(CHECKER_OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIBFT_A) -o checker $(INCLUDES)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) checker
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
