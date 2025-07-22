/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:54:53 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 18:57:48 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s, t_ops *ops, char *op)
{
	t_elem	tmp;

	if (s->size < 2)
		return ;
	tmp = s->arr[0];
	s->arr[0] = s->arr[1];
	s->arr[1] = tmp;
	if (op && ops)
		add_op(ops, op);
}

void	push(t_stack *src, t_stack *dst, t_ops *ops, char *op)
{
	int	i;

	if (src->size < 1)
		return ;
	i = dst->size;
	while (i > 0)
	{
		dst->arr[i] = dst->arr[i - 1];
		i--;
	}
	dst->arr[0] = src->arr[0];
	dst->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->arr[i] = src->arr[i + 1];
		i++;
	}
	src->size--;
	if (op && ops)
		add_op(ops, op);
}

void	rotate(t_stack *s, t_ops *ops, char *op)
{
	t_elem	tmp;
	int		i;

	if (s->size < 2)
		return ;
	tmp = s->arr[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	s->arr[s->size - 1] = tmp;
	if (op && ops)
		add_op(ops, op);
}

void	revrotate(t_stack *s, t_ops *ops, char *op)
{
	t_elem	tmp;
	int		i;

	if (s->size < 2)
		return ;
	tmp = s->arr[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	s->arr[0] = tmp;
	if (op && ops)
		add_op(ops, op);
}
