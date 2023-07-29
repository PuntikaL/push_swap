/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:31:48 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/29 19:08:23 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	abc(char *argv)
{
	int		i;
	char	c;
	int		valid;

	i = 0;
	valid = 0;
	while (argv[i] != '\0')
	{
		c = argv[i];
		if (c == '-' || c == '+')
		{
			valid++;
			if (i != 0 && ft_isdigit(argv[i - 1]))
				return (1);
			if (ft_isdigit(argv[i + 1]))
				valid--;
		}
		else if (c != ' ' && !(ft_isdigit(c)) && c != '\t')
			return (1);
		if (valid > 0)
			return (1);
		i++;
	}
	return (0);
}

int	replicate(t_stack *a)
{
	t_node	*p;
	t_node	*t;

	if (a == NULL || a->top == NULL)
		return (1);
	p = a->top;
	while (p->next != NULL)
	{
		t = p->next;
		while (t != NULL)
		{
			if (t->data == p->data)
				return (1);
			t = t->next;
		}
		p = p->next;
	}
	return (0);
}

int	sorted(t_stack *a)
{
	t_node	*p;
	t_node	*t;

	p = a->top;
	while (p->next != NULL)
	{
		t = p->next;
		while (t != NULL)
		{
			if (t->data < p->data)
				return (0);
			t = t->next;
		}
		p = p->next;
	}
	return (1);
}

void	free_split(char **k)
{
	char	**p;
	int		i;

	p = k;
	i = 0;
	while (p[i] != NULL)
	{
		free(p[i]);
		i++;
	}
	free(k);
}

int	split_data(t_stack *a, t_stack *b, int argc, char **argv)
{
	char	*set;
	char	**k;
	char	**p;
	int		i;
	int		count;

	i = 0;
	count = 0;
	set = join(argc, argv, a, b);
	k = ft_split(set, ' ');
	p = k;
	while (p[i] != NULL)
	{
		i++;
		count++;
	}
	set_a(a, count + 1, k);
	a->size = count;
	free_split(k);
	free(set);
	return (count + 1);
}
