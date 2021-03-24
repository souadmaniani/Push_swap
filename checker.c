#include "push_swap.h"

// check Error (not integers) (overflow) (duplicate)
int    create_stack(t_stackelem **head, char **argv)
{
    t_stackelem *new;
    int i;

    i = 0;
    *head = NULL;
    while (argv[++i])
    {
        if (ft_atoi(argv[i]) == -1 || (!ft_atoi(argv[i])
            && ft_strcmp(argv[i], "0")))
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
// PRINT STACK
void print_stack(t_stackelem *head)
{
    char *str;
    while (head)
    {
        str = ft_itoa(head->data);
        write(1, str, ft_strlen(str));
        write(1, " ", 1);
        head = head->next;
    }
    write(1, "\n", 1);
}

int apply_instruction(char *line, t_stackelem **a, t_stackelem **b)
{

    if(!ft_strcmp(line, "sa"))
        swap(*a);
    else if (!ft_strcmp(line, "sb"))
        swap(*b);
    else if (!ft_strcmp(line, "ss"))
    {
        swap(*a);
        swap(*b);
    }
    else if (!ft_strcmp(line, "pa"))
        push(a, b);
    else if (!ft_strcmp(line, "pb"))
        push(b, a);
    else if (!ft_strcmp(line, "ra"))
        rotate(a);   
    else if (!ft_strcmp(line, "rb"))
        rotate(b);
    else if (!ft_strcmp(line, "rr"))
    {
        rotate(a);
        rotate(b);
    }
    else if (!ft_strcmp(line, "rra"))
        reverse_rotate(a);
    else if (!ft_strcmp(line, "rrb"))
        reverse_rotate(b);
    else if (!ft_strcmp(line, "rrr"))
    {
        reverse_rotate(a);
        reverse_rotate(b);
    }
    else
    {
        write(1, "Error\n", 6);
        return (-1);
    }
    return (0);
}
//sa pb pb pb rr rrr sa pa pa pa

int is_sortded(t_stackelem *head)
{
    while (head->next)
    {
        if (head->data > head->next->data)
            return (0);
        head = head->next;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    int ret;
    int res;
    t_stackelem *a;
    t_stackelem *b;
    char *line;
    if (argc > 1)
    {
        b = NULL;
        ret = create_stack(&a, argv);
        if(ret == -1)
            return(-1);
        while (get_next_line(0, &line) > 0)
        {
            res = apply_instruction(line, &a, &b);
            if (res == -1)
            {
                free(line);
                return (-1);
            }
            free(line);
        }
        write(1, "stack a => ", 11);
        print_stack(a);
        write(1, "stack b => ", 11);
        print_stack(b);
        if (is_sortded(a) && !b)
            write(1, "OK\n", 3);
        else
            write(1, "KO\n", 3);
    }
    return 0;
}