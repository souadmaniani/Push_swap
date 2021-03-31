#include "push_swap.h"

// check Error (not integers) (overflow) (duplicate)
int is_duplicate(char *str, char **argv, int index)
{
    int i;
    int j;

    i = 0;
    while (argv[++i])
    {
        if (!strcmp(str, argv[i]) && index != i)
            return (1);
    }
     return (0);
}

int    create_stack(t_stackelem **head, char **argv)
{
    t_stackelem *new;
    int i;

    i = -1;
    *head = NULL;
    while (argv[++i])
    {
        if (ft_atoi(argv[i]) == -1 || (!ft_atoi(argv[i])
            && ft_strcmp(argv[i], "0")) || is_duplicate(argv[i], argv, i))
        {
            write(1, "Error\n", 7);
            return (-1);
        }
        new = stacknew(ft_atoi(argv[i]));
        if (!new)
            return (-1);
        stackadd_back(head, new);
    }
    return (0);
}

int is_sorted(t_stackelem *head)
{
    while (head->next)
    {
        if (head->data > head->next->data)
            return (0);
        head = head->next;
    }
    return (1);
}

// PRINT STACK
void print_stack(t_stackelem *head)
{
    char *str;
    t_stackelem *tmp;

    tmp = head;
    while (tmp)
    {
        str = ft_itoa(tmp->data);
        write(1, str, ft_strlen(str));
        write(1, " ", 1);
        tmp = tmp->next;
    }
    write(1, "\n", 1);
}