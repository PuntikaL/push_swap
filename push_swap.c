/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:11:50 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/09 12:26:57 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	get_index( t_stack *a, int value)
{
	t_node	*pointer;
	int		order;

	order = 0;
	pointer = a->top;
	while (pointer != NULL)
	{
		if (value >= pointer->data)
			order += 1;
		else
			pointer->index += 1;
		pointer = pointer->next;
	}
	return (order);
}

void	set_a( t_stack *a, int argc, char **argv)
{
	t_node		*n;
	t_node		*prevn;
	int			i;

	i = 1;
	n = malloc(sizeof(t_node));
	n->data = ft_atoi(argv[0]);
	n->next = NULL;
	n->index = 0;
	prevn = n;
	push(n, a);
	while (i < argc - 1)
	{
		n = malloc(sizeof(t_node));
		n->data = ft_atoi(argv[i]);
		n->next = NULL;
		n->index = get_index(a, n->data);
		prevn->next = n;
		prevn = n;
		i++;
	}
	prevn->next = NULL;
}

int	check_valid(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) != ft_atol(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	max( t_stack *a)
{
	t_node	*p;
	int		max;
	int		i;

	max = a->top->data;
	p = a->top;
	i = 0;
	while (i < a->size && p)
	{
		if (p->data > max)
			max = p->data;
		p = p->next;
		i++;
	}
	return (max);
}
