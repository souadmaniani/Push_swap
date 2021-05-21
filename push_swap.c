#include "push_swap.h"

void sort_three(t_stackelem **a, t_stackelem **b, int in_use)
{
    t_elem elem;

    elem.st = (*a)->data;
    elem.nd = (*a)->next->data;
    elem.rd = (*a)->next->next->data;

    if (elem.st == stackmax(*a))
    {
        stackiter(ft_rotate, a, b, "ra\n");
        if (!is_sorted(*a))
            stackiter(ft_swap, a, b,"sa\n");
    }
    else if (elem.st == stackmin(*a))
    {
        stackiter(ft_reverse_rotate, a, b,"rra\n");
        stackiter(ft_swap, a, b, "sa\n");
    }
    else
    {
        if (elem.st < elem.rd)
            stackiter(ft_swap, a, b,"sa\n");
        else
            stackiter(ft_reverse_rotate, a, b,"rra\n");
    }
    if (!in_use)
        print_stack_cmds(cmd);
}

void sort_five(t_stackelem **a, t_stackelem **b)
{ 
    int         mid;
    int         i;
    int         len;
    int         index;
    int         j;

    i = -1;
    while (++i < 2)
    {
        j = -1;
        len = stacksize(*a);
        index = stackmin_index(*a);
        mid = len / 2;
        if (index < mid)
            while (++j < index)
                stackiter(ft_rotate, a, b, "ra\n");
        else
        {
            while (index++ < len)
                stackiter(ft_reverse_rotate, a, b, "rra\n");
        }
        stackiter(ft_push, b, a, "pb\n");
    }
    
    if (!is_sorted(*a))
        sort_three(a, b, 1);
    stackiter(ft_push, a, b, "pa\n");
    stackiter(ft_push, a, b, "pa\n");
    print_stack_cmds(cmd);
}

int sort_part(t_stackelem **a, t_stackelem **b, int len)
{
    int mid;
    int j;
    int min_indx;
    int max_indx;
    int index;
    int is_rotate;

    is_rotate = 0;
    while (*b)
    {
        len = stacksize(*b);
        mid = len / 2;
        j = -1;
        min_indx = stackmin_index(*b);
        max_indx = stackmax_index(*b);
        if (min_indx < mid && max_indx < mid)
        {
            index = (min_indx < max_indx) ? min_indx : max_indx;
            while (++j < index)
                stackiter(ft_rotate, b, a, "rb\n");
            if (index == min_indx)
                j = -2;
        }
        else
        {
            if (min_indx >= mid && max_indx >= mid)
            {
                index = (min_indx > max_indx) ? min_indx : max_indx;
                if (index == min_indx)
                    j = -2;
                while (index < len)
                {
                    stackiter(ft_reverse_rotate, b, a, "rrb\n");
                    index++;
                }
            }
            else if  (min_indx < mid && max_indx >= mid)
            {
                if (min_indx <= len - 1 - max_indx)
                {
                    index = min_indx;
                    while (++j < index)
                        stackiter(ft_rotate, b, a, "rb\n");
                    j = -2;
                }
                else
                {
                    index = max_indx;
                    while (index < len)
                    {
                        stackiter(ft_reverse_rotate, b, a, "rrb\n");
                        index++;
                    }
                }
            }
            else if (max_indx < mid && min_indx >= mid)
            {
                if (max_indx <= len - 1 - min_indx)
                {
                    index = max_indx;
                    while (++j < index)
                        stackiter(ft_rotate, b, a, "rb\n");
                }
                else
                {
                    index = min_indx;
                    while (index < len)
                    {
                        stackiter(ft_reverse_rotate, b, a, "rrb\n");
                        index++;
                    }
                    j = -2;
                }
            }
        }
        stackiter(ft_push, a, b, "pa\n");
        if (j == -2)
        {
            stackiter(ft_rotate, a, b, "ra\n");
            is_rotate++;
        }
    }
    return (is_rotate);
}

void sort_hundrd(t_stackelem   **a, t_stackelem    **b, int    half)
{
    int			    index;
    int			    i;
    int             len;
    int             middle;
    int             mid;
    int             j;

	i = -1;
    len = stacksize(*a);
    middle = get_middle(*a, len);
    while (++i < half)
    {
        len = stacksize(*a);
        mid = len / 2;
        index = get_min_indexes(*a, middle, len);
        j = -1;
        if (index < mid)
            while (++j < index)
                stackiter(ft_rotate, a, b, "ra\n");
        else
        {
            while (index++ < len)
                stackiter(ft_reverse_rotate, a, b, "rra\n");
        }
        stackiter(ft_push, b, a, "pb\n");
    }
    sort_part(a, b, len);
    while ((*a)->data < middle)
        stackiter(ft_rotate, a, b, "ra\n");
    while ((*a)->data >= middle)
        stackiter(ft_push, b, a, "pb\n");
    sort_part(a, b, len);
    while ((*a)->data >= middle)
        stackiter(ft_rotate, a, b, "ra\n");
    print_stack_cmds(cmd);
}

void push_max(t_stackelem   **a, t_stackelem    **b)
{
    int index;
    int half;

    index = stackmax_index(*b);
    half = stacksize(*b) / 2;
    if (index > half)
    {
        while (index++ < stacksize(*b))
            stackiter(ft_reverse_rotate, b, a, "rrb\n");
        stackiter(ft_push, a, b, "pa\n");
    }
    else
    {
        while ((*b)->data != stackmax(*b))
            stackiter(ft_rotate, b, a, "rb\n");
        stackiter(ft_push, a, b, "pa\n");
    }
}

void sort_five_h(t_stackelem   **a, t_stackelem    **b, int    half)
{
    int			    index, i, len, mid, j, k, max_chunk;
    int             arr[100][3], chunk_len;
    // t_stackelem     *tmp;
    // t_stackelem     *cmd;

    k = 0;
    chunk_len = stacksize(*a) / 11;
    while (stacksize(*a))
    {
        i = -1;
        len = stacksize(*a);
        max_chunk = get_max_of_chunk(*a, len, chunk_len);
        while (++i < chunk_len)
        {
            len = stacksize(*a);
            mid = len / 2;
            index = get_min_indexes(*a, max_chunk, len);
            j = -1;
            if (index < mid)
                while (++j < index)
                    stackiter(ft_rotate, a, b, "ra\n");
            else
            {
                while (index++ < len)
                    stackiter(ft_reverse_rotate, a, b, "rra\n");
            }
            stackiter(ft_push, b, a, "pb\n");
            if (i == 0)
                arr[k][1] = (*b)->data;
        }
        if (!is_sorted(*a) && stacksize(*a) < chunk_len)
        {
            while (*a)
                 stackiter(ft_push, b, a, "pb\n");
        }
        arr[k][0] = (*b)->data;
        arr[k][2] = get_len(*b, arr[k][0], arr[k][1]);
        k++;
        if ( *a && (is_sorted(*a) || stacksize(*a) == 1))
            break ;
    }
    k--;
    while (k >= 0)
    {
        len = stacksize(*b);
        if (is_reverse_sorted(*b, len))
            while (*b)
                stackiter(ft_push, a, b, "pa\n");
        else
        {
            i = -1;
            len = arr[k][2];
            while (len)
            {
                mid = len / 2;
                if (len % 2 == 0)
                mid--;
                index = stackmax_index(*b);
                half = stacksize(*b) / 2;
                max_chunk = stackmax(*b);
                if (index > half)
                {
                    while (index++ < stacksize(*b))
                        stackiter(ft_reverse_rotate, b, a, "rrb\n");   
                }
                else if ((*b)->data < max_chunk)
                    stackiter(ft_rotate, b, a, "rb\n");
                else if ((*b)->data == max_chunk)
                {
                    stackiter(ft_push, a, b, "pa\n");
                    len--;
                    j++;
                }
            }
            k--;
        }
    }
    print_stack_cmds(cmd);
}
void push_swap(t_stackelem **a, t_stackelem **b, int len)
{
    if (!is_sorted(*a))
    {
        if (len == 2)
        {
            ft_swap(a, b);
            write(1, "sa\n", 3);
        }
        else if (len == 3)
            sort_three(a, b, 0);
        else if (len == 5)
            sort_five(a, b);
        else if (len <= 100)
            sort_hundrd(a, b,  stacksize(*a) / 2);
        else
            sort_five_h(a, b, stacksize(*a) / 2);
    }
}

void free_tab(char ***tab)
{
    int i;

    i = 0;
    while (*tab[i])
    {
        free(*tab[i]);
        *tab[i] = NULL;
        i++;
    }
    free(*tab);
    **tab = NULL;
}

int main(int argc, char *argv[])
{
    int ret;
    t_stackelem *a;
    t_stackelem *b;
    
	char **args;
    int len;

    if (argc >= 2)
    {
        b = NULL;
        if (argc == 2)
        {
            args = ft_split(argv[1], ' ', &len);
            ret = create_stack(&a, args);
            argc = len + 1;
            // FREE ARGS
        }
        else
            ret = create_stack(&a, argv + 1);
        if(ret == -1)
            return(-1);
        push_swap(&a, &b, argc - 1);
    }
    return 0;
}