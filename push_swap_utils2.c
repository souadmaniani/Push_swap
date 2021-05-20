#include "push_swap.h"

void elem_order(t_stackelem *a, t_elem *elem)
{
	t_stackelem *ptr;
	t_stackelem *copy = NULL;

	
	copy = stackcopy(&copy, a);
    elem->st = stackmin(a);
    elem->fth = stackmax(a);
    ptr = stackchr(copy, elem->st);
    ptr->data = INT_MAX;
    ptr = stackchr(copy, elem->fth);
    ptr->data = INT_MAX;
    elem->nd = stackmin(copy);
    ptr = stackchr(copy, elem->nd);
    ptr->data = INT_MAX;
    elem->rd = stackmin(copy);
    ptr = stackchr(copy, elem->rd);
    ptr->data = INT_MAX;
    elem->rth = stackmin(copy);
}

void print_stacks(char *str, t_stackelem *a, t_stackelem *b)
{
        write(1, str, ft_strlen(str));
    	write(1, "      stack a => ", 17);
        print_stack(a);
        write(1, "\n", 1);
        write(1, "      stack b => ", 17);
        print_stack(b);
        write(1, "\n", 1);
}

int *copystack_arr(t_stackelem *a, int len)
{
    int *arr;
    int i;

    i = 0;
    arr = malloc(sizeof(int) * (len));
    while (len)
    {
        arr[i++] = a->data;
        a = a->next;
        len--;
        // printf(" i= %d %d\n",i-1, arr[i - 1]);
        // fflush(stdout);
    }
    return (arr);
}

int get_middle(t_stackelem *a, int len)
{
    int mid;
    int *arr;
    int i;
    int *sorted_arr;

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
    mid = sorted_arr[len/2];
    return (mid);
}
int get_max_of_chunk(t_stackelem *a, int len)
{
    int max_of_chunk;
    int *arr;
    int i;
    int *sorted_arr;

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
    max_of_chunk = sorted_arr[45];
    return (max_of_chunk);
}

int get_min_indexes(t_stackelem *a, int mid, int len)
{
    int index1;
    int index2;
    int *arr;
    int i;
    int j;

    arr = copystack_arr(a, len);
    index1 = 0;
    index2 = 0;
    i = -1;
    // get_min_from_top
    while (arr[++i] >= mid)
        index1++;
    // get_min_from_bottom
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

int get_index(t_stackelem *a, int middle)
{
    int index;
    while (a->data > middle)
    {
       a = a->next;
       index++;
    }
    return (index);
}

int get_max_indexes(t_stackelem *a, int mid, int len)
{
    int index1;
    int index2;
    int *arr;
    int i;
    int j;

    arr = copystack_arr(a, len);
    index1 = 0;
    index2 = 0;
    i = -1;
    // get_max_from_top
    while (arr[++i] <= mid)
        index1++;
    // get_max_from_bottom
    i = 0;
    while (arr[len - i - 1] <= mid)
    {
        index2++;
        i++;
    }
    // free(arr);
    if (index1 <= index2)
        return (index1);
    return (len - i - 1);
}

int get_len(t_stackelem *b, int first, int last)
{
    int len;
    int index_f;
    int index_l;

    len = 0;
    // segfault hna (chi haja ktkhrb9 o last kaywalli f a o kanwaaliw f NULL)
    // printf("first: %d last: %d\n", first, last);
    // fflush(stdout);
    index_f = stackindex(b, first);
    index_l = stackindex(b, last);
    len = abs(index_l - index_f);
    // printf("\nlen = %d\n", len);
    return (len + 1);
}

int is_reverse_sorted(t_stackelem *head, int len)
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
