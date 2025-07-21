#include "push_swap.h"

// === Gestion du buffer d'instructions ===

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
	if (ops->size >= ops->cap)
	{
		char **new = malloc(sizeof(char*) * (ops->cap * 2));
		int i = 0;
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
	int i = 0;
	while (i < ops->size)
	{
		write(1, ops->tab[i], ft_strlen(ops->tab[i]));
		i++;
	}
}

void	free_ops(t_ops *ops)
{
	int i = 0;
	while (i < ops->size)
		free(ops->tab[i++]);
	free(ops->tab);
}

