/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:49:14 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 18:53:45 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct s_elem
{
	int	value;
	int	index;
}	t_elem;

typedef struct s_stack
{
	t_elem	*arr;
	int		size;
	int		capacity;
}	t_stack;

typedef struct s_ops
{
	char	**tab;
	int		size;
	int		cap;
}	t_ops;

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	total;
}	t_cost;

// ops_utils.c
void	init_ops(t_ops *ops);
void	add_op(t_ops *ops, char *op);
void	print_ops(t_ops *ops);
void	free_ops(t_ops *ops);

// optimize_ops.c
void	optimize_ops(t_ops *ops);

// parsing.c
void	parse_args(int argc, char **argv, t_stack *a);

// parsing_utils.c
void	error_exit(void);
int		is_number(char *str);
int		is_duplicate(t_stack *a, int value);
void	free_stack(t_stack *stack);
long	ft_atol(const char *str);

// indexing.c
void	index_stack(t_stack *a);

// ops.c
void	swap(t_stack *s, t_ops *ops, char *op);
void	push(t_stack *src, t_stack *dst, t_ops *ops, char *op);
void	rotate(t_stack *s, t_ops *ops, char *op);
void	revrotate(t_stack *s, t_ops *ops, char *op);

// sort_small.c
void	sort_3(t_stack *a, t_ops *ops);
void	sort_small_stack(t_stack *a, t_stack *b, t_ops *ops);

// sort_utils.c
int		is_sorted(t_stack *a);
int		min_pos(t_stack *a);
void	min_to_top(t_stack *a, t_ops *ops);
void	rotate_to_top_a(t_stack *a, t_ops *ops, int pos);
void	push_max_to_top_b(t_stack *b, t_ops *ops);

// turk_sort.c
void	turk_sort(t_stack *a, t_stack *b, t_ops *ops);

// turk_cost.c
t_cost	calc_cost(t_stack *a, t_stack *b, int i);

// turk_exec.c
void	execute_move(t_stack *a, t_stack *b, t_ops *ops, t_cost cost);

#endif
