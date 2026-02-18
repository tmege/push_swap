/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:36:33 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 18:36:33 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_both_rotate(t_stack *a, t_stack *b, t_ops *ops, t_cost *cost)
{
	while (cost->cost_a > 0 && cost->cost_b > 0)
	{
		rotate(a, NULL, NULL);
		rotate(b, NULL, NULL);
		add_op(ops, "rr\n");
		cost->cost_a--;
		cost->cost_b--;
	}
}

static void	do_both_revrotate(t_stack *a, t_stack *b, t_ops *ops, t_cost *cost)
{
	while (cost->cost_a < 0 && cost->cost_b < 0)
	{
		revrotate(a, NULL, NULL);
		revrotate(b, NULL, NULL);
		add_op(ops, "rrr\n");
		cost->cost_a++;
		cost->cost_b++;
	}
}

static void	do_remaining_a(t_stack *a, t_ops *ops, int cost_a)
{
	while (cost_a > 0)
	{
		rotate(a, ops, "ra\n");
		cost_a--;
	}
	while (cost_a < 0)
	{
		revrotate(a, ops, "rra\n");
		cost_a++;
	}
}

static void	do_remaining_b(t_stack *b, t_ops *ops, int cost_b)
{
	while (cost_b > 0)
	{
		rotate(b, ops, "rb\n");
		cost_b--;
	}
	while (cost_b < 0)
	{
		revrotate(b, ops, "rrb\n");
		cost_b++;
	}
}

void	execute_move(t_stack *a, t_stack *b, t_ops *ops, t_cost cost)
{
	if (cost.cost_a >= 0 && cost.cost_b >= 0)
		do_both_rotate(a, b, ops, &cost);
	else if (cost.cost_a <= 0 && cost.cost_b <= 0)
		do_both_revrotate(a, b, ops, &cost);
	do_remaining_a(a, ops, cost.cost_a);
	do_remaining_b(b, ops, cost.cost_b);
	push(a, b, ops, "pb\n");
}
