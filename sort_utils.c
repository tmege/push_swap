#include "push_swap.h"

// Renvoie 1 si triée, 0 sinon
int	is_sorted(t_stack *a)
{
	int	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i].value > a->arr[i + 1].value)
			return (0);
		i++;
	}
	return (1);
}

int	min_pos(t_stack *a)
{
	int	min = a->arr[0].index;
	int	pos = 0;
	int	i = 1;
	while (i < a->size)
	{
		if (a->arr[i].index < min)
		{
			min = a->arr[i].index;
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	min_to_top(t_stack *a, t_ops *ops)
{
	int	pos = min_pos(a);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			rotate(a, ops, "ra\n");
	}
	else
	{
		while (pos++ < a->size)
			revrotate(a, ops, "rra\n");
	}
}

