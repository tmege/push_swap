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

// Attribue à chaque valeur son rang dans la stack
void	index_stack(t_stack *a)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = malloc(sizeof(int) * a->size);
	if (!tmp)
		error_exit();
	i = 0;
	while (i < a->size)
	{
		tmp[i] = a->arr[i].value;
		i++;
	}
	qsort(tmp, a->size, sizeof(int), cmp_int);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->arr[i].value == tmp[j])
			{
				a->arr[i].index = j;
				break;
			}
			j++;
		}
		i++;
	}
	free(tmp);
}

