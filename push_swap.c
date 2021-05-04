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
// getmin_max_index
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

void sort_hundred(t_stackelem **a, t_stackelem **b, int half)
{
    int			    index;
    int			    i;
    int             len;
    int             middle;
    t_stackelem     *tmp;
    int             mid;
    int             bottom;

	i = -1;
    len = stacksize(*a);
    middle = get_middle(*a, len);
    tmp = *a;
    printf("middle=> %d  half=> %d\n", middle, half);
    while (++i < half)
    {
        // get index elem indferieur a middle from top and bottom
        // compare the indexes and do ra or rra
        len = stacksize(*a);
        mid = len / 2;
        index = get_min_indexes(*a, middle, len);
        printf("index %d\n", index);
        if (index < mid)
        {
            while (index < mid)
            {
                ft_rotate(a, b);
                index++;
            }
        }
        else
        {
            while (index < len)
            {
                ft_reverse_rotate(a, b);
                index++;
            }
        }
        ft_push(b, a);
    }
    print_stacks("etape1: \n", *a, *b);
    // get min and max in b do ra or rra and push to top or bottom
    while (*b)
    {
        bottom = 0;
        len = stacksize(*b);
        mid = len / 2;
        if (abs(stackmin_index(*b) - mid) <= abs(stackmax_index(*b) - mid))
        {
            index = stackmin_index(*b);
            if (index < mid)
            {
                while (index < mid)
                {
                        ft_rotate(b, a);
                        index++;
                }
            }
            else
            {
                while (index < len)
                {
                    ft_reverse_rotate(b, a);
                    index++;
                }
            }
            bottom = 1;
        }
        else
        {
            index = stackmax_index(*b);
            if (index < mid)
            {
                while (index < mid)
                {
                        ft_rotate(b, a);
                        index++;
                }
            }
            else
            {
                while (index < len)
                {
                    ft_reverse_rotate(b, a);
                    index++;
                }
            }
        }
       ft_push(a, b);
        if (bottom)
            ft_rotate(a, b);
       print_stacks("etape: \n", *a, *b);
    }
    print_stacks("etape2: \n", *a, *b);
}

void push_swap(t_stackelem **a, t_stackelem **b, int len)
{
    if (!is_sorted(*a))
    {
        if (len == 2)
            stackiter(ft_swap, a, b, "sa\n");
        if (len == 3) // 2 instructions
            sort_three(a, b);
        if (len == 5) // 12 instructions
            sort_five(a, b);
        else // Less than 700
            sort_hundred(a, b, stacksize(*a) / 2);
    }
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