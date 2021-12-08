/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:20:46 by amoubare          #+#    #+#             */
/*   Updated: 2021/12/08 03:37:28 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	nadi(char **stock, char **ligne)
{
	char	*temp;
	int		x;

	x = ft_int_strchr(*stock, '\n') + 1;
	temp = *ligne;
	*ligne = ft_substr(*stock, 0, x);
	free(temp);
	*stock = ft_substr(*stock, x, ft_strlen(*stock));
}

char	*get_next_line(int fd)
{
	int			i;
	char		*buff;
	char		*ligne;
	static char	*stock;
	char		*temp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_int_strchr(stock, '\n') == -1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == 0 && ft_int_strchr(stock, '\n') == -1)
		{
			ligne = stock;
			if (stock)
				free(stock);
			stock = NULL;
			return (ligne);
		}
		else if (i == -1)
		{
			free (buff);
			return (0);
		}
		buff[i] = '\0';
		temp = stock;
		stock = ft_strjoin(stock, buff);
		if (temp)
			free(temp);
	}
	free(buff);
	nadi(&stock, &ligne);
	return (ligne);
}
// int main()
// {
//     char *k;
//     int fd;
//     fd = open("filetest",  O_RDONLY);
//     k = get_next_line(fd);
//     while(k)
//     {
//         printf("%s", k);
//         free(k);
//         k = get_next_line(fd);
//     }
// }