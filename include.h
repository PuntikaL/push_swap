/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:05:13 by pleepago          #+#    #+#             */
/*   Updated: 2023/07/29 21:34:05 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	struct s_node	*top;
	int				size;
}	t_stack;

int		is_valid_argument(char *str);
void	push( t_node *newnode, t_stack *a);
t_node	*top(t_stack *a);
int		size(t_stack *a);
int		is_empty(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
int		abc(char *argv);
int		replicate(t_stack *a);
int		split_data(t_stack *a, t_stack *b, int argc, char **argv);
void	tiny(t_stack *a);
int		get_index(t_stack *a, int value);
void	set_a(t_stack *a, int argc, char **argv);
int		max(t_stack *a);
void	operation(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	sa(t_stack *a);
int		sorted(t_stack *a);
char	*join(int argc, char **argv, t_stack *as, t_stack *b);
int		check(int argc, char **argv);
void	small(t_stack *a, t_stack *b);
void	medium(t_stack *a, t_stack *b);
void	liang(t_stack *a);
void	select_sort(t_stack *a, t_stack *b, int argc);
void	free_me(t_stack *a, t_stack *b);
long	ft_atol(const char *str);
int		check_valid(int argc, char **argv);
void	medium_ext(t_stack *a, t_stack *b);
void	c_dup_n_sort(t_stack *a, t_stack *b);
void	free_split(char **k);

#endif
