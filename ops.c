/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:02:22 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 19:05:22 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ops(t_ops *ops)
{
	ops->cap = 1024;
	ops->size = 0;
	ops->tab = malloc(sizeof(char *) * ops->cap);
	if (!ops->tab)
		error_exit();
}

void	add_op(t_ops *ops, char *op)
{
	char	**new;
	int		i;

	if (ops->size >= ops->cap)
	{
		new = malloc(sizeof(char *) * (ops->cap * 2));
		i = 0;
		if (!new)
			error_exit();
		while (i < ops->size)
		{
			new[i] = ops->tab[i];
			i++;
		}
		free(ops->tab);
		ops->tab = new;
		ops->cap *= 2;
	}
	ops->tab[ops->size++] = ft_strdup(op);
}

void	print_ops(t_ops *ops)
{
	int	i;

	i = 0;
	while (i < ops->size)
	{
		write(1, ops->tab[i], ft_strlen(ops->tab[i]));
		i++;
	}
}

void	free_ops(t_ops *ops)
{
	int	i;

	i = 0;
	while (i < ops->size)
		free(ops->tab[i++]);
	free(ops->tab);
}
