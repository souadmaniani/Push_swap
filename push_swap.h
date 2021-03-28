#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "srcs/libft/libft.h"
#include "srcs/get_next_line/get_next_line.h"
#include <stdio.h>
# define INT_MAX	2147483647

typedef struct 				s_stackelem
{
    int						data;
    struct s_stackelem		*next;
}						    t_stackelem;

typedef struct               s_elem
{
    int                      first;
    int                      second;
    int                      third;
}                            t_elem;

t_stackelem					*stacknew(int data);
int							stacksize(t_stackelem *head);
void						stackadd_front(t_stackelem **head, t_stackelem *new);
t_stackelem					*stacklast(t_stackelem *head);
void						stackadd_back(t_stackelem **head, t_stackelem *new);
int                         stackdelete_head(t_stackelem **head);
int                         stackdelete_last(t_stackelem **head);
void	                    stackiter(void (*f)(t_stackelem **, t_stackelem **),
                            t_stackelem **a, t_stackelem **b, char *str);
int                         stackmax(t_stackelem *a);
int                         stackmin(t_stackelem *a);
void                        ft_swap(t_stackelem **head, t_stackelem **b);
void                        ft_push(t_stackelem **dest, t_stackelem **src);
void                        ft_rotate(t_stackelem **head, t_stackelem **b);
void                        ft_reverse_rotate(t_stackelem **head, t_stackelem **b);
void                        print_stack(t_stackelem *head);
int                         is_duplicate(char *str, char **argv, int index);
int							create_stack(t_stackelem **head, char **argv);
int							apply_instruction(char *line, t_stackelem **a, t_stackelem **b);
int							is_sortded(t_stackelem *head);
#endif

// char **t = malloc(4*sizeof(char*));
// t[0] = ft_strdup("./push_swap");
// t[1] = ft_strdup("5");
// t[2] = ft_strdup("1");
// t[3] = ft_strdup("2");