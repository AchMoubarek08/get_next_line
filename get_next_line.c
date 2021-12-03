/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:20:46 by amoubare          #+#    #+#             */
/*   Updated: 2021/12/02 23:06:10 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i = 0;
    static char *stock;
    char *str;
    char *temp;

    stock = ft_strdup("");
    str = malloc(sizeof(char) * BUFFER_SIZE + 1);
    str[i] = 0;
    while (!ft_strchr(str, '\n'))
    {
        i = read(fd, str, BUFFER_SIZE);
        str[i] = 0;
        temp = stock;
        stock = ft_strjoin(stock, str);
        free(temp);
        if(*stock == '\0')
        {
            free(str);
            return (0);
        }
        else if(i == 0)
        {
            temp = ft_strdup(stock);
            stock[0] = '\0';
            free(str);
            return temp;
        }
    }
    temp = str;
    free(temp);
    str = ft_substr(stock, 0, ft_int_strchr(stock, '\n') + 1);
    stock = ft_substr(str, ft_int_strchr(str, '\n') + 1, ft_strlen(str));
    
    return (str);
}
int main()
{
    int fd;
    fd = open("filetest",  O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}