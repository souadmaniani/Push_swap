/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 01:18:46 by ozakkare          #+#    #+#             */
/*   Updated: 2019/10/23 01:34:09 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int lstsize;

	if (!lst)
		return (NULL);
	lstsize = ft_lstsize(lst) - 1;
	while (lstsize--)
		lst = lst->next;
	return (lst);
}
