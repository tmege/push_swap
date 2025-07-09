#include "push_swap.h"

int is_number(char *str)
{
    int i = 0;
    if (!str || !str[0])
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}


// Vérifie s'il y a un doublon dans la stack
int is_duplicate(t_stack *stack, int value)
{
    t_node *cur = stack->head;
    int i = 0;
    while (i < stack->size && cur)
    {
        if (cur->value == value)
            return (1);
        cur = cur->next;
        i++;
    }
    return (0);
}

// Libère un tableau de strings (pour ft_split)
void free_split(char **split)
{
    int i = 0;
    while (split && split[i])
        free(split[i++]);
    free(split);
}

void parse_args(int argc, char **argv, t_stack *a)
{
    int     i = 1, j, val;
    char    **split;

    while (i < argc)
    {
        split = ft_split(argv[i], ' ');
        if (!split)
            error_exit(a, NULL);
        j = 0;
        while (split[j])
        {
            if (!is_number(split[j]))
                error_exit(a, NULL);
            val = ft_atoi(split[j]);
            if (is_duplicate(a, val))
                error_exit(a, NULL);
            t_node *node = new_node(val);
            if (!node)
                error_exit(a, NULL);
            stack_add_back(a, node);
            j++;
        }
        free_split(split);
        i++;
    }
}


