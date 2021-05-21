#include "push_swap.h"

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
