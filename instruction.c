/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:28:04 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/09 09:50:54 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	sa(t_stack *a)
{
	t_node	*temp;
	t_node	*temp2;

	temp = a->top;
	a->top = a->top->next;
	temp2 = a->top->next;
	a->top->next = temp;
	temp->next = temp2;
	write(1, "sa\n", 3);
}

void	rra(t_stack *a)
{
	t_node	*p;
	t_node	*temp;
	t_node	*last;

	temp = a->top;
	p = a->top;
	while (p->next != NULL)
	{
		if (p->next->next == NULL)
			last = p;
		p = p->next;
	}
	a->top = p;
	p->next = temp;
	last->next = NULL;
	write(1, "rra\n", 4);
}
