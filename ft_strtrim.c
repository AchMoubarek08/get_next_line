/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:28:49 by amoubare          #+#    #+#             */
/*   Updated: 2021/11/12 05:01:13 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
	{
		i++;
	}
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int	len;

	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len - 1]))
	{
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1)
		return (NULL);
	start = ft_start(s1, set);
	if (start == (int)ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_end(s1, set);
	str = (char *)malloc(sizeof(char) * end - start + 1);
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 1);
	str[end - start + 1] = '\0';
	return (str);
}
