/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifying_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:19:46 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/13 20:45:15 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	**allocate_starting_array(char **input, int size)
{
	char	**new;
	char	**tmp;

	new = (char **)malloc(sizeof(char *) * size + 1);
	tmp = new;
	if (!new)
		exit(-1);
	input++;
	while (size-- > 0)
	{
		*new = ft_strdup(*input++);
		if (!*new++)
			exit(-1);
	}
	*new = 0;
	return (tmp);
}

char	*join_n_del_first(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}

int	is_stack_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value >= stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_stack_reverse_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value <= stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	distance_to_edges(t_stack *stack, int index)
{
	int	size;

	size = calc_stack_size(stack);
	if (index > size / 2)
		index = size - index;
	return (index);
}
