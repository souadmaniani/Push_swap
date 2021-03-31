#include "../push_swap.h"

t_stackelem *stackchr(t_stackelem *a, int data)
{
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
    t_stackelem *new;

    i = -1;
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