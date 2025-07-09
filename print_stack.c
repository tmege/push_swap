#include "push_swap.h"

void    print_stack(t_stack *stack, char name)
{
    t_node *cur;
    int     i;

    if (!stack || !stack->head)
    {
        ft_printf("Stack %c is empty.\n", name);
        return;
    }
    cur = stack->head;
    ft_printf("Stack %c (%d elements): ", name, stack->size);
    i = 0;
    while (i < stack->size)
    {
        ft_printf("%d ", cur->value);
        cur = cur->next;
        i++;
    }
    ft_printf("\n");
}

