#include <stdio.h>
#include <stdlib.h>

int *copy_array(int arr[], int start, int end)
{
    int i;
    int *a;
    
    i = 0;
    a = malloc((end - start) * sizeof(int));
    while (start < end)
    {
        a[i] = arr[start];
        start++;
        i++;
    }
    return (a);
}

void merge(int arr[], int l, int mid, int h)
{
    int *a, *b;
    int i = 0, j = 0, k = 0, n;

    n = h - mid;
    a = copy_array(arr, l, mid);
    b = copy_array(arr, mid, h);
    while (i < mid && j < n)
    {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }
    while (i < mid)
        arr[k++] = a[i++];
    while (j < n)
        arr[k++] = b[j++];
        
}

void merge_sort(int arr[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, h);
        merge(arr, l , mid, h);
    }
}

int main()
{
    int i = 0;
    int arr [] ={38, 37, 99 , 8};
    merge_sort(arr, 0, 4);
    i = 0;
    while (i < 4)
    {
       printf("%d ", arr[i]);
       i++;
    }
    return 0;
}