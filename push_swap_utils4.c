#include "push_swap.h"

void	push_all_min(t_stackelem **a, t_stackelem **b, int middle, int half)
{
	int	i;
	int	len;
	int	index;
	int	j;
	int	mid;

	i = -1;
	while (++i < half)
	{
		len = stacksize(*a);
		mid = len / 2;
		index = get_min_indexes(*a, middle, len);
		j = -1;
		if (index < mid)
			while (++j < index)
				stackiter(ft_rotate, a, b, "ra\n");
		else
		{
			while (index++ < len)
				stackiter(ft_reverse_rotate, a, b, "rra\n");
		}
		stackiter(ft_push, b, a, "pb\n");
	}
}

void	analyse_number(t_stackelem **a, t_stackelem **b, int *len)
{
	int	index;
	int	half;
	int	max_chunk;

	index = stackmax_index(*b);
	half = stacksize(*b) / 2;
	max_chunk = stackmax(*b);
	if (index > half)
		while (index++ < stacksize(*b))
			stackiter(ft_reverse_rotate, b, a, "rrb\n");
	else if ((*b)->data < max_chunk)
		stackiter(ft_rotate, b, a, "rb\n");
	else if ((*b)->data == max_chunk)
	{
		stackiter(ft_push, a, b, "pa\n");
		(*len)--;
	}
}

void	sort_chunks(t_stackelem **a, t_stackelem **b, int k, int arr[100][3])
{
	int	len;

	while (k >= 0)
	{
		len = stacksize(*b);
		if (is_reverse_sorted(*b, len))
			while (*b)
				stackiter(ft_push, a, b, "pa\n");
		else
		{
			len = arr[k][2];
			while (len)
				analyse_number(a, b, &len);
			k--;
		}
	}
}

void	push_chunks(t_stackelem **a, t_stackelem **b, int max_chunk)
{
	int	len;
	int	mid;
	int	index;
	int	j;

	len = stacksize(*a);
	mid = len / 2;
	index = get_min_indexes(*a, max_chunk, len);
	j = -1;
	if (index < mid)
		while (++j < index)
			stackiter(ft_rotate, a, b, "ra\n");
	else
	{
		while (index++ < len)
			stackiter(ft_reverse_rotate, a, b, "rra\n");
	}
	stackiter(ft_push, b, a, "pb\n");
}

void	sort_five_hundred(t_stackelem **a, t_stackelem **b,
			int chunk_len, int k)
{
	int	i;
	int	max_chunk;
	int	arr[100][3];

	while (stacksize(*a))
	{
		i = -1;
		max_chunk = get_max_of_chunk(*a, stacksize(*a), chunk_len);
		while (++i < chunk_len)
		{
			push_chunks(a, b, max_chunk);
			if (i == 0)
				arr[k][1] = (*b)->data;
		}
		if (!is_sorted(*a) && stacksize(*a) < chunk_len)
			while (*a)
				stackiter(ft_push, b, a, "pb\n");
		arr[k][0] = (*b)->data;
		arr[k][2] = get_len(*b, arr[k][0], arr[k][1]);
		k++;
		if (*a && (is_sorted(*a) || stacksize(*a) == 1))
			break ;
	}
	k--;
	sort_chunks(a, b, k, arr);
}
