#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    int i = 1, value, hole;

    while (i < n)
    {
        value = arr[i];
        hole = i;
        while (hole >= 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole = hole - 1;
        }
        arr[hole] = value;
        i++;
    }
}

int main(int argc, char*argv[])
{
    int i = -1;
    int table[7] = {9, 8, 10, 3, 5, 2, 1};
    insertion_sort(table, 7);
    while (++i < 7)
        printf ("%d ", table[i]);
    printf("\n");
}