#include "push_swap.h"

t_stackelem	*stacknew(int data)
{
	t_stackelem *new;

    new = malloc(sizeof(t_stackelem));
    if (!new)
        return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}

int	stacksize(t_stackelem *head)
{
	int len;

	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

void	stackadd_front(t_stackelem **head, t_stackelem *new)
{
	new->next = *head;
	*head = new;
}

t_stackelem	*stacklast(t_stackelem *head)
{
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (head);
}

void	stackadd_back(t_stackelem **head, t_stackelem *new)
{
	t_stackelem *last;

	if(!*head)
		stackadd_front(head, new);
	last = stacklast(*head);
	last->next = new;
	new->next = NULL;
}

