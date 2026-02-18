/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:26:39 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 18:27:48 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_stack *a, t_ops *ops)
{
	if (a->arr[0].value > a->arr[1].value)
		swap(a, ops, "sa\n");
}

void	sort_3(t_stack *a, t_ops *ops)
{
	int	x;
	int	y;
	int	z;

	x = a->arr[0].value;
	y = a->arr[1].value;
	z = a->arr[2].value;
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		swap(a, ops, "sa\n");
	else if (x > y && y > z)
	{
		swap(a, ops, "sa\n");
		revrotate(a, ops, "rra\n");
	}
	else if (x > y && y < z && x > z)
		rotate(a, ops, "ra\n");
	else if (x < y && y > z && x < z)
	{
		swap(a, ops, "sa\n");
		rotate(a, ops, "ra\n");
	}
	else if (x < y && y > z && x > z)
		revrotate(a, ops, "rra\n");
}

static void	sort_4(t_stack *a, t_stack *b, t_ops *ops)
{
	min_to_top(a, ops);
	push(a, b, ops, "pb\n");
	sort_3(a, ops);
	push(b, a, ops, "pa\n");
}

static void	sort_5(t_stack *a, t_stack *b, t_ops *ops)
{
	min_to_top(a, ops);
	push(a, b, ops, "pb\n");
	min_to_top(a, ops);
	push(a, b, ops, "pb\n");
	sort_3(a, ops);
	push(b, a, ops, "pa\n");
	push(b, a, ops, "pa\n");
}

void	sort_small_stack(t_stack *a, t_stack *b, t_ops *ops)
{
	if (a->size == 2)
		sort_2(a, ops);
	else if (a->size == 3)
		sort_3(a, ops);
	else if (a->size == 4)
		sort_4(a, b, ops);
	else if (a->size == 5)
		sort_5(a, b, ops);
}
