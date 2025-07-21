#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_ops	ops;  // Nouveau : buffer des opérations

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

	init_ops(&ops); // Initialise le buffer d’instructions

	if (!is_sorted(&a))
	{
		if (a.size <= 5)
			sort_small_stack(&a, &b, &ops); // Passe le buffer
		else
			chunk_sort(&a, &b, &ops);       // Passe le buffer
		optimize_ops(&ops);                 // Optimise le buffer
		optimize_ops(&ops);
		print_ops(&ops);                    // Affiche les instructions finales
	}

	free_ops(&ops);    // Libère le buffer d’instructions
	free_stack(&a);
	free_stack(&b);
	return (0);
}
