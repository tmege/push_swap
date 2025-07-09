#include "push_swap.h"

// ----- ACTIONS GENERIQUES -----

void    swap(t_stack *s)
{
    t_node *f, *s2;
    int tmp_val, tmp_idx;

    if (!s || s->size < 2)
        return;
    f = s->head;
    s2 = s->head->next;
    tmp_val = f->value;
    tmp_idx = f->index;
    f->value = s2->value;
    f->index = s2->index;
    s2->value = tmp_val;
    s2->index = tmp_idx;
}

void    push(t_stack *src, t_stack *dst)
{
    t_node *top;

    if (!src || src->size == 0)
        return;
    top = src->head;

    // retirer top de src
    if (src->size == 1)
    {
        src->head = NULL;
        src->size--;
    }
    else
    {
        src->head = top->next;
        src->head->prev = top->prev;
        top->prev->next = src->head;
        src->size--;
    }

    // ajouter top à dst
    if (!dst->head)
    {
        top->next = top;
        top->prev = top;
        dst->head = top;
    }
    else
    {
        top->next = dst->head;
        top->prev = dst->head->prev;
        dst->head->prev->next = top;
        dst->head->prev = top;
        dst->head = top;
    }
    dst->size++;
}


void    rotate(t_stack *s)
{
    if (s && s->size > 1)
        s->head = s->head->next;
}

void    revrotate(t_stack *s)
{
    if (s && s->size > 1)
        s->head = s->head->prev;
}

#include "push_swap.h"

void    sa(t_stack *a) {
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack *b) {
    swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_stack *a, t_stack *b) {
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void    pa(t_stack *a, t_stack *b) {
    push(b, a);
    write(1, "pa\n", 3);
}

void    pb(t_stack *a, t_stack *b) {
    push(a, b);
    write(1, "pb\n", 3);
}

void    ra(t_stack *a) {
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack *b) {
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b) {
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void    rra(t_stack *a) {
    revrotate(a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack *b) {
    revrotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b) {
    revrotate(a);
    revrotate(b);
    write(1, "rrr\n", 4);
}


