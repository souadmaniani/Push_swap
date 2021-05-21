/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:40:42 by ozakkare          #+#    #+#             */
/*   Updated: 2019/10/19 19:27:57 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	len;
	unsigned int	i;

	len = 0;
	if (s == 0)
		return (0);
	while (s[len])
		len++;
	if (!(p = malloc((len + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (++i < len)
		p[i] = f(i, s[i]);
	p[i] = '\0';
	return (p);
}
