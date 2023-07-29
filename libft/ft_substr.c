/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:54:16 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/09 12:55:01 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(char const *s, unsigned int start, size_t len)
{
	if (len > (size_t)ft_strlen(s))
		len = (size_t)ft_strlen(s);
	if (start + len > (size_t)ft_strlen(s))
		len -= start;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (start > (size_t)ft_strlen(s))
		return (ft_calloc(1, 1));
	len = get_len (s, start, len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
