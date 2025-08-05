/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:22:14 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 18:23:23 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Compare int, croissant (pour qsort)
int	cmp_int(const void *a, const void *b)
{
	int	ia;
	int	ib;

	ia = *(const int *)a;
	ib = *(const int *)b;
	return (ia - ib);
}

static int	*copy_values(t_stack *a)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = malloc(sizeof(int) * a->size);
	if (!tmp)
		error_exit();
	while (i < a->size)
	{
		tmp[i] = a->arr[i].value;
		i++;
	}
	return (tmp);
}

static void	assign_indices(t_stack *a, int *sorted)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->arr[i].value == sorted[j])
			{
				a->arr[i].index = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_stack *a)
{
	int	*tmp;

	tmp = copy_values(a);
	bubble_sort(tmp, a->size);
	assign_indices(a, tmp);
	free(tmp);
}
