#include "push_swap.h"

int	is_duplicate(char *str, char **argv, int	index)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_strcmp(str, argv[i]) && index != i)
			return (1);
	}
	return (0);
}

int	create_stack(t_stackelem	**head, char **argv)
{
	t_stackelem	*new;
	int			i;

	i = -1;
	*head = NULL;
	while (argv[++i])
	{
		if ((ft_atoi(argv[i]) == -1 && ft_strcmp(argv[i], "-1"))
			|| (!ft_atoi(argv[i]) && ft_strcmp(argv[i], "0"))
			|| is_duplicate(argv[i], argv, i))
		{
			write(2, "Error\n", 7);
			return (-1);
		}
		new = stacknew(ft_atoi(argv[i]));
		if (!new)
			return (-1);
		stackadd_back(head, new);
	}
	return (0);
}

int	is_sorted(t_stackelem	*head)
{
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_stack(t_stackelem	*head)
{
	t_stackelem	*tmp;

	tmp = head;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
