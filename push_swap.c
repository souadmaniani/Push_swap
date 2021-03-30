#include "push_swap.h"

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
t_stackelem *getpointer(t_stackelem *a, int index)
{
    int i;
    t_stackelem *tmp;

    tmp = a;
    i = 0;
    while (tmp)
    {
    	if (i == index)
    		return tmp;
		i++;
		tmp = tmp->next;
    }
    return 0;
}

void elem_order(t_stackelem *a, t_elem *elem)
{
	t_stackelem *ptr;
	t_stackelem *copy = NULL;

	
	copy = stackcopy(&copy, a);
    elem->st = stackmin(a);
    elem->fth = stackmax(a);
    ptr = stack_search(copy, elem->st);
    ptr->data = INT_MAX;
    ptr = stack_search(copy, elem->fth);
    ptr->data = INT_MAX;
    elem->nd = stackmin(copy);
    ptr = stack_search(copy, elem->nd);
    ptr->data = INT_MAX;
    elem->rd = stackmin(copy);
    ptr = stack_search(copy, elem->rd);
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
    { // 2 3 4-> 1 5| 2 3 5-> 1 4| 2 4 5-> 1 3
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
    else if ((*b)->next->data == elem.st)
    { // 1 2 3|1 2 4|1 2 5|1 3 4|1 3 5|1 4 5;
        
        // 6 CASES
    }
    
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
    // char **t = malloc(7 * sizeof(char*));
    // t[0] = ft_strdup("./push_swap");
    // t[1] = ft_strdup("1");
    // t[2] = ft_strdup("2");
    // t[3] = ft_strdup("3");
    // t[4] = ft_strdup("5");
    // t[5] = ft_strdup("4");
	// t[6] = NULL;
	// argc = 6;
    if (argc >= 2)
    {
        b = NULL;
        if (argc == 2)
        {
            args = ft_split(argv[1], ' ', &len);
            ret = create_stack(&a, args);
        }
        else
            ret = create_stack(&a, argv);
        if(ret == -1)
            return(-1);
        push_swap(&a, &b, argc - 1);
        // write(1, "stack a => ", 11);
        // print_stack(a);
        // write(1, "stack b => ", 11);
        // print_stack(b);
    }
    return 0;
}