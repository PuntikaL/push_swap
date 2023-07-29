/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:28:36 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/09 12:29:26 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	push( t_node *newnode, t_stack *a)
{
	a->top = newnode;
	a->size++;
}

t_node	*top(t_stack *a)
{
	return (a->top);
}

int	size(t_stack *a)
{
	return (a->size);
}

int	is_empty(t_stack *a)
{
	if (a->top == NULL || a->size == 0)
		return (1);
	return (0);
}
