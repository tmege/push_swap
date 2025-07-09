#include "push_swap.h"

// ========== Cas 2 éléments ==========
void    sort_2(t_stack *a)
{
    if (a->head->value > a->head->next->value)
        sa(a);
}

// ========== Cas 3 éléments ==========
void    sort_3(t_stack *a)
{
    int x = a->head->value;
    int y = a->head->next->value;
    int z = a->head->next->next->value;

    if (x < y && y < z)
        return;
    if (x > y && y < z && x < z)
        sa(a);
    else if (x > y && y > z)
    {
        sa(a);
        rra(a);
    }
    else if (x > y && y < z && x > z)
        ra(a);
    else if (x < y && y > z && x < z)
    {
        sa(a);
        ra(a);
    }
    else if (x < y && y > z && x > z)
        rra(a);
}

// ========== Chercher la position du minimum ==========
int     min_pos(t_stack *a)
{
    t_node  *cur = a->head;
    int     min = cur->value;
    int     pos = 0, i = 0;

    for (i = 0; i < a->size; i++)
    {
        if (cur->value < min)
        {
            min = cur->value;
            pos = i;
        }
        cur = cur->next;
    }
    return (pos);
}

// ========== Mettre le minimum en tête ==========
void    min_to_top(t_stack *a)
{
    int pos = min_pos(a);

    if (pos <= a->size / 2)
        while (pos-- > 0)
            ra(a);
    else
        while (pos++ < a->size)
            rra(a);
}

// ========== Cas 4 éléments ==========
void    sort_4(t_stack *a, t_stack *b)
{
    min_to_top(a);
    pb(a, b);
    sort_3(a);
    pa(a, b);
}

// ========== Cas 5 éléments ==========
void    sort_5(t_stack *a, t_stack *b)
{
    min_to_top(a);
    pb(a, b);
    min_to_top(a);
    pb(a, b);
    sort_3(a);
    pa(a, b);
    pa(a, b);
}

// ========== Enveloppe unique ==========
void    sort_small_stack(t_stack *a, t_stack *b)
{
    if (a->size == 2)
        sort_2(a);
    else if (a->size == 3)
        sort_3(a);
    else if (a->size == 4)
        sort_4(a, b);
    else if (a->size == 5)
        sort_5(a, b);
}

