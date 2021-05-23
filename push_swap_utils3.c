#include "push_swap.h"

int	sort_part_case1(t_stackelem **a, t_stackelem **b,
		int	min_indx, int	max_indx)
{
	int	j;
	int	index;

	j = -1;
	if (min_indx < max_indx)
		index = min_indx;
	else
		index = max_indx;
	while (++j < index)
		stackiter(ft_rotate, b, a, "rb\n");
	if (index == min_indx)
		j = -2;
	return (j);
}

int	sort_part_case2(t_stackelem **a, t_stackelem **b, int	len)
{
	int	j;
	int	index;
	int	min_indx;
	int	max_indx;

	j = -1;
	min_indx = stackmin_index(*b);
	max_indx = stackmax_index(*b);
	if (min_indx > max_indx)
		index = min_indx;
	else
		index = max_indx;
	if (index == min_indx)
		j = -2;
	while (index < len)
	{
		stackiter(ft_reverse_rotate, b, a, "rrb\n");
		index++;
	}
	return (j);
}

int	sort_part_case3(t_stackelem **a, t_stackelem **b, int	len)
{
	int	j;
	int	index;
	int	min_indx;
	int	max_indx;

	j = -1;
	min_indx = stackmin_index(*b);
	max_indx = stackmax_index(*b);
	if (min_indx <= len - 1 - max_indx)
	{
		index = min_indx;
		while (++j < index)
			stackiter(ft_rotate, b, a, "rb\n");
		j = -2;
	}
	else
	{
		index = max_indx;
		while (index < len)
		{
			stackiter(ft_reverse_rotate, b, a, "rrb\n");
			index++;
		}
	}
	return (j);
}

int	sort_part_case4(t_stackelem **a, t_stackelem **b, int	len)
{
	int	j;
	int	index;
	int	min_indx;
	int	max_indx;

	j = -1;
	min_indx = stackmin_index(*b);
	max_indx = stackmax_index(*b);
	if (max_indx <= len - 1 - min_indx)
	{
		index = max_indx;
		while (++j < index)
			stackiter(ft_rotate, b, a, "rb\n");
	}
	else
	{
		index = min_indx;
		while (index < len)
		{
			stackiter(ft_reverse_rotate, b, a, "rrb\n");
			index++;
		}
		j = -2;
	}
	return (j);
}

void	sort_part(t_stackelem **a, t_stackelem **b, int	len)
{
	int	mid;
	int	j;

	while (*b)
	{
		len = stacksize(*b);
		mid = len / 2;
		j = -1;
		if (stackmin_index(*b) < mid && stackmax_index(*b) < mid)
			j = sort_part_case1(a, b, stackmin_index(*b), stackmax_index(*b));
		else
		{
			if (stackmin_index(*b) >= mid && stackmax_index(*b) >= mid)
				j = sort_part_case2(a, b, len);
			else if (stackmin_index(*b) < mid && stackmax_index(*b) >= mid)
				j = sort_part_case3(a, b, len);
			else if (stackmax_index(*b) < mid && stackmin_index(*b) >= mid)
				j = sort_part_case4(a, b, len);
		}
		stackiter(ft_push, a, b, "pa\n");
		if (j == -2)
			stackiter(ft_rotate, a, b, "ra\n");
	}
}
