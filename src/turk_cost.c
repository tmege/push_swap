/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:36:33 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 18:36:33 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_in_b(t_stack *b)
{
	int	i;
	int	pos;
	int	max;

	pos = 0;
	max = b->arr[0].index;
	i = 1;
	while (i < b->size)
	{
		if (b->arr[i].index > max)
		{
			max = b->arr[i].index;
			pos = i;
		}
		i++;
	}
	return (pos);
}

static int	find_target_pos_b(t_stack *b, int idx)
{
	int	i;
	int	next;

	if (b->size == 0)
		return (0);
	i = 0;
	while (i < b->size)
	{
		next = (i + 1) % b->size;
		if (b->arr[i].index > idx && b->arr[next].index < idx)
			return (next);
		i++;
	}
	return (max_in_b(b));
}

static int	cost_for_pos(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (-(size - pos));
}

static int	compute_total(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	if (cost_a < 0)
		abs_a = -cost_a;
	else
		abs_a = cost_a;
	if (cost_b < 0)
		abs_b = -cost_b;
	else
		abs_b = cost_b;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

t_cost	calc_cost(t_stack *a, t_stack *b, int i)
{
	t_cost	cost;
	int		target;

	cost.cost_a = cost_for_pos(i, a->size);
	target = find_target_pos_b(b, a->arr[i].index);
	cost.cost_b = cost_for_pos(target, b->size);
	cost.total = compute_total(cost.cost_a, cost.cost_b);
	return (cost);
}
