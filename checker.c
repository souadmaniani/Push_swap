#include "push_swap.h"

int apply_instruction(char *line, t_stackelem **a, t_stackelem **b)
{

    if(!ft_strcmp(line, "sa"))
        ft_swap(a, b);
    else if (!ft_strcmp(line, "sb"))
        ft_swap(b, a);
    else if (!ft_strcmp(line, "ss"))
    {
        ft_swap(a, b);
        ft_swap(b, a);
    }
    else if (!ft_strcmp(line, "pa"))
        ft_push(a, b);
    else if (!ft_strcmp(line, "pb"))
        ft_push(b, a);
    else if (!ft_strcmp(line, "ra"))
        ft_rotate(a, b);   
    else if (!ft_strcmp(line, "rb"))
        ft_rotate(b, a);
    else if (!ft_strcmp(line, "rr"))
    {
        ft_rotate(a, b);
        ft_rotate(b, a);
    }
    else if (!ft_strcmp(line, "rra"))
        ft_reverse_rotate(a, b);
    else if (!ft_strcmp(line, "rrb"))
        ft_reverse_rotate(b, a);
    else if (!ft_strcmp(line, "rrr"))
    {
        ft_reverse_rotate(a, b);
        ft_reverse_rotate(b, a);
    }
    else
    {
        write(1, "Error\n", 6);
        return (-1);
    }
    return (0);
}
//sa pb pb pb rr rrr sa pa pa pa

int main(int argc, char *argv[])
{
    int ret;
    int res;
    t_stackelem *a;
    t_stackelem *b;
    char *line;
    char **args;
    int len;
    if (argc >= 2)
    {
        b = NULL;
        if (argc == 2)
        {
            args = ft_split(argv[1], ' ', &len);
            ret = create_stack(&a, args);
        }
        else
            ret = create_stack(&a, argv + 1);
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
        if (is_sorted(a) && !b)
            write(1, "OK\n", 3);
        else
            write(1, "KO\n", 3);
    }
    return 0;
}