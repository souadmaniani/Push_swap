/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:55:30 by smaniani          #+#    #+#             */
/*   Updated: 2019/10/29 14:02:56 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int				get_next_line(int fd, char **line);
char			*ft_strcpy(char *dest, char *src);
char			*resize(char *line);
int				free_table(char **table, char **ptr);
int				fill_line(char **stock, char **line, int cas);

#endif
