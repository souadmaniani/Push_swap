#include "../push_swap.h"
#include <limits.h>

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
// int *getlastLargestHalf(t_stackelem *a)
// {
//     int         *tmp;
//     int         max;
//     int         middle;
//     int         *arr;
//     int         i;
//     t_stackelem *copy = NULL;

//     middle = stacksize(a) / 2;
//     if (stacksize(a) % 2 != 0)
//         middle = middle + 1;
//     i = 0;
//     arr = malloc(middle * sizeof(int));
//     tmp = malloc(middle * sizeof(int));
//     copy = stackcopyHalf(&copy, a);
//     middle = stacksize(copy);
//     while (i < middle)
//     {
//         max = stackmax(copy);
//         tmp[i++] = max;
//         copy = stackchange_value(copy, max);
//     }
//     i = 0;
//     while (middle--)
//     {
//         arr[i] = tmp[i];
//         i++;
//     }
//     return (arr);
// }

// t_stackelem  *stackchange_value(t_stackelem *a, int value)
// {
//     t_stackelem *tmp;
//     t_stackelem *copy = NULL;
//     copy = stackcopy(&copy, a);
//     tmp = copy;
//     while (tmp->data != value)
//        tmp= tmp->next;
//     tmp->data = INT_MIN;
//     return (copy);
    
// }

// int *getLargestHalf(t_stackelem *a)
// {
//     int         *tmp;
//     int         max;
//     int         middle;
//     int         *arr;
//     int         i;
//     t_stackelem *copy = NULL;

//     middle = stacksize(a) / 2;
//     i = 0;
//     arr = malloc(middle * sizeof(int));
//     tmp = malloc(middle * sizeof(int));
//     copy = stackcopy(&copy, a);
//     while (i < middle)
//     {
//         max = stackmax(copy);
//         tmp[i++] = max;
//         copy = stackchange_value(copy, max);
//     }
//     i = 0;
//     while (middle--)
//     {
//         arr[i] = tmp[middle];
//         i++;
//     }
//     return (arr);
// }

// t_stackelem *stackcopyHalf(t_stackelem **dest, t_stackelem *src)
// {
//     int         mid;
//     int         i;
//     t_stackelem *new;

//     i = -1;
//     mid = stacksize(src) / 2;
//     while (++i < mid)
//         src = src->next;
//     while (src)
//     {
//         new = stacknew(src->data);
//         if (!new)
//             return (0);
//         stackadd_back(dest, new);
//         src = src->next;
//     }
//     return (*dest);
// }
