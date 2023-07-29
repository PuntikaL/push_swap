/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:15:37 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/29 21:33:49 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	liang(t_stack *a)
{
	if (a->top->data > a->top->next->data)
		ra(a);
}

void	select_sort(t_stack *a, t_stack *b, int argc)
{
	if (argc == 3)
		liang(a);
	if (argc == 4)
		tiny(a);
	else if (argc == 5)
		small(a, b);
	else if (argc == 6)
		medium(a, b);
	else if (argc > 6)
		operation(a, b);
}

long	ft_atol(const char *str)
{
	unsigned int	i;
	long			sign;
	long			sum;

	i = 0;
	sign = 1;
	sum = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (sign * sum);
}

int	is_valid_argument(char *p)
{
	char	*str;

	str = p;
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}
