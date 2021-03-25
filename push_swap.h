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

t_stackelem					*stacknew(int data);
int							stacksize(t_stackelem *head);
void						stackadd_front(t_stackelem **head, t_stackelem *new);
t_stackelem					*stacklast(t_stackelem *head);
void						stackadd_back(t_stackelem **head, t_stackelem *new);
int                         stackdelete_head(t_stackelem **head);
int                         stackdelete_last(t_stackelem **head);
void                        swap(t_stackelem *head);
void                        push(t_stackelem **dest, t_stackelem **src);
void                        rotate(t_stackelem **head);
void                        reverse_rotate(t_stackelem **head);
void                        print_stack(t_stackelem *head);
#endif