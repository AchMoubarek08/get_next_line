/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:20:46 by amoubare          #+#    #+#             */
/*   Updated: 2021/12/13 02:57:16 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	nadi(char **stock, char **ligne)
{
	char	*temp;
	int		x;

	x = ft_int_strchr(*stock, '\n') + 1;
	*ligne = ft_substr(*stock, 0, x);
	temp = *stock;
	*stock = ft_substr(*stock, x, ft_strlen(*stock));
	free(temp);
}

char	*ft_free(char **lost)
{
	if (*lost)
		free(*lost);
	*lost = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			i;
	char		buff[BUFFER_SIZE + 1];
	char		*ligne;
	static char	*stock[1024];
	char		*temp;

	while (ft_int_strchr(stock[fd], '\n') == -1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == 0 || i == -1)
		{
			if (stock[fd] && stock[fd][0] == '\0')
				ft_free(&stock[fd]);
			ligne = stock[fd];
			stock[fd] = NULL;
			return (ligne);
		}
		buff[i] = '\0';
		temp = stock[fd];
		stock[fd] = ft_strjoin(stock[fd], buff);
		ft_free(&temp);
	}
	nadi(&stock[fd], &ligne);
	return (ligne);
}
