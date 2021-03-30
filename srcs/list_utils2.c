#include "../push_swap.h"

t_stackelem *stack_search(t_stackelem *a, int data)
{
    t_stackelem *tmp;

    while (a)
    {
        if (a->data == data)
            return a;
        a = a->next;
    }
     return 0;
}


t_stackelem *stackcopy(t_stackelem **dest, t_stackelem *src)
{
    int         len;
    int         i;
    t_stackelem *tmp;
    t_stackelem *new;

    i = -1;
    tmp = src;
    while (tmp)
    {
        new = stacknew(tmp->data);
        if (!new)
            return (0);
        stackadd_back(dest, new);
        tmp = tmp->next;
    }
    return (*dest);
}