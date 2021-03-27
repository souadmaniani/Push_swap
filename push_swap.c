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


void sort_three(t_stackelem *a)
{
    int first;
    int second;
    int third;

    first = a->data;
    second = a->next->data;
    third = a->next->next->data;

    if (first == stackmax(a))
    {
        ft_rotate(&a);
        write(1, "ra\n", 3);
        if (!is_sortded(a))
        {
            ft_swap(a);
            write(1, "sa\n", 3);
        }
    }
    else if (first == stackmin(a))
    {
        ft_reverse_rotate(&a);
        ft_swap(a);
        write(1, "rra\n", 4);
        write(1, "sa\n", 3);
    }
    else
    {
       if (first < third)
       {
            ft_swap(a);
            write(1, "sa\n", 3);
       }
       else
       {
           ft_reverse_rotate(&a);
           write(1, "rra\n", 4);
       }
       
    }
    

}

void push_swap(t_stackelem *a, t_stackelem *b, int len)
{
    if (len == 2 && !is_sortded(a))
    {
        ft_swap(a);
        write(1, "sa\n", 3);
    }
    // for len = 3 no more then 2 actions
    if (len == 3 && !is_sortded(a))
    {
        sort_three(a);
        // 5 cases
        //  2 1 4 sa
        //  2 4 1 rra
    }
    // for len = 5 no more then 12 actions
    else if (len <= 5)
    {

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
        push_swap(a, b, argc - 1);
        // write(1, "stack a => ", 11);
        // print_stack(a);
        // write(1, "stack b => ", 11);
        // print_stack(b);
    }
    return 0;
}