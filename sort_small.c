#include "push_swap.h"

void	sort_2(t_stack *a, t_ops *ops)
{
	if (a->arr[0].value > a->arr[1].value)
		swap(a, ops, "sa\n");
}

void	sort_3(t_stack *a, t_ops *ops)
{
	int	x = a->arr[0].value;
	int	y = a->arr[1].value;
	int	z = a->arr[2].value;

	if (x < y && y < z)
		return;
	if (x > y && y < z && x < z)
		swap(a, ops, "sa\n");
	else if (x > y && y > z)
	{
		swap(a, ops, "sa\n");
		revrotate(a, ops, "rra\n");
	}
	else if (x > y && y < z && x > z)
		rotate(a, ops, "ra\n");
	else if (x < y && y > z && x < z)
	{
		swap(a, ops, "sa\n");
		rotate(a, ops, "ra\n");
	}
	else if (x < y && y > z && x > z)
		revrotate(a, ops, "rra\n");
}

void	sort_4(t_stack *a, t_stack *b, t_ops *ops)
{
	min_to_top(a, ops);
	push(a, b, ops, "pb\n");
	sort_3(a, ops);
	push(b, a, ops, "pa\n");
}

void	sort_5(t_stack *a, t_stack *b, t_ops *ops)
{
	min_to_top(a, ops);
	push(a, b, ops, "pb\n");
	min_to_top(a, ops);
	push(a, b, ops, "pb\n");
	sort_3(a, ops);
	push(b, a, ops, "pa\n");
	push(b, a, ops, "pa\n");
}
