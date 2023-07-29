/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:07:12 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/09 11:56:23 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (abc(argv[i]) || argv[i] == NULL)
			return (1);
		i++;
	}
	return (0);
}

char	*join(int argc, char **argv, t_stack *as, t_stack *b)
{
	char	*a;
	char	*tmp;
	int		i;

	i = 1;
	a = ft_strjoin("", " ");
	while (i < argc)
	{
		if (check(argc, argv) || !(check_valid(argc, argv)))
		{
			write(2, "Error\n", 6);
			free_me(as, b);
			free(a);
			exit(1);
		}
		tmp = a;
		a = ft_strjoin(a, argv[i]);
		free(tmp);
		tmp = a;
		a = ft_strjoin(a, " ");
		free(tmp);
		i++;
	}
	return (a);
}
