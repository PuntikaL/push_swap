/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:15:37 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/09 11:55:07 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	tiny(t_stack *a)
{
	int	highest;

	if (sorted(a))
		return ;
	highest = max(a);
	if (a->top->data == highest)
		ra(a);
	else if (a->top->next->data == highest)
		rra(a);
	if ((a->top->data > a->top->next->data))
		sa(a);
}

int	min(t_stack *a)
{
	t_node	*p;
	int		min;
	int		i;

	min = a->top->data;
	p = a->top;
	i = 0;
	while (i < a->size)
	{
		if (p->data < min)
			min = p->data;
		p = p->next;
		i++;
	}
	return (min);
}

void	small(t_stack *a, t_stack *b)
{
	int	low;
	int	i;

	low = min(a);
	i = 0;
	while (i < 1)
	{
		if (a->top->data == low)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	tiny(a);
	pa(a, b);
}

void	medium_ext(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		pa(a, b);
		if (a->top->data > a->top->next->data)
			ra(a);
		i++;
	}
}

void	medium(t_stack *a, t_stack *b)
{
	int	low;
	int	high;
	int	i;

	low = min(a);
	high = max(a);
	i = 0;
	while (i < 2)
	{
		if (a->top->data == low || a->top->data == high)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	tiny(a);
	medium_ext(a, b);
}
