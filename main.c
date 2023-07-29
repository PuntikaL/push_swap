/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:15:37 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/29 21:35:18 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	find_maxbit(t_stack *a)
{
	int	max_num;
	int	max_bit;

	max_bit = 0;
	max_num = a->size;
	while (max_num >> max_bit != 0)
		++max_bit;
	return (max_bit);
}

void	operation(t_stack *a, t_stack *b)
{
	int	max_bit;
	int	i;
	int	j;
	int	len;

	max_bit = find_maxbit(a);
	len = a->size;
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j < len)
		{
			if (((a->top->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			++j;
		}
		while (b->size)
			pa(a, b);
		++i;
	}
}

void	free_me(t_stack *a, t_stack *b)
{
	t_node	*p;
	t_node	*f;

	p = NULL;
	if (a->size > 0)
	{
		p = a->top;
		while (p->next != NULL)
		{
			f = p;
			p = p->next;
			free(f);
		}
		free(p);
	}
	free(a);
	free(b);
}

void	c_dup_n_sort(t_stack *a, t_stack *b)
{
	if (replicate(a))
	{
		write(2, "Error\n", 6);
		free_me(a, b);
		exit(0);
	}
	if (sorted(a))
	{
		free_me(a, b);
		exit(0);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i ;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (argv[i] == NULL || argv[i][0] == '\0' || \
		!is_valid_argument(argv[i]))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->top = NULL;
	a->size = 0;
	argc = split_data(a, b, argc, argv);
	c_dup_n_sort(a, b);
	select_sort(a, b, argc);
	free_me(a, b);
	return (0);
}
