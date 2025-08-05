/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:36:33 by tmege             #+#    #+#             */
/*   Updated: 2025/08/05 17:17:37 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	push_chunk_elem(t_stack *a, t_stack *b, t_ops *ops, t_chunk chunk)
{
	int	i;
	int	len;
	int	idx;

	i = 0;
	len = a->size;
	while (i < len)
	{
		idx = a->arr[0].index;
		if (idx >= chunk.min && idx <= chunk.max)
		{
			push(a, b, ops, "pb\n");
			(*chunk.pushed)++;
			if (idx > chunk.min + (chunk.max - chunk.min) / 2 && b->size > 1)
				rotate(b, ops, "rb\n");
		}
		else
			rotate(a, ops, "ra\n");
		i++;
	}
}

static void	final_rebuild(t_stack *a, t_stack *b, t_ops *ops)
{
	while (b->size)
	{
		push_max_to_top_b(b, ops);
		push(b, a, ops, "pa\n");
	}
}

static void	process_chunks(t_stack *a, t_stack *b, t_ops *ops, t_chunk *chunk)
{
	while (*(chunk->pushed) < chunk->size)
	{
		push_chunk_elem(a, b, ops, *chunk);
		chunk->min += chunk->chunk_size;
		chunk->max += chunk->chunk_size;
		if (chunk->max >= chunk->size)
			chunk->max = chunk->size - 1;
	}
}

void	chunk_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int		pushed;
	t_chunk	chunk;

	pushed = 0;
	chunk.size = a->size;
	chunk.chunk_size = pick_chunk_size(chunk.size);
	chunk.min = 0;
	chunk.max = chunk.chunk_size - 1;
	chunk.pushed = &pushed;
	process_chunks(a, b, ops, &chunk);
	final_rebuild(a, b, ops);
}
