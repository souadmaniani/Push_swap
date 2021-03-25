/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:12:08 by ozakkare          #+#    #+#             */
/*   Updated: 2019/10/22 19:01:21 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	if (*needle == 0)
		return ((char *)haystack);
	j = 0;
	while (j < len && haystack[j])
	{
		k = j;
		i = 0;
		while (haystack[k] == needle[i] && (j + i) < len)
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)(haystack + (k - i + 1)));
			k++;
		}
		j++;
	}
	return (0);
}
