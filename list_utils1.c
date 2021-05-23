#include "push_swap.h"

int	stacksize(t_stackelem *head)
{
	int	len;

	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

t_stackelem	*stacklast(t_stackelem *head)
{
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (head);
}

int	stackmax(t_stackelem *a)
{
	int	maxim;

	maxim = a->data;
	a = a->next;
	while (a)
	{
		if (a->data > maxim)
			maxim = a->data;
		a = a->next;
	}
	return (maxim);
}

int	stackmin(t_stackelem *a)
{
	int	minim;

	minim = a->data;
	a = a->next;
	while (a)
	{
		if (a->data < minim)
			minim = a->data;
		a = a->next;
	}
	return (minim);
}

void	stackiter(void (*f)(t_stackelem **, t_stackelem **),
			t_stackelem **a, t_stackelem **b, char *str)
{
	f(a, b);
	write(1, str, ft_strlen(str));
}
