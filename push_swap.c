#include "push_swap.h"

int stackmax(t_stackelem *a)
{
    int maxim = a->data;
    a = a->next;
    while (a)
    {
        if (a->data > maxim)
            maxim = a->data;
        a = a->next;
    }
    return (maxim);
    
}

int stackmin(t_stackelem *a)
{
    int minim = a->data;
    a = a->next;
    while (a)
    {
        if (a->data < minim)
            minim = a->data;
        a = a->next;
    }
    return (minim);
    
}

void	stackiter(void (*f)(t_stackelem **, t_stackelem **),
    t_stackelem **a, t_stackelem **b, char *str)
{

    f(a, b);
    write(1, str, ft_strlen(str));
}

void sort_three(t_stackelem **a, t_stackelem **b)
{
    t_elem elem;

    elem.first = (*a)->data;
    elem.second = (*a)->next->data;
    elem.third = (*a)->next->next->data;

    if (elem.first == stackmax(*a))
    {
        stackiter(ft_rotate, a, b, "ra\n");
        if (!is_sortded(*a))
            stackiter(ft_swap, a, b,"sa\n");
    }
    else if (elem.first == stackmin(*a))
    {
        stackiter(ft_reverse_rotate, a, b,"rra\n");
        stackiter(ft_swap, a, b, "sa\n");
    }
    else
    {
        if (elem.first < elem.third)
            stackiter(ft_swap, a, b,"sa\n");
        else
            stackiter(ft_reverse_rotate, a, b,"rra\n");
    }
}

void sort_five(t_stackelem **a, t_stackelem **b)
{ 
    t_stackelem *ptr;
    int         *tmp;
    int         i;
    int         min;

    ptr = *a;
    tmp = malloc(4 * sizeof(int));
    min = stackmin(*a);
    i = -1;
    while (ptr)
    {
        if (ptr->data != min)
           tmp[i] = ptr->data;
        ptr = ptr->next;
    }
    stackiter(ft_push, b, a, "pb\n");
    stackiter(ft_push, b, a, "pb\n");
    sort_three(a, b);
    //1 2 3|1 2 4|1 2 5|1 3 4|1 3 5|1 4 5;
    if ((*a)->data == stackmin(*a))
    {
        // 6 CASES
    }
    else { //2 3 4|2 3 5|2 4 5

    }
    //3 4 5
}

void push_swap(t_stackelem **a, t_stackelem **b, int len)
{
    if (!is_sortded(*a))
    {
        if (len == 2)
            stackiter(ft_swap, a, b, "sa\n");
        if (len == 3) // 2 instructions
            sort_three(a, b);
        if (len == 5) // 12 instructions
        {
        }
    }
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
        push_swap(&a, &b, argc - 1);
        // write(1, "stack a => ", 11);
        // print_stack(a);
        // write(1, "stack b => ", 11);
        // print_stack(b);
    }
    return 0;
}