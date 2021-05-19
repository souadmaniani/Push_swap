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
        if ((ft_atoi(argv[i]) == -1 && ft_strcmp(argv[i], "-1") )
        || (!ft_atoi(argv[i]) && ft_strcmp(argv[i], "0"))
        || is_duplicate(argv[i], argv, i))
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
void print_stack_cmds(t_stackelem *head)
{
    t_stackelem *tmp;

    tmp = head;
    while (tmp)
    {
            if ((tmp->next )&& ((!strcmp(tmp->cmd , "ra\n") && !strcmp(tmp->next->cmd , "rb\n"))
                || (!strcmp(tmp->cmd , "rb\n") && !strcmp(tmp->next->cmd , "ra\n") )))
            {
                write(1, "rr\n", 3);
                 tmp = tmp->next;
            }
            else if ((tmp->next)  && ((!strcmp(tmp->cmd , "rra\n") && !strcmp(tmp->next->cmd , "rrb\n"))
                || (!strcmp(tmp->cmd , "rrb\n") && !strcmp(tmp->next->cmd , "rra\n"))))
            {
                write(1, "rrr\n", 4);
                 tmp = tmp->next;
            }
            else if ((tmp->next)  && ((!strcmp(tmp->cmd , "sa\n") && !strcmp(tmp->next->cmd , "sb\n"))
            || (!strcmp(tmp->cmd , "sb\n") && !strcmp(tmp->next->cmd , "sa\n"))))
            {
                write(1, "ss\n", 3);
                 tmp = tmp->next;
            }
            else
                write(1, tmp->cmd, ft_strlen(tmp->cmd));
            tmp = tmp->next;
    }
}

// 10807 ---> diff 63
// 10744