/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:28:30 by ozakkare          #+#    #+#             */
/*   Updated: 2019/10/18 23:26:49 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char *s;
	size_t				i;

	d = (unsigned char*)dst;
	s = (unsigned const char*)src;
	i = -1;
	while (++i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return ((dst + i + 1));
	}
	return (0);
}
