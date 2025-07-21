#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct s_elem
{
    int value;
    int index;
}   t_elem;

typedef struct s_stack
{
    t_elem *arr;
    int size;
    int capacity;
}   t_stack;

typedef struct s_ops
{
    char    **tab;
    int     size;
    int     cap;
}   t_ops;

void	init_ops(t_ops *ops);
void	add_op(t_ops *ops, char *op);
void	optimize_ops(t_ops *ops);
void	print_ops(t_ops *ops);
void	free_ops(t_ops *ops);

// parsing.c
void    error_exit(void);
int     is_number(char *str);
void    free_stack(t_stack *stack);
long	ft_atol(const char *str);
void    parse_args(int argc, char **argv, t_stack *a);

// indexing.c
void    index_stack(t_stack *a);

// operations.c
void    swap(t_stack *s, t_ops *ops, char *op);
void    push(t_stack *src, t_stack *dst, t_ops *ops, char *op);
void    rotate(t_stack *s, t_ops *ops, char *op);
void    revrotate(t_stack *s, t_ops *ops, char *op);

// sort.c
int     is_sorted(t_stack *a);
void	sort_2(t_stack *a, t_ops *ops);
void	sort_3(t_stack *a, t_ops *ops);
int	min_pos(t_stack *a);
void	min_to_top(t_stack *a, t_ops *ops);
void	sort_4(t_stack *a, t_stack *b, t_ops *ops);
void	sort_5(t_stack *a, t_stack *b, t_ops *ops);
void    sort_small_stack(t_stack *a, t_stack *b, t_ops *ops);
void	push_max_to_top_b(t_stack *b, t_ops *ops);
int	pick_chunk_size(int size);
void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops);

#endif


