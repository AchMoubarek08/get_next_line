/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:20:46 by amoubare          #+#    #+#             */
/*   Updated: 2021/11/29 21:25:36 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i = 0;
    static char *stock;
    char *str;
    char *line;
    str = malloc(sizeof(char) * 100);
    line = malloc(sizeof(char) * 100);
    read(fd, str, 1000);
    while(str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    stock = ft_substr(str, i, 100);
    i = 0;
    while(stock[i] != '\n')
    {
        line[i] = stock[i];
        i++;
    }
    return(line);
}
int main()
{
    char *str = malloc(sizeof(char) * 10000);
    int fd;
    fd = open("filetest",  O_RDONLY);
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
}