/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:52:54 by ozakkare          #+#    #+#             */
/*   Updated: 2019/10/19 00:33:57 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *sr;
	size_t				i;

	sr = (const unsigned char*)s;
	i = 0;
	while (n--)
	{
		if (sr[i] == (unsigned char)c)
			return ((unsigned char*)(s + i));
		i++;
	}
	return (0);
}
