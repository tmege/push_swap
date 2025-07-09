#include "push_swap.h"

// Crée un nouveau node isolé
t_node  *new_node(int value)
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->index = -1;
    node->next = node;
    node->prev = node;
    return (node);
}

// Ajoute à la fin de la stack circulaire
void    stack_add_back(t_stack *stack, t_node *new)
{
    if (!stack->head)
    {
        stack->head = new;
    }
    else
    {
        t_node *tail = stack->head->prev;
        tail->next = new;
        new->prev = tail;
        new->next = stack->head;
        stack->head->prev = new;
    }
    stack->size++;
}

// Ajoute en tête (top)
void    stack_add_top(t_stack *stack, t_node *new)
{
    stack_add_back(stack, new);
    stack->head = new;
}

// Libère toute la stack
void    free_stack(t_stack *stack)
{
    t_node  *tmp;
    t_node  *next;
    int     i;

    if (!stack || !stack->head)
        return;
    tmp = stack->head;
    i = 0;
    while (i < stack->size)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
        i++;
    }
    stack->head = NULL;
    stack->size = 0;
}

