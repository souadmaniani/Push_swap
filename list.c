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

void	stackadd_front(t_stackelem **head, t_stackelem *new)
{
	new->next = *head;
	*head = new;
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

int	stackdelete_head(t_stackelem **head)
{
	t_stackelem *tmp;
	int			data;

	tmp = NULL;
	if ((*head)->next)
		tmp = (*head)->next;
	data = (*head)->data;
	free(*head);
	*head = tmp;
	return (data);
}

int	stackdelete_last(t_stackelem **head)
{
	int			data;
	t_stackelem *last;
	t_stackelem *tmp;

	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	data = tmp->next->data;
	last = tmp;
	free(tmp->next);
	last->next = NULL;
	return (data);
}
