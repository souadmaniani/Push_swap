/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:44:50 by ozakkare          #+#    #+#             */
/*   Updated: 2019/10/18 15:33:49 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned	x;
	char		nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		x = n * -1;
	}
	else
		x = n;
	if (x > 10)
		ft_putnbr_fd(x / 10, fd);
	nb = x % 10 + 48;
	write(fd, &nb, 1);
}
