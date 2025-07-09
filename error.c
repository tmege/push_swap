#include "push_swap.h"

// Affiche "Error" sur stderr, libère les stacks et quitte le programme
void error_exit(t_stack *a, t_stack *b)
{
    write(2, "Error\n", 6);
    free_stack(a);
    free_stack(b);
    exit(1);
}

