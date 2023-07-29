/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:18:45 by pleepago          #+#    #+#             */
/*   Updated: 2023/06/23 23:08:43 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_split(char c, char s)
{
	(void)s;
	if (c == '\0' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	word_num(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_split(str[i + 1], c) && !is_split(str[i], c))
			count++;
		i++;
	}
	return (count);
}

void	put_str(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (is_split(src[i], c) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	print(char **arr, char *str, char c)
{
	int	i;
	int	j;
	int	n_word;

	n_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_split(str[i], c))
			i++;
		else
		{
			j = 0;
			while (is_split(str[i + j], c) == 0)
				j++;
			arr[n_word] = (char *)malloc(sizeof(char) * (j + 1));
			put_str(arr[n_word], str + i, c);
			i += j;
			n_word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word;
	char	*p;

	p = (char *)s;
	if (s == NULL)
		return (NULL);
	word = word_num(p, c);
	arr = (char **)malloc(sizeof(char *) * (word + 1));
	if (!arr)
		return (NULL);
	arr[word] = 0;
	print(arr, p, c);
	return (arr);
}
