/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:36:33 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 18:36:33 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_target_pos_a(t_stack *a, int idx)
{
	int	i;
	int	target;
	int	best;

	target = min_pos(a);
	best = -1;
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i].index > idx)
		{
			if (best == -1 || a->arr[i].index < best)
			{
				best = a->arr[i].index;
				target = i;
			}
		}
		i++;
	}
	return (target);
}

static int	find_cheapest_idx(t_stack *a, t_stack *b)
{
	int		i;
	int		best;
	t_cost	cost;
	t_cost	best_cost;

	best = 0;
	best_cost = calc_cost(a, b, 0);
	i = 1;
	while (i < a->size)
	{
		cost = calc_cost(a, b, i);
		if (cost.total < best_cost.total)
		{
			best_cost = cost;
			best = i;
		}
		i++;
	}
	return (best);
}

static void	turk_push_all_to_b(t_stack *a, t_stack *b, t_ops *ops)
{
	int		idx;
	t_cost	cost;

	while (a->size > 3)
	{
		idx = find_cheapest_idx(a, b);
		cost = calc_cost(a, b, idx);
		execute_move(a, b, ops, cost);
	}
}

static void	turk_push_all_to_a(t_stack *a, t_stack *b, t_ops *ops)
{
	int	target;

	while (b->size)
	{
		push_max_to_top_b(b, ops);
		target = find_target_pos_a(a, b->arr[0].index);
		rotate_to_top_a(a, ops, target);
		push(b, a, ops, "pa\n");
	}
	min_to_top(a, ops);
}

void	turk_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	push(a, b, ops, "pb\n");
	push(a, b, ops, "pb\n");
	turk_push_all_to_b(a, b, ops);
	sort_3(a, ops);
	turk_push_all_to_a(a, b, ops);
}
