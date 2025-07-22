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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_ops	ops;

	a.arr = NULL;
	b.arr = NULL;
	a.size = 0;
	b.size = 0;
	a.capacity = 0;
	b.capacity = 0;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	b.arr = malloc(sizeof(t_elem) * a.capacity);
	if (!b.arr)
		error_exit();
	b.size = 0;
	b.capacity = a.capacity;
	index_stack(&a);
	init_ops(&ops);
	if (!is_sorted(&a))
	{
		if (a.size <= 5)
			sort_small_stack(&a, &b, &ops);
		else
			chunk_sort(&a, &b, &ops);
		optimize_ops(&ops);
		optimize_ops(&ops);
		print_ops(&ops);
	}
	free_ops(&ops);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
