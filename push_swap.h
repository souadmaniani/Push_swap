#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
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

#endif