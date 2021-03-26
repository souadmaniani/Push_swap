#include "push_swap.h"

void ft_swap(int *a, int *b)
{
    int k;

    k = *a;
    *a = *b;
    *a = k;
}
int partition(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= h)
            i++;
        while (arr[j] > pivot && j >= l)
            j--;
        if (i < j)
            ft_swap(&arr[i], &arr[j]);
    }
    ft_swap(&arr[l], &arr[j]);
    return (j);
}

int *quiq_sort(int *arr, int l, int h)
{
    int j;

    if (l < h)
    {
        j = partition(arr, l, h);
        // quiq_sort(arr, l, j);
        // quiq_sort(arr, j + 1, h);
    }
    return (arr);
}

int main(int argc, char*argv[])
{
    int i = -1;
    int table[7] = {9, 8, 10, 3, 5, 2, 1};
    int *sorted_table = quiq_sort(table, 0, 6);
    while (++i < 7)
        printf ("%d ", table[i]);
    printf("\n");
}