#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# define INT_MAX	2147483647

typedef struct s_stackelem
{
	int					data;
	struct s_stackelem	*next;
}				t_stackelem;

void		print_stack_cmds(t_stackelem *head);
t_stackelem	*stacknew(int data);
int			stacksize(t_stackelem *head);
void		stackadd_front(t_stackelem **head, t_stackelem *new);
t_stackelem	*stacklast(t_stackelem *head);
void		stackadd_back(t_stackelem **head, t_stackelem *new);
int			stackdelete_head(t_stackelem **head);
int			stackdelete_last(t_stackelem **head);
void		stackiter(void (*f)(t_stackelem **, t_stackelem **),
				t_stackelem **a, t_stackelem **b, char *str);
int			stackmax(t_stackelem *a);
int			stackmin(t_stackelem *a);
t_stackelem	*stackchr(t_stackelem *a, int data);
t_stackelem	*stackcopy(t_stackelem **dest, t_stackelem *src);
void		ft_swap(t_stackelem **head, t_stackelem **b);
void		ft_push(t_stackelem **dest, t_stackelem **src);
void		ft_rotate(t_stackelem **head, t_stackelem **b);
void		ft_reverse_rotate(t_stackelem **head, t_stackelem **b);
void		print_stack(t_stackelem *head);
int			is_duplicate(char *str, char **argv, int index);
int			create_stack(t_stackelem **head, char **argv);
int			apply_instruction(char *line, t_stackelem **a, t_stackelem **b);
int			is_sorted(t_stackelem *head);
int			stackmin_index(t_stackelem *a);
int			stackmax_index(t_stackelem *a);
void		stackdelete_elem(t_stackelem **a, t_stackelem *elem);
int			stackindex(t_stackelem *a, int value);
void		ft_swap_q(int *a, int *b);
int			partition(int *arr, int l, int h);
int			*quiq_sort(int *arr, int l, int h);
int			get_middle(t_stackelem *a, int len);
int			get_len(t_stackelem *b, int first, int last);
int			is_reverse_sorted(t_stackelem *head, int len);
int			get_min_indexes(t_stackelem *a, int mid, int len);
void		print_stacks(char *str, t_stackelem *a, t_stackelem *b);
int			get_max_of_chunk(t_stackelem *a, int len, int	chunk_len);
void		free_tab(char **tab);
void		free_stack(t_stackelem *head);
void		sort_part(t_stackelem **a, t_stackelem **b, int len);
int			*copystack_arr(t_stackelem *a, int len);
void		sort_three(t_stackelem **a, t_stackelem **b);
void		sort_five(t_stackelem **a, t_stackelem **b);
void		sort_hundred(t_stackelem **a, t_stackelem **b, int half);
void		push_all_min(t_stackelem **a, t_stackelem **b,
				int middle, int half);
void		analyse_number(t_stackelem **a, t_stackelem **b, int *len);
void		sort_chunks(t_stackelem **a, t_stackelem **b, int k,
				int arr[100][3]);
void		push_chunks(t_stackelem **a, t_stackelem **b,
				int max_chunk);
void		sort_five_hundred(t_stackelem **a, t_stackelem **b,
				int chunk_len, int k);
void		push_swap(t_stackelem **a, t_stackelem **b,	int	len);
#endif