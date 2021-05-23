#include "push_swap.h"

int	get_middle(t_stackelem	*a, int	len)
{
	int	mid;
	int	*arr;
	int	i;
	int	*sorted_arr;

	if (len == 1)
		return (a->data);
	if (len == 2)
	{
		if (a->data < a->next->data)
			return (a->data);
		return (a->next->data);
	}
	i = 0;
	arr = copystack_arr(a, len);
	sorted_arr = quiq_sort(arr, 0, len - 1);
	mid = sorted_arr[len / 2];
	free(arr);
	return (mid);
}

int	get_max_of_chunk(t_stackelem *a, int	len, int	chunk_len)
{
	int	max_of_chunk;
	int	*arr;
	int	i;
	int	*sorted_arr;

	if (len == 1)
		return (a->data);
	if (len == 2)
	{
		if (a->data > a->next->data)
			return (a->data);
		return (a->next->data);
	}
	i = 0;
	arr = copystack_arr(a, len);
	sorted_arr = quiq_sort(arr, 0, len - 1);
	max_of_chunk = sorted_arr[chunk_len];
	free(arr);
	return (max_of_chunk);
}

int	get_min_indexes(t_stackelem *a, int	 mid, int	 len)
{
	int	index1;
	int	index2;
	int	*arr;
	int	i;

	arr = copystack_arr(a, len);
	index1 = 0;
	index2 = 0;
	i = -1;
	while (arr[++i] >= mid)
		index1++;
	i = 0;
	while (arr[len - i - 1] >= mid)
	{
		index2++;
		i++;
	}
	free(arr);
	if (index1 <= index2)
		return (index1);
	return (len - i - 1);
}

int	get_len(t_stackelem	*b, int	first, int	last)
{
	int	len;
	int	index_f;
	int	index_l;

	len = 0;
	index_f = stackindex(b, first);
	index_l = stackindex(b, last);
	len = abs(index_l - index_f);
	return (len + 1);
}

int	is_reverse_sorted(t_stackelem *head, int	len)
{
	while (len > 1)
	{
		if (head->data < head->next->data)
			return (0);
		head = head->next;
		len--;
	}
	return (1);
}
