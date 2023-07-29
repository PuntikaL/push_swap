/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:44:14 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/09 12:30:25 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!(is_empty(b)))
	{
		tmp = b->top;
		b->top = tmp->next;
		if (a->size > 0)
			tmp->next = a->top;
		else
			tmp->next = NULL;
		a->top = tmp;
		a->size++;
		b->size--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!(is_empty(a)))
	{
		tmp = a->top;
		a->top = tmp->next;
		if (b->size > 0)
			tmp->next = b->top;
		else
			tmp->next = NULL;
		b->top = tmp;
		a->size--;
		b->size++;
		write(1, "pb\n", 3);
	}
}

void	ra(t_stack *a)
{
	t_node	*temp;
	t_node	*pt;

	pt = a->top;
	temp = a->top;
	a->top = a->top->next;
	while (pt->next != NULL)
		pt = pt->next;
	pt->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *a)
{
	t_node	*temp;
	t_node	*pt;

	pt = a->top;
	temp = a->top;
	a->top = a->top->next;
	while (pt->next != NULL)
		pt = pt->next;
	pt->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}
