#include "push_swap.h"

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

int stackmin_index(t_stackelem *a)
{
    int min;
    int index;

    min =  stackmin(a);
    index = 0;
    while (a)
    {
        if (a->data == min)
            return (index);
        index++;
        a = a->next;
    }
    return (index);
}

int stackmax_index(t_stackelem *a)
{
    int max;
    int index;

    max =  stackmax(a);
    index = 0;
    while (a)
    {
        if (a->data == max)
            return (index);
        index++;
        a = a->next;
    }
    return (index);
}
void  stackdelete_elem(t_stackelem **head, t_stackelem *elem)
{
    t_stackelem *tmp;
    t_stackelem *next;
    t_stackelem *prev;

    tmp = *head;
    if (elem->data == tmp->data)
        stackdelete_head(head);
    while (tmp->next)
    {
        prev = tmp;
        tmp = tmp->next;
        next = tmp->next;
        if (tmp && tmp->data == elem->data)
        {
            prev->next = next;
            free(tmp);
            break ;
        }
    }
}

t_stackelem *stackelem_byindex(t_stackelem **a, int index)
{
    t_stackelem *tmp;
    int i;

    tmp = *a;
    i = -1;
    while (++i < index)
        tmp = tmp->next;
    return (tmp);
}

int stackindex(t_stackelem *a, int value)
{
    int index;

    index = 0;
    while (a->data != value)
    {
        a = a->next;
        index++;
    }
    return (index);
}
