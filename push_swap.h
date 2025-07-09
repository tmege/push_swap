#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/includes/libft.h"

// === STRUCTURES ===

typedef struct s_node
{
    int             value;
    int             index;   // index trié
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
    t_node  *head;
    int     size;
}   t_stack;

// === PARSING ===
void    parse_args(int argc, char **argv, t_stack *a);

// === GESTION STACK ===
t_node  *new_node(int value);
void    stack_add_back(t_stack *stack, t_node *new);
void    stack_add_top(t_stack *stack, t_node *new);
void    free_stack(t_stack *stack);

// === ERREURS ===
void    error_exit(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack, char name);

// === INDEXATION ===
void    assign_indexes(t_stack *stack);

// === OPERATIONS (push_swap) ===
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

// === TRI PETITES STACKS ===
void    sort_small_stack(t_stack *a, t_stack *b);

// === TRI BIG (CHUNKS/PIVOT) ===
void    sort_big_stack(t_stack *a, t_stack *b);

// === UTILS ===
int     stack_is_sorted(t_stack *a);
int     is_number(char *str);
int     is_duplicate(t_stack *stack, int value);

#endif

