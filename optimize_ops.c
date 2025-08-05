/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:06:26 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 19:15:19 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fusion(char *a, char *b, char **out)
{
	if ((!ft_strncmp(a, "sa\n", 4) && !ft_strncmp(b, "sb\n", 4))
		|| (!ft_strncmp(a, "sb\n", 4) && !ft_strncmp(b, "sa\n", 4)))
		*out = "ss\n";
	else if ((!ft_strncmp(a, "ra\n", 4) && !ft_strncmp(b, "rb\n", 4))
		|| (!ft_strncmp(a, "rb\n", 4) && !ft_strncmp(b, "ra\n", 4)))
		*out = "rr\n";
	else if ((!ft_strncmp(a, "rra\n", 4) && !ft_strncmp(b, "rrb\n", 4))
		|| (!ft_strncmp(a, "rrb\n", 4) && !ft_strncmp(b, "rra\n", 4)))
		*out = "rrr\n";
	else
		return (0);
	return (1);
}

static int	neutral(char *a, char *b)
{
	if ((!ft_strncmp(a, "sa\n", 4) && !ft_strncmp(b, "sa\n", 4))
		|| (!ft_strncmp(a, "sb\n", 4) && !ft_strncmp(b, "sb\n", 4))
		|| (!ft_strncmp(a, "ss\n", 4) && !ft_strncmp(b, "ss\n", 4))
		|| (!ft_strncmp(a, "ra\n", 4) && !ft_strncmp(b, "rra\n", 4))
		|| (!ft_strncmp(a, "rra\n", 4) && !ft_strncmp(b, "ra\n", 4))
		|| (!ft_strncmp(a, "rb\n", 4) && !ft_strncmp(b, "rrb\n", 4))
		|| (!ft_strncmp(a, "rrb\n", 4) && !ft_strncmp(b, "rb\n", 4))
		|| (!ft_strncmp(a, "rr\n", 4) && !ft_strncmp(b, "rrr\n", 4))
		|| (!ft_strncmp(a, "rrr\n", 4) && !ft_strncmp(b, "rr\n", 4))
		|| (!ft_strncmp(a, "pa\n", 4) && !ft_strncmp(b, "pb\n", 4))
		|| (!ft_strncmp(a, "pb\n", 4) && !ft_strncmp(b, "pa\n", 4)))
		return (1);
	return (0);
}

static void	shift_ops(t_ops *ops, int start, int shift)
{
	int	j;

	j = start;
	while (j < ops->size - shift)
	{
		ops->tab[j] = ops->tab[j + shift];
		j++;
	}
	ops->size -= shift;
}

static int	try_optimize_pair(t_ops *ops, int i)
{
	char	*fusion_op;

	if (fusion(ops->tab[i], ops->tab[i + 1], &fusion_op))
	{
		free(ops->tab[i]);
		free(ops->tab[i + 1]);
		ops->tab[i] = ft_strdup(fusion_op);
		shift_ops(ops, i + 1, 1);
		return (1);
	}
	else if (neutral(ops->tab[i], ops->tab[i + 1]))
	{
		free(ops->tab[i]);
		free(ops->tab[i + 1]);
		shift_ops(ops, i, 2);
		return (1);
	}
	return (0);
}

void	optimize_ops(t_ops *ops)
{
	int	i;

	i = 0;
	while (i < ops->size - 1)
	{
		if (try_optimize_pair(ops, i))
		{
			if (i > 0)
				i--;
			continue ;
		}
		i++;
	}
}
