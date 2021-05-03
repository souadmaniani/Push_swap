#include "push_swap.h"
// LESS THAN 1100: FOR 100 NUMBER
// LESS THAN 8500: FOR 500 NUMBER
#include <limits.h>

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

t_stackelem  *stackchange_value(t_stackelem *a, int value)
{
    t_stackelem *tmp;
    t_stackelem *copy = NULL;
    copy = stackcopy(&copy, a);
    tmp = copy;
    while (tmp->data != value)
       tmp= tmp->next;
    tmp->data = INT_MIN;
    return (copy);
    
}

int *getLargestHalf(t_stackelem *a)
{
    int         *tmp;
    int         max;
    int         middle;
    int         *arr;
    int         i;
    t_stackelem *copy = NULL;

    middle = stacksize(a) / 2;
    i = 0;
    arr = malloc(middle * sizeof(int));
    tmp = malloc(middle * sizeof(int));
    copy = stackcopy(&copy, a);
    while (i < middle)
    {
        max = stackmax(copy);
        tmp[i++] = max;
        copy = stackchange_value(copy, max);
    }
    i = 0;
    while (middle--)
    {
        arr[i] = tmp[middle];
        i++;
    }
    return (arr);
}

t_stackelem *stackcopyHalf(t_stackelem **dest, t_stackelem *src)
{
    int         mid;
    int         i;
    t_stackelem *new;

    i = -1;
    mid = stacksize(src) / 2;
    while (++i < mid)
        src = src->next;
    while (src)
    {
        new = stacknew(src->data);
        if (!new)
            return (0);
        stackadd_back(dest, new);
        src = src->next;
    }
    return (*dest);
}

int *getlastLargestHalf(t_stackelem *a)
{
    int         *tmp;
    int         max;
    int         middle;
    int         *arr;
    int         i;
    t_stackelem *copy = NULL;

    middle = stacksize(a) / 2;
    if (stacksize(a) % 2 != 0)
        middle = middle + 1;
    i = 0;
    arr = malloc(middle * sizeof(int));
    tmp = malloc(middle * sizeof(int));
    copy = stackcopyHalf(&copy, a);
    middle = stacksize(copy);
    while (i < middle)
    {
        max = stackmax(copy);
        tmp[i++] = max;
        copy = stackchange_value(copy, max);
    }
    i = 0;
    while (middle--)
    {
        arr[i] = tmp[i];
        i++;
    }
    return (arr);
}

void sort_hundred(t_stackelem **a, t_stackelem **b, int mid)
{
    int			    index;
    int			    i;
	t_stackelem     *elem;
	int			    middle;
	int			    j;
    int             len;
    int             *tab;

	i = 0;
    len = stacksize(*a);
    tab = getLargestHalf(*a);
    // print_stacks("etat initial: \n", *a, *b);
	// etape1=> PUSH TO B HALF MIN
    while (i < mid)
    {
		// GET INDEX OF MIN
        index = stackindex(*a, tab[i]);
		// GET MIDDLE OF STACK
		middle = stacksize(*a) / 2;
		j = -1;
		// COMPARE INDEX WITH MIDDLE
		if (index < middle)
		{
			while (++j < index)
				stackiter(ft_rotate, a, b, "ra\n");
                // ft_rotate(a, b);
		}
		else
		{
			while (index++ < stacksize(*a))
				stackiter(ft_reverse_rotate, a, b, "rra\n");
                // ft_reverse_rotate(a, b);
		}
        // ft_push(b, a);
		stackiter(ft_push, b, a, "pb\n");
		i++;
    }
    // print_stacks("etape1: \n", *a, *b);
	// // etape2=> FREE STACK B
	i = -1;
	while (++i < mid)
		stackiter(ft_push, a, b, "pa\n");
        // ft_push(a, b);
    if (len % 2 != 0)
    {
        len = len - 1;
        mid = mid + 1;
    }
    // should be optimised (demi tour {i = mid})
	// while (i++ < len)
	// 	stackiter(ft_rotate, a, b, "ra\n");
        // ft_rotate(a, b);
	// print_stacks("etape2: \n", *a, *b);
	// // etape3=> PUSH TO B THE OTHER HALF MIN
	i = -1;
	// while (++i < mid)
	// 	stackiter(ft_push, b, a, "pb\n");
        // ft_push(b, a);
    // print_stacks("etape3: \n", *a, *b);
	// // etape4=> SORT THE FIRST MIDDLE
	i = -1;
    tab = getlastLargestHalf(*a);
    middle = stacksize(*a) / 2;
    // print_stacks("etape3: \n", *a, *b);
    while (++i < mid)
    {
		index = stackindex(*a, tab[i]);
		
    }
    // print_stacks("etape1: \n", *a, *b);
	// // etape2=> FREE STACK B
    // print_stacks("etape4: \n", *a, *b);
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