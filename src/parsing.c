/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:58:39 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 18:58:43 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(int argc, char **argv, t_stack *a)
{
	int		val;
	int		i;
	long	lval;

	a->capacity = argc - 1;
	a->arr = malloc(sizeof(t_elem) * a->capacity);
	if (!a->arr)
		error_exit();
	a->size = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_exit();
		val = ft_atoi(argv[i]);
		lval = ft_atol(argv[i]);
		if (lval > 2147483647L || lval < -2147483648L)
			error_exit();
		if (is_duplicate(a, val))
			error_exit();
		a->arr[a->size].value = val;
		a->arr[a->size].index = -1;
		a->size++;
		i++;
	}
}
