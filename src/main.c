/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:16:19 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 19:17:19 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
	a->arr = NULL;
	b->arr = NULL;
	a->size = 0;
	b->size = 0;
	a->capacity = 0;
	b->capacity = 0;
	parse_args(argc, argv, a);
	b->arr = malloc(sizeof(t_elem) * a->capacity);
	if (!b->arr)
		error_exit();
	b->capacity = a->capacity;
}

static void	run_sort(t_stack *a, t_stack *b)
{
	t_ops	ops;

	index_stack(a);
	init_ops(&ops);
	if (!is_sorted(a))
	{
		if (a->size <= 5)
			sort_small_stack(a, b, &ops);
		else
			turk_sort(a, b, &ops);
		optimize_ops(&ops);
		print_ops(&ops);
	}
	free_ops(&ops);
}

static void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init_stacks(argc, argv, &a, &b);
	run_sort(&a, &b);
	free_all(&a, &b);
	return (0);
}
