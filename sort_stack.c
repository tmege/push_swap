#include "push_swap.h"

int stack_is_sorted(t_stack *a)
{
    t_node *cur;
    int i;

    if (!a || a->size < 2)
        return (1);
    cur = a->head;
    i = 1;
    while (i < a->size)
    {
        if (cur->value > cur->next->value)
            return (0);
        cur = cur->next;
        i++;
    }
    return (1);
}

// Cherche la position (distance) du prochain index du chunk
static int	find_chunk_pos(t_stack *a, int start, int end)
{
	t_node	*top = a->head;
	t_node	*bot = a->head->prev;
	int		i = 0;

	// Depuis le haut
	while (i < a->size)
	{
		if (top->index >= start && top->index <= end)
			return i;
		top = top->next;
		i++;
	}
	// Depuis le bas
	i = 1;
	while (i < a->size)
	{
		if (bot->index >= start && bot->index <= end)
			return -i;
		bot = bot->prev;
		i++;
	}
	return -9999;
}

// Push tous les nodes d'un chunk dans B
static void	push_chunk_to_b(t_stack *a, t_stack *b, int start, int end)
{
	int pos;
	while ((pos = find_chunk_pos(a, start, end)) != -9999)
	{
		if (pos == 0)
			pb(a, b);
		else if (pos > 0)
			while (pos-- > 0)
				ra(a);
		else if (pos < 0)
			while (pos++ < 0)
				rra(a);
	}
}

// Trouve la position du max dans B
static int	find_max_pos(t_stack *b)
{
	t_node	*cur = b->head;
	int		max = cur->index, i = 0, max_pos = 0;
	while (i < b->size)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_pos = i;
		}
		cur = cur->next;
		i++;
	}
	return max_pos;
}

// Push back le max de B dans A jusqu'à ce que B soit vide
static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int pos;
	while (b->size)
	{
		pos = find_max_pos(b);
		if (pos <= b->size / 2)
			while (pos-- > 0)
				rb(b);
		else
			while (pos++ < b->size)
				rrb(b);
		pa(a, b);
	}
}

void sort_big_stack(t_stack *a, t_stack *b)
{
    int chunk_count;
    int chunk_size;
    int start, end, i = 0;

    // Ajustement plus robuste pour petites tailles
    if (a->size <= 20)
        chunk_count = 1;
    else if (a->size <= 100)
        chunk_count = 5;
    else
        chunk_count = 11;

    chunk_size = a->size / chunk_count + (a->size % chunk_count != 0);

    while (i < chunk_count)
    {
        start = i * chunk_size;
        end = start + chunk_size - 1;
        if (end >= a->size)
            end = a->size - 1;
        push_chunk_to_b(a, b, start, end);
        i++;
    }
    push_back_to_a(a, b);
}


