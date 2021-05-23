#include "push_swap.h"

void	sort_three(t_stackelem **a, t_stackelem **b)
{
	int	last;

	last = stacklast(*a)->data;
	if ((*a)->data == stackmax(*a))
	{
		stackiter(ft_rotate, a, b, "ra\n");
		if (!is_sorted(*a))
			stackiter(ft_swap, a, b, "sa\n");
	}
	else if ((*a)->data == stackmin(*a))
	{
		stackiter(ft_reverse_rotate, a, b, "rra\n");
		stackiter(ft_swap, a, b, "sa\n");
	}
	else
	{
		if ((*a)->data < last)
			stackiter(ft_swap, a, b, "sa\n");
		else
			stackiter(ft_reverse_rotate, a, b, "rra\n");
	}
}

void	sort_five(t_stackelem **a, t_stackelem **b)
{
	int	i;
	int	len;
	int	index;
	int	j;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		len = stacksize(*a);
		index = stackmin_index(*a);
		if (index < (int)(len / 2))
			while (++j < index)
				stackiter(ft_rotate, a, b, "ra\n");
		else
		{
			while (index++ < len)
				stackiter(ft_reverse_rotate, a, b, "rra\n");
		}
		stackiter(ft_push, b, a, "pb\n");
	}
	if (!is_sorted(*a))
		sort_three(a, b);
	stackiter(ft_push, a, b, "pa\n");
	stackiter(ft_push, a, b, "pa\n");
}

void	sort_hundred(t_stackelem **a, t_stackelem **b, int half)
{
	int	len;
	int	middle;

	len = stacksize(*a);
	middle = get_middle(*a, len);
	push_all_min(a, b, middle, half);
	sort_part(a, b, len);
	while ((*a)->data < middle)
		stackiter(ft_rotate, a, b, "ra\n");
	while ((*a)->data >= middle)
		stackiter(ft_push, b, a, "pb\n");
	sort_part(a, b, len);
	while ((*a)->data >= middle)
		stackiter(ft_rotate, a, b, "ra\n");
}

void	push_swap(t_stackelem **a, t_stackelem **b, int len)
{
	int	chunk_len;

	if (!is_sorted(*a))
	{
		if (len == 2)
			stackiter(ft_swap, a, b, "sa\n");
		else if (len == 3)
			sort_three(a, b);
		else if (len == 5)
			sort_five(a, b);
		else if (len <= 100)
			sort_hundred(a, b, stacksize(*a) / 2);
		else
		{
			chunk_len = stacksize(*a) / 11;
			sort_five_hundred(a, b, chunk_len, 0);
		}
	}
}

int	main(int argc, char *argv[])
{
	int			ret;
	t_stackelem	*a;
	t_stackelem	*b;
	char		**args;
	int			len;

	if (argc >= 2)
	{
		b = NULL;
		if (argc == 2)
		{
			args = ft_split(argv[1], ' ', &len);
			ret = create_stack(&a, args);
			argc = len + 1;
			free_tab(args);
		}
		else
			ret = create_stack(&a, argv + 1);
		if (ret == -1)
			return (-1);
		push_swap(&a, &b, argc - 1);
		free_stack(a);
	}
	return (0);
}
