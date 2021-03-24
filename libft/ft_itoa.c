/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:46:13 by ozakkare          #+#    #+#             */
/*   Updated: 2019/10/20 16:50:22 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int		convert(int n)
{
	if (negative(n))
		return (n * -1);
	return (n);
}

static char		*fill(int len, int n, char *p, int count)
{
	int				i;
	unsigned int	nb;
	int				zero;

	i = 0;
	nb = (unsigned int)convert(n);
	if (negative(n))
		p[i++] = '-';
	while (len--)
	{
		p[i++] = (char)((nb / count) + 48);
		if ((nb % count) != 0 || (count / 10) != 0)
		{
			nb %= count;
			count /= 10;
			if (((nb) / (count)) > nb)
				p[i] = '0';
		}
	}
	zero = 0;
	if (negative(n))
		zero++;
	p[i - zero] = '\0';
	return (p);
}

char			*ft_itoa(int n)
{
	unsigned int	nb;
	int				count;
	int				len;
	char			*p;

	nb = convert(n);
	count = 1;
	len = 1 + negative(n);
	while (nb >= 10)
	{
		nb /= 10;
		count *= 10;
		len++;
	}
	if (!(p = malloc(len + 1 * sizeof(char))))
		return (0);
	return (fill(len, n, p, count));
}
