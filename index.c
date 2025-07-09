#include "push_swap.h"

// Trouve l'index trié de chaque node de la stack
void assign_indexes(t_stack *a)
{
    t_node *cur1 = a->head;
    t_node *cur2;
    int i, count;

    if (!a || a->size == 0)
        return;

    int size = a->size;
    for (i = 0; i < size; i++)
    {
        count = 0;
        cur2 = a->head;
        for (int j = 0; j < size; j++)
        {
            if (cur1->value > cur2->value)
                count++;
            cur2 = cur2->next;
        }
        cur1->index = count;
        cur1 = cur1->next;
    }
}

