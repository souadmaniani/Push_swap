/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:11:48 by ozakkare          #+#    #+#             */
/*   Updated: 2019/10/19 19:27:03 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*p;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(p = malloc((lens1 + lens2 + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (++i < lens1)
		p[i] = s1[i];
	j = 0;
	while (i < (lens1 + lens2))
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}
