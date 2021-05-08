#include "push_swap.h"
// LESS THAN 1100: FOR 100 NUMBER
// LESS THAN 8500: FOR 500 NUMBER

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
}

void elem_order(t_stackelem *a, t_elem *elem)
{
	t_stackelem *ptr;
	t_stackelem *copy = NULL;

	
	copy = stackcopy(&copy, a);
    elem->st = stackmin(a);
    elem->fth = stackmax(a);
    ptr = stackchr(copy, elem->st);
    ptr->data = INT_MAX;
    ptr = stackchr(copy, elem->fth);
    ptr->data = INT_MAX;
    elem->nd = stackmin(copy);
    ptr = stackchr(copy, elem->nd);
    ptr->data = INT_MAX;
    elem->rd = stackmin(copy);
    ptr = stackchr(copy, elem->rd);
    ptr->data = INT_MAX;
    elem->rth = stackmin(copy);
}

void sort_five(t_stackelem **a, t_stackelem **b)
{ 
    t_stackelem ptr;
    int         i;
    int         min;
    t_elem      elem;

    // elem_order(*a, &elem);
    elem_order(*a, &elem);
    stackiter(ft_push, b, a, "pb\n");
    stackiter(ft_push, b, a, "pb\n");
    if (!is_sorted(*a))
        sort_three(a, b);
	if ((*a)->data == elem.rd)
    {// 3 4 5
        stackiter(ft_push, a, b, "pa\n");
        stackiter(ft_push, a, b, "pa\n");
        if (!is_sorted(*a))
            stackiter(ft_swap, a, b, "sa\n");
    }
	else if ((*a)->data == elem.nd)
    { // 2 3 4-> [1,5] | 2 3 5-> [1,4] | 2 4 5-> [1,3]
        if ((*b)->data == elem.fth || (*b)->next->data == elem.fth)
		{
			stackiter(ft_push,a, b, "pa\n");
			if ((*b)->data == elem.fth)
			{
				stackiter(ft_push, a, b, "pa\n");
				stackiter(ft_rotate, a, b, "ra\n");
			}
			else
			{
				stackiter(ft_rotate, a, b, "ra\n");
				stackiter(ft_push, a, b, "pa\n");
			}
		}
		else if ((*b)->data == elem.rd || (*b)->next->data == elem.rd)
		{
			if ((*b)->next->data == elem.rd)
				stackiter(ft_swap, b, a, "sb\n");
			stackiter(ft_push, a, b, "pa\n");
			stackiter(ft_swap, a, b, "sa\n");
			stackiter(ft_push, a, b, "pa\n");
		}
		else
		{
			if ((*b)->data == elem.st)
				stackiter(ft_swap, b, a, "sb\n");
			stackiter(ft_reverse_rotate, a, b, "rra\n");
			stackiter(ft_push, a, b, "pa\n");
			stackiter(ft_rotate, a, b, "ra\n");
			stackiter(ft_rotate, a, b, "ra\n");
			stackiter(ft_push, a, b, "pa\n");
		}
    }
    else if ((*a)->data == elem.st)
    { // 1 2 3 | 1 2 4 | 1 2 5 | 1 3 4 | 1 3 5 | 1 4 5;
        if (stackchr(*b, elem.fth) && stackchr(*b, elem.rth))
        {
            if (is_sorted(*b))
                stackiter(ft_swap, b, a, "sb\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_rotate, a, b, "ra\n");
			stackiter(ft_rotate, a, b, "ra\n");
        }
        else if (stackchr(*b, elem.fth) && stackchr(*b, elem.rd))
        {
            if (!is_sorted(*b))
                stackiter(ft_swap, b, a, "sb\n");
            stackiter(ft_push, a, b, "rra\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_rotate, a, b, "ra\n");
            stackiter(ft_rotate, a, b, "ra\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_rotate, a, b, "ra\n");
        }
        else if (stackchr(*b, elem.rth) && stackchr(*b, elem.rd))
        {
            if ((*b)->data == elem.rth)
            {
                stackiter(ft_push, a, b, "rra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_rotate, a, b, "ra\n");
            }
            else
            {
                stackiter(ft_push, a, b, "rra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_rotate, a, b, "ra\n");
            }
        }
        else if (stackchr(*b, elem.fth) && stackchr(*b, elem.nd))
        {
            if ((*b)->data == elem.nd)
            {
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_swap, a, b, "sa\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
            }
            else
            {
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_swap, a, b, "sa\n");
            }
        }
        else if (stackchr(*b, elem.rth) && stackchr(*b, elem.nd))
        {   if ((*b)->data == elem.rth)
            {
                stackiter(ft_push, a, b, "rra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_swap, a, b, "sa\n");
            }
            else
            {   stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_swap, a, b, "sa\n");
                stackiter(ft_push, a, b, "rra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_rotate, a, b, "ra\n");
            }
        }
        else if (stackchr(*b, elem.rd) && stackchr(*b, elem.nd))
        {
            if (is_sorted(*b))
                stackiter(ft_swap, b, a, "sb\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_swap, a, b, "sa\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_swap, a, b, "sa\n");
        }
    }
}

void print_stacks(char *str, t_stackelem *a, t_stackelem *b)
{
        write(1, str, ft_strlen(str));
    	write(1, "      stack a => ", 17);
        print_stack(a);
        write(1, "      stack b => ", 17);
        print_stack(b);
}

// 	stackiter(ft_rotate, a, b, "ra\n");
// ft_rotate(a, b);
// print_stacks("etat initial: \n", *a, *b);

int *copystack_arr(t_stackelem *a, int len)
{
    int *arr;
    int i;

    i = 0;
    arr = malloc(sizeof(int) * len);
    while (a)
    {
        arr[i++] = a->data;
        a = a->next;
    }
    return (arr);
}
int get_middle(t_stackelem *a, int len)
{
    int mid;
    int *arr;
    int i;
    int *sorted_arr;

    if (len == 1)
        return (a->data);
    if (len == 2)
        return (a->next->data);
    i = 0;
    arr = copystack_arr(a, len);
    sorted_arr = quiq_sort(arr, 0, len - 1);
    mid = sorted_arr[len/2];
    return (mid);
}

int get_min_indexes(t_stackelem *a, int mid, int len)
{
    int index1;
    int index2;
    int *arr;
    int i;
    int j;

    arr = copystack_arr(a, len);
    index1 = 0;
    index2 = 0;
    i = -1;
    // get_min_from_top
    while (arr[++i] >= mid)
        index1++;
    // get_min_from_bottom
    i = 0;
    while (arr[len - i - 1] >= mid)
    {
        index2++;
        i++;
    }
    free(arr);
    if (index1 < index2)
        return (index1);
    return (len - i - 1);
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

int get_index(t_stackelem *a, int middle)
{
    int index;
    while (a->data > middle)
    {
       a = a->next;
       index++;
    }
    return (index);
}

int get_max_indexes(t_stackelem *a, int mid, int len)
{
    int index1;
    int index2;
    int *arr;
    int i;
    int j;

    arr = copystack_arr(a, len);
    index1 = 0;
    index2 = 0;
    i = -1;
    // get_max_from_top
    while (arr[++i] <= mid)
        index1++;
    // get_max_from_bottom
    i = 0;
    while (arr[len - i - 1] <= mid)
    {
        index2++;
        i++;
    }
    // free(arr);
    if (index1 <= index2)
        return (index1);
    return (len - i - 1);
}
int get_len(t_stackelem *a, int first, int last)
{
    int len;

    len = 0;
    while (a->data != first)
        a = a->next;
    while (a->data != last)
   {
       len++;
       a = a->next;
   }
    return (len + 1);
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

int is_reverse_sorted(t_stackelem *head, int len)
{
    while (len)
    {
        if (head->data < head->next->data)
            return (0);
        head = head->next;
        len--;
    }
    return (1);
}

void print_nbr(char *str, int n)
{
    char *nbr;

    write(1, str, ft_strlen(str));
    nbr = ft_itoa(n);
    write(1, nbr, ft_strlen(nbr));
    write(1, "\n", 1);
}
void sort_five_h(t_stackelem   **a, t_stackelem    **b, int    half)
{
    int			    index;
    int			    i;
    int             len;
    int             middle;
    int             mid;
    int             j;
    int             is_rotate;
    int             k;
    int             arr[8][2];
    int             count;
    int             count2;
    int             count3;
    t_stackelem *tmp;
    // while (!is_sorted(*a))
    // {
        k = 0;
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
            half = stacksize(*a) / 2;
            arr[k][0] = (*b)->data;
            k++;
        }
        k--;
        if (!is_sorted(*a))
            stackiter(ft_swap, a, b, "sa\n");
        // print_stacks("etat 1: \n", *a, *b);
        // print_nbr("k ", k);
        while (*b)
        {
            print_stacks("etat 1: \n", *a, *b);
            len = stacksize(*b);
            if (is_reverse_sorted(*b, len))
            {
                while (len)
                {
                    stackiter(ft_push, a, b, "pa\n");
                    len--;
                }
            }
            else
            {
                i = -1;
                len = get_len(*b, arr[k][0], arr[k][1]);
                middle = get_middle(*b, len);
                // print_nbr("first ", arr[k][0]);
                // print_nbr("last ", arr[k][1]);
                // print_nbr("len ", len);
                // print_nbr("middle ", middle);
                while (len)
                {
                    // print_nbr("len ", len);
                    middle = get_middle(*b, len);
                    if (len == 1)
                    {
                        stackiter(ft_push, a, b, "pa\n");
                        break ;
                    }
                    else if (len == 2)
                    {
                        if ((*b)->data < (*b)->next->data)
                            stackiter(ft_swap, b, a, "sb\n");
                        stackiter(ft_push, a, b, "pa\n");
                        stackiter(ft_push, a, b, "pa\n");
                        break ;
                    }
                    j = 0;
                    mid = len / 2;
                    // while mazal chi haja kbar man middle o mazal hna f chunk
                    count = 0;
                    count2 = 0;
                    count3 = 0;
                    while (stackmax(*b) != middle)
                    {
                        // 3 4 5  && 3 4 5 > middle = 2
                        // print_nbr("max_stack ", stackmax(*b));
                        // print_nbr("middle ",middle);
                        if ((*b)->data > middle && (*b)->next->data > middle)
                        {
                            while ((*b)->data > middle && (*b)->next->data > middle)
                            {
                                stackiter(ft_rotate, b, a, "rb\n");
                                count2++;
                            }
                            stackiter(ft_push, a, b, "pa\n");
                            len--;
                            while (count2)
                            {
                                stackiter(ft_reverse_rotate, b, a, "rrb\n");
                                stackiter(ft_push, a, b, "pa\n");
                                len--;
                                count2--;
                            }
                        }
                        else if ((*b)->data <= middle)
                        {
                            stackiter(ft_rotate, b, a, "rb\n");
                            count++;
                            // print_nbr("dkhal hna ", count);
                        }
                        else if ((*b)->data > middle && (*b)->data == stackmax(*b))
                        {
                                stackiter(ft_push, a, b, "pa\n");
                                len--;
                                if (count3 != -1 && count3 != 0)
                                {
                                    count3 = count3 + count;
                                    count = 0;
                                    while (count3--)
                                        stackiter(ft_reverse_rotate, b, a, "rrb\n");
                                }
                        }
                        else if ((*b)->data > middle && (*b)->data != stackmax(*b))
                        {
                            stackiter(ft_rotate, b, a, "rb\n");
                            count3++;
                        }
                        j++;
                        // print_nbr("count ", count);
                        // print_nbr("count3 ", count3);
                        
                        print_stacks("etat : \n", *a, *b);
                    }
                    while (count--)
                        stackiter(ft_reverse_rotate, b, a, "rrb\n");
                }
                k--;
            }
        }
        // print_stacks("etat final: \n", *a, *b);
    // }
}
// 2 0 6 12 11 9 4 7 10 8 3 1 5

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
    // char **t = malloc(10 * sizeof(char*));
    // t[0] = ft_strdup("./push_swap");
    // t[1] = ft_strdup("5");
    // t[2] = ft_strdup("4");
    // t[3] = ft_strdup("3");
    // t[4] = ft_strdup("1");
    // t[5] = ft_strdup("2");
    // t[6] = ft_strdup("7");
    // t[7] = ft_strdup("8");
    // t[8] = ft_strdup("9");
	// t[9] = NULL;
	// argc = 10;
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