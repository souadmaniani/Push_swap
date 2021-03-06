#include "push_swap.h"

void	ft_swap(t_stackelem **head, t_stackelem **b)
{
	int	tmp;

	(void)b;
	if (*head && (*head)->next)
	{
		tmp = (*head)->data;
		(*head)->data = (*head)->next->data;
		(*head)->next->data = tmp;
	}
}

void	ft_push(t_stackelem **dest, t_stackelem **src)
{
	int			data;
	t_stackelem	*new;

	if (*src)
	{
		data = stackdelete_head(src);
		new = stacknew(data);
		stackadd_front(dest, new);
	}
}

void	ft_rotate(t_stackelem **head, t_stackelem **b)
{
	int			data;
	t_stackelem	*new;

	(void)b;
	if (*head && (*head)->next)
	{
		data = stackdelete_head(head);
		new = stacknew(data);
		stackadd_back(head, new);
	}
}

void	ft_reverse_rotate(t_stackelem **head, t_stackelem **b)
{
	int			data;
	t_stackelem	*new;

	(void)b;
	if (*head && (*head)->next)
	{
		data = stackdelete_last(head);
		new = stacknew(data);
		stackadd_front(head, new);
	}
}
