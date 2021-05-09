#include "push_swap.h"
// LESS THAN 1100: FOR 100 NUMBER
// LESS THAN 8500: FOR 500 NUMBER

void sort_three(t_stackelem **a, t_stackelem **b)
{
    t_elem elem;

    elem.st = (*a)->data;
    elem.nd = (*a)->next->data;
    elem.rd = (*a)->next->next->data;

    if (elem.st == stackmax(*a))
    {
        stackiter(ft_rotate, a, b, "ra\n");
        if (!is_sorted(*a))
            stackiter(ft_swap, a, b,"sa\n");
    }
    else if (elem.st == stackmin(*a))
    {
        stackiter(ft_reverse_rotate, a, b,"rra\n");
        stackiter(ft_swap, a, b, "sa\n");
    }
    else
    {
        if (elem.st < elem.rd)
            stackiter(ft_swap, a, b,"sa\n");
        else
            stackiter(ft_reverse_rotate, a, b,"rra\n");
    }
}

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

void sort_five(t_stackelem **a, t_stackelem **b)
{ 
    t_stackelem ptr;
    int         i;
    int         min;
    t_elem      elem;

    // elem_order(*a, &elem);
    elem_order(*a, &elem);
    stackiter(ft_push, b, a, "pb\n");
    stackiter(ft_push, b, a, "pb\n");
    if (!is_sorted(*a))
        sort_three(a, b);
	if ((*a)->data == elem.rd)
    {// 3 4 5
        stackiter(ft_push, a, b, "pa\n");
        stackiter(ft_push, a, b, "pa\n");
        if (!is_sorted(*a))
            stackiter(ft_swap, a, b, "sa\n");
    }
	else if ((*a)->data == elem.nd)
    { // 2 3 4-> [1,5] | 2 3 5-> [1,4] | 2 4 5-> [1,3]
        if ((*b)->data == elem.fth || (*b)->next->data == elem.fth)
		{
			stackiter(ft_push,a, b, "pa\n");
			if ((*b)->data == elem.fth)
			{
				stackiter(ft_push, a, b, "pa\n");
				stackiter(ft_rotate, a, b, "ra\n");
			}
			else
			{
				stackiter(ft_rotate, a, b, "ra\n");
				stackiter(ft_push, a, b, "pa\n");
			}
		}
		else if ((*b)->data == elem.rd || (*b)->next->data == elem.rd)
		{
			if ((*b)->next->data == elem.rd)
				stackiter(ft_swap, b, a, "sb\n");
			stackiter(ft_push, a, b, "pa\n");
			stackiter(ft_swap, a, b, "sa\n");
			stackiter(ft_push, a, b, "pa\n");
		}
		else
		{
			if ((*b)->data == elem.st)
				stackiter(ft_swap, b, a, "sb\n");
			stackiter(ft_reverse_rotate, a, b, "rra\n");
			stackiter(ft_push, a, b, "pa\n");
			stackiter(ft_rotate, a, b, "ra\n");
			stackiter(ft_rotate, a, b, "ra\n");
			stackiter(ft_push, a, b, "pa\n");
		}
    }
    else if ((*a)->data == elem.st)
    { // 1 2 3 | 1 2 4 | 1 2 5 | 1 3 4 | 1 3 5 | 1 4 5;
        if (stackchr(*b, elem.fth) && stackchr(*b, elem.rth))
        {
            if (is_sorted(*b))
                stackiter(ft_swap, b, a, "sb\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_rotate, a, b, "ra\n");
			stackiter(ft_rotate, a, b, "ra\n");
        }
        else if (stackchr(*b, elem.fth) && stackchr(*b, elem.rd))
        {
            if (!is_sorted(*b))
                stackiter(ft_swap, b, a, "sb\n");
            stackiter(ft_push, a, b, "rra\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_rotate, a, b, "ra\n");
            stackiter(ft_rotate, a, b, "ra\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_rotate, a, b, "ra\n");
        }
        else if (stackchr(*b, elem.rth) && stackchr(*b, elem.rd))
        {
            if ((*b)->data == elem.rth)
            {
                stackiter(ft_push, a, b, "rra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_rotate, a, b, "ra\n");
            }
            else
            {
                stackiter(ft_push, a, b, "rra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_rotate, a, b, "ra\n");
            }
        }
        else if (stackchr(*b, elem.fth) && stackchr(*b, elem.nd))
        {
            if ((*b)->data == elem.nd)
            {
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_swap, a, b, "sa\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
            }
            else
            {
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_swap, a, b, "sa\n");
            }
        }
        else if (stackchr(*b, elem.rth) && stackchr(*b, elem.nd))
        {   if ((*b)->data == elem.rth)
            {
                stackiter(ft_push, a, b, "rra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_swap, a, b, "sa\n");
            }
            else
            {   stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_swap, a, b, "sa\n");
                stackiter(ft_push, a, b, "rra\n");
                stackiter(ft_push, a, b, "pa\n");
                stackiter(ft_rotate, a, b, "ra\n");
                stackiter(ft_rotate, a, b, "ra\n");
            }
        }
        else if (stackchr(*b, elem.rd) && stackchr(*b, elem.nd))
        {
            if (is_sorted(*b))
                stackiter(ft_swap, b, a, "sb\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_swap, a, b, "sa\n");
            stackiter(ft_push, a, b, "pa\n");
            stackiter(ft_swap, a, b, "sa\n");
        }
    }
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

// 	stackiter(ft_rotate, a, b, "ra\n");
// ft_rotate(a, b);
// print_stacks("etat initial: \n", *a, *b);

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
        return (a->next->data);
    i = 0;
    arr = copystack_arr(a, len);
    sorted_arr = quiq_sort(arr, 0, len - 1);
    mid = sorted_arr[len/2];
    return (mid);
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
    if (index1 < index2)
        return (index1);
    return (len - i - 1);
}

int sort_part(t_stackelem **a, t_stackelem **b, int len)
{
    int mid;
    int j;
    int min_indx;
    int max_indx;
    int index;
    int is_rotate;

    is_rotate = 0;
    while (*b)
    {
        len = stacksize(*b);
        mid = len / 2;
        j = -1;
        min_indx = stackmin_index(*b);
        max_indx = stackmax_index(*b);
        if (min_indx < mid && max_indx < mid)
        {
            index = (min_indx < max_indx) ? min_indx : max_indx;
            while (++j < index)
                stackiter(ft_rotate, b, a, "rb\n");
                // ft_rotate(b, a);
            if (index == min_indx)
                j = -2;
        }
        else
        {
            if (min_indx >= mid && max_indx >= mid)
            {
                index = (min_indx > max_indx) ? min_indx : max_indx;
                if (index == min_indx)
                    j = -2;
                while (index < len)
                {
                    stackiter(ft_reverse_rotate, b, a, "rrb\n");
                    // ft_reverse_rotate(b, a);
                    index++;
                }
            }
            else if  (min_indx < mid && max_indx >= mid)
            {
                if (min_indx <= len - 1 - max_indx)
                {
                    index = min_indx;
                    while (++j < index)
                        stackiter(ft_rotate, b, a, "rb\n");
                        // ft_rotate(b, a);
                    j = -2;
                }
                else
                {
                    index = max_indx;
                    while (index < len)
                    {
                        // ft_reverse_rotate(b, a);
                        stackiter(ft_reverse_rotate, b, a, "rrb\n");
                        index++;
                    }
                }
            }
            else if (max_indx < mid && min_indx >= mid)
            {
                if (max_indx <= len - 1 - min_indx)
                {
                    index = max_indx;
                    while (++j < index)
                        stackiter(ft_rotate, b, a, "rb\n");
                        // ft_rotate(b, a);
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
            }
        }
        stackiter(ft_push, a, b, "pa\n");
        if (j == -2)
        {
            stackiter(ft_rotate, a, b, "ra\n");
            is_rotate++;
        }
    }
    return (is_rotate);
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

    len = 0;
    // segfault hna (chi haja ktkhrb9 o last kaywalli f a o kanwaaliw f NULL)
    printf("first: %d last: %d\n", first, last);
    fflush(stdout);
    while (b->data != first)
        b = b->next;
    while (b->data != last)
   {
       len++;
       b = b->next;
   }
//    print_stack(a);
    return (len + 1);
}

void sort_hundrd(t_stackelem   **a, t_stackelem    **b, int    half)
{
    int			    index;
    int			    i;
    int             len;
    int             middle;
    int             mid;
    int             j;

	i = -1;
    len = stacksize(*a);
    middle = get_middle(*a, len);
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
    sort_part(a, b, len);
    while ((*a)->data < middle)
        stackiter(ft_rotate, a, b, "ra\n");
    while ((*a)->data >= middle)
        stackiter(ft_push, b, a, "pb\n");
    sort_part(a, b, len);
    while ((*a)->data >= middle)
        stackiter(ft_rotate, a, b, "ra\n");
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

void print_nbr(char *str, int n)
{
    char *nbr;

    write(1, str, ft_strlen(str));
    nbr = ft_itoa(n);
    write(1, nbr, ft_strlen(nbr));
    write(1, "\n", 1);
}
void sort_five_h(t_stackelem   **a, t_stackelem    **b, int    half)
{
    int			    index;
    int			    i;
    int             len;
    int             middle;
    int             mid;
    int             j;
    int             is_rotate;
    int             k;
    int             arr[8][2];
    int             count;
    int             count2;
    int             count3;
    t_stackelem *tmp;
    k = 0;
    // 4 5 1 2 3 7 77 444 11 14
    while (stacksize(*a) > 2)
    {
        i = -1;
        len = stacksize(*a);
        middle = get_middle(*a, len);
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
            if (i == 0)
                arr[k][1] = (*b)->data;
        }
        half = stacksize(*a) / 2;
        arr[k][0] = (*b)->data;
        k++;
    }
    k--;
    if (!is_sorted(*a))
        stackiter(ft_swap, a, b, "sa\n");
    // 97 169 124 136 144 30 101 140 53 72 163 10 76 26 181 186 141 31 138 16 45 34 21 115 195 184 126 0 161 65 49 179 197 80 5 28 25 52 145 18 55 78 68 157 166 14 100 117 13 127 114 151 29 102 182 172 131 135 88 139 110 61 44 20 46 64 83 112 9 42 174 59 99 162 23 70 4 24 185 105 75 60 134 7 137 67 87 125 81 121 132 19 38 111 155 89 196 54 2 167 190 129 164 146 84 142 156 11 130 3 118 194 116 1 39 147 41 85 74 170 188 199 12 77 176 96 104 177 40 153 106 90 22 123 103 47 113 189 183 33 119 69 148 160 180 159 58 98 79 120 175 37 82 71 86 109 43 191 95 198 32 165 107 171 128 6 168 152 154 62 122 192 143 73 158 35 63 17 193 149 92 93 66 178 36 51 8 15 57 108 173 27 91 187 133 56 50 48 94 150
    while (*b)
    {
        len = stacksize(*b);
        if (is_reverse_sorted(*b, len))
        {
            while (*b)
                stackiter(ft_push, a, b, "pa\n");
        }
        else
        {
            i = -1;
            if (arr[k][1] == 97)
                print_stacks("stacks: \n", *a, *b);
            len = get_len(*b, arr[k][0], arr[k][1]);
            while (len)
            {
                middle = get_middle(*b, len);
                printf("middle: %d \n", middle);
                if (len == 1)
                {
                    stackiter(ft_push, a, b, "pa\n");
                    break ;
                }
                else if (len == 2)
                {
                    printf("count %d count2 %d count3 %d\n", count, count2, count3);
                    if ((*b)->data < (*b)->next->data)
                        stackiter(ft_swap, b, a, "sb\n");
                    if ((*b)->data == stackmax(*b))
                        stackiter(ft_push, a, b, "pa\n");
                    if ((*b)->data == stackmax(*b))
                        stackiter(ft_push, a, b, "pa\n");
                    break ;
                }
                mid = len / 2;
                if (len % 2 == 0)
                    mid--;
                // while mazal chi haja kbar man middle o mazal hna f chunk
                count = 0;
                count2 = 0;
                count3 = 0;
                j = 0;
                while (j < mid)
                {
                    if ((*b)->data > middle && (*b)->next->data > (*b)->data)
                    {
                        while ((*b)->data > middle && (*b)->next->data > (*b)->data)
                        {
                            stackiter(ft_rotate, b, a, "rb\n");
                            count2++;
                        }
                        stackiter(ft_push, a, b, "pa\n");
                        len--;
                        j++;
                        while (count2)
                        {
                            stackiter(ft_reverse_rotate, b, a, "rrb\n");
                            stackiter(ft_push, a, b, "pa\n");
                            len--;
                            j++;
                            count2--;
                        }
                    }
                    else if ((*b)->data <= middle)
                    {
                        printf("middle: %d count: %d\n", middle, count);
                        stackiter(ft_rotate, b, a, "rb\n");
                        count++;
                    }
                    else if ((*b)->data > middle && (*b)->data == stackmax(*b))
                    {
                        stackiter(ft_push, a, b, "pa\n");
                        len--;
                        j++;
                        if (count3 != 0)
                        {
                            count3 = count3 + count;
                            count = 0;
                            printf("(*a)->data: %d \n", (*a)->data);
                            while (count3)
                            {
                               printf("ITS ME \n");
                                stackiter(ft_reverse_rotate, b, a, "rrb\n");
                                count3--;
                            }
                            printf("(*b)->data: %d \n", (*b)->data);
                        }
                    }
                    else if ((*b)->data > middle && (*b)->data != stackmax(*b))
                    {
                        printf("count3: %d\n", count3);
                        stackiter(ft_rotate, b, a, "rb\n");
                        count3++;
                    }
                }
                print_stacks("chunk: \n", *a, *b);
                while (count)
                {
                    stackiter(ft_reverse_rotate, b, a, "rrb\n");
                    count--;
                }
            }
            k--;
        }
    }
    print_stacks("etat final: \n", *a, *b);
}

void push_swap(t_stackelem **a, t_stackelem **b, int len)
{
    if (!is_sorted(*a))
    {
        if (len == 2)
            stackiter(ft_swap, a, b, "sa\n");
        else if (len == 3) // 2 instructions
            sort_three(a, b);
        else if (len == 5) // 12 instructions
            sort_five(a, b);
        else if (len == 100)
            sort_hundrd(a, b, stacksize(*a) / 2);
        else
             sort_five_h(a, b, stacksize(*a) / 2);
    }
}

void free_tab(char ***tab)
{
    int i;

    i = 0;
    while (*tab[i])
    {
        free(*tab[i]);
        *tab[i] = NULL;
        i++;
    }
    free(*tab);
    **tab = NULL;
}

int main(int argc, char *argv[])
{
     int ret;
    int res;
    t_stackelem *a;
    t_stackelem *b;
    char *line;
	char **args;
    int len;
    // char **t = malloc(13 * sizeof(char*));
    // t[0] = ft_strdup("./push_swap");
    // t[1] = ft_strdup("0");
    // t[2] = ft_strdup("6");
    // t[3] = ft_strdup("1");
    // t[4] = ft_strdup("4");
    // t[5] = ft_strdup("3");
    // t[6] = ft_strdup("9");
    // t[7] = ft_strdup("10");
    // t[8] = ft_strdup("8");
    // t[9] = ft_strdup("7");
    // t[10] = ft_strdup("2");
    // t[11] = ft_strdup("5");
	// t[12] = NULL;
	// argc = 14;
    // argv = t;
    int i = 0;
    if (argc >= 2)
    {
        b = NULL;
        if (argc == 2)
        {
            args = ft_split(argv[1], ' ', &len);
            ret = create_stack(&a, args);
            argc = len + 1;
            // FREE ARGS
        }
        else
            ret = create_stack(&a, argv + 1);
        if(ret == -1)
            return(-1);
        push_swap(&a, &b, argc - 1);
        // write(1, "stack a => ", 11);
        // print_stack(a);
        // write(1, "stack b => ", 11);
        // print_stack(b);
        // write(1, "stack a => ", 11);
        // print_stack(a);
        // write(1, "stack b => ", 11);
        // print_stack(b);
    }
    return 0;
}