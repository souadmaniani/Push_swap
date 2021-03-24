#include "push_swap.h"
// sa sb ss pa pb ra rb rr rra rrb rrr
void swap(t_stackelem *head)
{
    int tmp;
    
    if (head && head->next)
    {
        tmp = head->data;
        head->data = head->next->data;
        head->next->data = tmp;
    }
}

void push(t_stackelem **dest, t_stackelem **src)
{
    int data;
    t_stackelem *new;

    if (*src)
    {
        data = stackdelete_head(src);
        new = stacknew(data);
        stackadd_front(dest, new);
    }
}

void rotate(t_stackelem **head)
{
    int data;
    t_stackelem *new;

    if (*head && (*head)->next)
    {
        data = stackdelete_head(head);
        new = stacknew(data);
        stackadd_back(head, new);
    }
}

void reverse_rotate(t_stackelem **head)
{
    int data;
    t_stackelem *new;

    if (*head && (*head)->next)
    {
        data = stackdelete_last(head);
        new = stacknew(data);
        stackadd_front(head, new);
    } 
}