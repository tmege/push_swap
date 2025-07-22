/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:36:33 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 18:41:37 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Ramène le plus grand index de B en haut (avec ops)
void	push_max_to_top_b(t_stack *b, t_ops *ops)
{
	int	max;
	int	pos;
	int	i;

	max = b->arr[0].index;
	pos = 0;
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
	if (pos == 1)
		swap(b, ops, "sb\n");
	else if (pos <= b->size / 2)
		while (pos-- > 0)
			rotate(b, ops, "rb\n");
	else
		while (pos++ < b->size)
			revrotate(b, ops, "rrb\n");
}

int	pick_chunk_size(int size)
{
	if (size >= 500)
		return (46);
	else if (size >= 100)
		return (18);
	else if (size > 10)
		return (size / 5 + 4);
	else
		return (2);
}

// Algo principal : tri par chunk (avec ops)
void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int	size;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	pushed;
	int	i;
	int	len;
	int	idx;

	size = a->size;
	chunk_size = pick_chunk_size(size);
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	pushed = 0;
	while (pushed < size)
	{
		i = 0;
		len = a->size;
		while (i < len)
		{
			idx = a->arr[0].index;
			if (idx >= chunk_min && idx <= chunk_max)
			{
				push(a, b, ops, "pb\n");
				pushed++;
				if (idx > chunk_min + (chunk_size / 2) && b->size > 1)
					rotate(b, ops, "rb\n");
			}
			else
				rotate(a, ops, "ra\n");
			i++;
		}
		chunk_min += chunk_size;
		chunk_max += chunk_size;
		if (chunk_max >= size)
			chunk_max = size - 1;
	}
	while (b->size)
	{
		push_max_to_top_b(b, ops);
		push(b, a, ops, "pa\n");
	}
}
