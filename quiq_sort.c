#include "./push_swap.h"

void	ft_swap_q(int *a, int *b)
{
	int	k;

	k = *a;
	*a = *b;
	*b = k;
}

int	partition(int *arr, int l, int h)
{
	int	pivot;
	int	i;
	int	j;

	i = l;
	j = h;
	pivot = arr[l];
	while (i < j)
	{
		while (arr[i] <= pivot && i < h)
			i++;
		while (arr[j] > pivot && j > l)
			j--;
		if (i < j)
			ft_swap_q(&arr[i], &arr[j]);
	}
	ft_swap_q(&arr[l], &arr[j]);
	return (j);
}

int	*quiq_sort(int *arr, int l, int h)
{
	int	j;

	if (l < h)
	{
		j = partition(arr, l, h);
		quiq_sort(arr, l, j);
		quiq_sort(arr, j + 1, h);
	}
	return (arr);
}
