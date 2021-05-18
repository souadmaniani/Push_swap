#include "push_swap.h"
// LESS THAN 1100: FOR 100 NUMBER
// LESS THAN 8500: FOR 500 NUMBER
// 	stackiter(ft_rotate, a, b, "ra\n");
// ft_rotate(a, b);
// print_stacks("etat initial: \n", *a, *b);
// SHOUF A LHBIBA DIFF BETWEEN ALGO1 AND ALGO2 12001 - 10541 = 1460
void sort_three(t_stackelem **a, t_stackelem **b)
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
    // print_stack_cmds(cmd);
}

void sort_five(t_stackelem **a, t_stackelem **b)
{ 
    int         mid;
    int         i;
    int         len;
    int         middle;
    int         index;
    int j;

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
        sort_three(a, b);
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
                // ft_rotate(b, a);
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
                    // ft_reverse_rotate(b, a);
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
                        // ft_rotate(b, a);
                    j = -2;
                }
                else
                {
                    index = max_indx;
                    while (index < len)
                    {
                        // ft_reverse_rotate(b, a);
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
                        // ft_rotate(b, a);
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
    int			    index, i, len, middle, mid, j, is_rotate, k;
    int             arr[100][3];
    t_stackelem *tmp;

    // push all min then middle
    // while (!is_sorted(*a))
    k = 0;
    // print_stacks("INITIAL STATE\n", *a, *b);
    while (stacksize(*a) > 2)
    {
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
            if (i == 0)
                arr[k][1] = (*b)->data;
        }
        // print_stacks("STATE\n", *a, *b);
        half = stacksize(*a) / 2;
        // print_stacks("STATE 1 \n", *a, *b);
        arr[k][0] = (*b)->data;
        arr[k][2] = get_len(*b, arr[k][0], arr[k][1]);
        k++;
        if (is_sorted(*a))
            break ;
    }
    k--;
    if (!is_sorted(*a) && stacksize(*a) == 2)
        stackiter(ft_swap, a, b, "sa\n");
    // i = k;
    // while (i > -1)
    // {
    //     printf("LEN=========> %d \n", arr[i][2]);
    //     i--;
    // }
    // print_stacks("STATE 1 \n", *a, *b);
    print_stack_cmds(cmd);
    return ;
    while (*b)
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
                // print_stacks("stacks\n", *a, *b);
                middle = get_middle(*b, len);
                if (len == 1)
                {
                    push_max(a, b);
                    break ;
                }
                else if (len == 2)
                {
                    push_max(a, b);
                    push_max(a, b);
                    break ;
                }
                else if (len == 250)
                {   
                    sort_part(a, b, len);
                    while ((*a)->data != stackmin(*a))
                        stackiter(ft_reverse_rotate, a, b, "rra\n");
                    break ;
                }
                mid = len / 2;
                if (len % 2 == 0)
                    mid--;
                // while mazal chi haja kbar man middle o mazal hna f chunk
                j = 0;
                while (j < mid)
                {
                    index = stackmax_index(*b);
                    half = stacksize(*b) / 2;
                    if (index > half)
                    {
                        while (index++ < stacksize(*b))
                            stackiter(ft_reverse_rotate, b, a, "rrb\n");   
                    }
                    else if ((*b)->data <= middle)
                        stackiter(ft_rotate, b, a, "rb\n");
                    else if ((*b)->data > middle && (*b)->data != stackmax(*b))
                        stackiter(ft_rotate, b, a, "rb\n");
                    else if ((*b)->data == stackmax(*b))
                    {
                        stackiter(ft_push, a, b, "pa\n");
                        len--;
                        j++;
                    }
                }
            }
            k--;
        }
    }
    print_stack_cmds(cmd);
    // print_stacks("FINAL STATE \n", *a, *b);
}
void push_swap(t_stackelem **a, t_stackelem **b, int len)
{
    if (!is_sorted(*a))
    {
        if (len == 2)
            stackiter(ft_swap, a, b, "sa\n");
        else if (len == 3) // 2 instructions
            sort_three(a, b);
        else if (len == 5) // 12 instructions
            sort_five(a, b);
        else if (len == 100)
            sort_hundrd(a, b, stacksize(*a) / 2);
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
    int res;
    t_stackelem *a;
    t_stackelem *b;
    char *line;
	char **args;
    int len;
    // char **t = malloc(21 * sizeof(char*));
    // t[0] = ft_strdup("./push_swap");
    // t[1] = ft_strdup("0");
    // t[2] = ft_strdup("5");
    // t[3] = ft_strdup("15");
    // t[4] = ft_strdup("7");
    // t[5] = ft_strdup("2");
    // t[6] = ft_strdup("3");
    // t[7] = ft_strdup("17");
    // t[8] = ft_strdup("11");
    // t[9] = ft_strdup("4");
    // t[10] = ft_strdup("12");
    // t[11] = ft_strdup("18");
    // t[12] = ft_strdup("1");
    // t[13] = ft_strdup("16");
    // t[14] = ft_strdup("19");
    // t[15] = ft_strdup("10");
    // t[16] = ft_strdup("14");
    // t[17] = ft_strdup("13");
    // t[18] = ft_strdup("6");
    // t[19] = ft_strdup("9");
    // t[20] = ft_strdup("8");
	// t[21] = NULL;
	// argc = 20;
    // argv = t;
    int i = 0;
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
        // write(1, "stack a => ", 11);
        // print_stack(a);
        // write(1, "stack b => ", 11);
        // print_stack(b);
        // write(1, "stack a => ", 11);
        // print_stack(a);
        // write(1, "stack b => ", 11);
        // print_stack(b);
    }
    return 0;
}