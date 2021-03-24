#include "push_swap.h"

// check Error (not integers) (overflow) (duplicate) (an exist instruction (no space))
// sa=> swap(a or b)
// ss=> swap(a) && swap(b)
// pa=> push(a or b)
// ra=> rotate(a or b)
// rr=> rotate(a) && rotate(b)
// rra=> reverse_rotate(a or b)
// rrr=> reverse_rotate(a) && reverse_rotate(b)
void swap(t_stackelem **head)
{
    int tmp;
    tmp = (*head)->data;
    (*head)->data = (*head)->next->data;
    (*head)->next->data = tmp;
}

int    create_stack(t_stackelem **head, char **argv)
{
    t_stackelem *new;
    int i;

    i = 0;
    *head = NULL;
    while (argv[++i])
    {
        new = stacknew(ft_atoi(argv[i]));
        if (!new)
            return (-1);
        stackadd_back(head, new);
    }
    return (0);
}
// PRINT STACK
void print_stack(t_stackelem *head)
{

    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int ret;
    t_stackelem *head;

    ret = create_stack(&head, argv);
    if(ret == -1)
        return(-1);
    print_stack(head);
    swap(&head);
    print_stack(head);
    return 0;
}