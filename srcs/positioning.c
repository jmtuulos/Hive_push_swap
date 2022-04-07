/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:13:34 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/07 16:39:13 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_highest(t_stack *stack)
{
	int		highest;
	int		index;
	int		i;

	index = 0;
	i = 0;
	if (!stack)
		return (0);
	highest = stack->value;
	while (stack)
	{
		if (stack->value >= highest)
		{
			highest = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int	find_smallest(t_stack *stack)
{
	int		smallest;
	int		index;
	int		i;

	if (!stack)
		return (0);
	smallest = stack->value;
	index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value <= smallest)
		{
			smallest = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int	find_highest_value(t_stack *stack)
{
	int	highest;

	if (!stack)
		return (0);
	highest = stack->value;
	while (stack)
	{
		if (highest <= stack->value)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}

int	find_smallest_value(t_stack *stack)
{
	int	smallest;

	if (!stack)
		return (0);
	smallest = stack->value;
	while (stack)
	{
		if (smallest >= stack->value)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

int	index_in_r_sorted(t_stack *stack, int value)
{
	int	i;
	int	highest;
	int	smallest;

	highest = find_highest_value(stack);
	if (highest < value)
		return (find_highest(stack));
	smallest = find_smallest_value(stack);
	if (smallest > value)
		return (find_smallest(stack) + 1);
	i = 0;
	while (stack)
	{
		i++;
		if (stack->value > value && stack->next && stack->next->value < value)
			return (i);
		stack = stack->next;
	}
	return (0);
}
