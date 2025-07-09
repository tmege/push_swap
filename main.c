#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a = {NULL, 0};
    t_stack b = {NULL, 0};

    if (argc < 2)
        return (0);
    parse_args(argc, argv, &a);
    if (stack_is_sorted(&a))
    {
        free_stack(&a);
        return (0);
    }
    assign_indexes(&a);
    if (a.size <= 5)
        sort_small_stack(&a, &b);
    else
        sort_big_stack(&a, &b);
//	print_stack(&a, 'A');
//	print_stack(&b, 'B');
    free_stack(&a);
    free_stack(&b);
    return (0);
}

