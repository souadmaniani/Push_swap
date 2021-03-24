/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 02:18:56 by ozakkare          #+#    #+#             */
/*   Updated: 2019/10/23 03:40:48 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *var;
	t_list *helper;

	var = *lst;
	while (var)
	{
		helper = var->next;
		del(var->content);
		free(var);
		var = helper;
	}
	(*lst) = NULL;
}
