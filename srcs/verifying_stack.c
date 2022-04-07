/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifying_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:19:46 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/06 20:03:31 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
