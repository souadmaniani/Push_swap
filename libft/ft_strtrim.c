/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:53:44 by ozakkare          #+#    #+#             */
/*   Updated: 2019/10/20 18:45:27 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char a, const char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

static int		starts(const char *s1, const char *set, int lens)
{
	int j;
	int start;
	int i;

	if (!(check(s1[0], set)))
		return (0);
	j = -1;
	while (++j < lens)
	{
		i = -1;
		while (set[++i])
		{
			if (set[i] == s1[j])
			{
				start = j;
				if (!(check(s1[j + 1], set)))
				{
					if (start + 1 == (int)ft_strlen(s1))
						start = 0;
					return (start + 1);
				}
			}
		}
	}
	return (start);
}

static int		ends(const char *s1, const char *set, int lens)
{
	int j;
	int i;
	int end;

	if (!(check(s1[lens - 1], set)))
		return (lens);
	j = lens - 1;
	while (j)
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == s1[j])
			{
				end = j;
				if (!(check(s1[j - 1], set)))
					return (end);
			}
			i++;
		}
		j--;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		start;
	int		end;
	int		lens;

	if (s1 == 0)
		return (0);
	lens = (int)ft_strlen(s1);
	start = starts(s1, set, lens);
	end = ends(s1, set, lens);
	p = malloc((end - start + 1) * sizeof(char));
	if (p == 0)
		return (0);
	i = 0;
	while (start < end)
	{
		p[i] = s1[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
