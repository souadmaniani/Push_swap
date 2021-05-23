#include "libft.h"

static size_t	ft_numwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			count++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**ft_free(char **str, int num)
{
	while (--num)
		free(&str[num]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	static size_t	i = 0;
	size_t			num;
	size_t			start;
	static size_t	len = 0;
	char			**str;

	if (s == 0)
		return (0);
	num = ft_numwords(s, c) + 1;
	str = (char **)malloc(sizeof(char *) * (num));
	if (!str)
		return (NULL);
	while (i < num - 1)
	{
		while (s[len] == c && s[len])
			len++;
		start = len;
		while (s[len] != c && s[len])
			len++;
		(str[i++] = ft_substr(s, start, (len - start)));
		if (!str)
			return (ft_free(str, num));
	}
	str[i] = 0;
	return (str);
}
