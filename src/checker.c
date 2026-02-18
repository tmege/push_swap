/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:36:33 by tmege             #+#    #+#             */
/*   Updated: 2025/07/22 18:36:33 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_line(char *buf, int max)
{
	int		i;
	char	c;
	int		ret;

	i = 0;
	while (i < max - 1)
	{
		ret = read(0, &c, 1);
		if (ret <= 0)
			break ;
		buf[i++] = c;
		if (c == '\n')
			break ;
	}
	buf[i] = '\0';
	return (i);
}

static void	exec_op(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		swap(a, NULL, NULL);
	else if (!ft_strncmp(line, "sb\n", 4))
		swap(b, NULL, NULL);
	else if (!ft_strncmp(line, "ss\n", 4))
	{
		swap(a, NULL, NULL);
		swap(b, NULL, NULL);
	}
	else if (!ft_strncmp(line, "pa\n", 4))
		push(b, a, NULL, NULL);
	else if (!ft_strncmp(line, "pb\n", 4))
		push(a, b, NULL, NULL);
	else if (!ft_strncmp(line, "ra\n", 4))
		rotate(a, NULL, NULL);
	else if (!ft_strncmp(line, "rb\n", 4))
		rotate(b, NULL, NULL);
	else if (!ft_strncmp(line, "rr\n", 4))
	{
		rotate(a, NULL, NULL);
		rotate(b, NULL, NULL);
	}
	else
		error_exit();
}

static void	exec_rev_ops(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "rra\n", 5))
		revrotate(a, NULL, NULL);
	else if (!ft_strncmp(line, "rrb\n", 5))
		revrotate(b, NULL, NULL);
	else if (!ft_strncmp(line, "rrr\n", 5))
	{
		revrotate(a, NULL, NULL);
		revrotate(b, NULL, NULL);
	}
	else
		exec_op(a, b, line);
}

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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	line[16];

	if (argc < 2)
		return (0);
	init_stacks(argc, argv, &a, &b);
	while (read_line(line, 16) > 0)
		exec_rev_ops(&a, &b, line);
	if (is_sorted(&a) && b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
