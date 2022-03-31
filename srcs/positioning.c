#include "pushswap.h"

int	location_in_sorted(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while(stack)
	{
		if (stack->value > value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_highest(t_stack *stack)
{
	int		highest;
	int		index;
	int		i;

	highest = MIN_NUMBER;
	index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

int	find_smallest(t_stack *stack)
{
	int		smallest;
	int		index;
	int		i;

	smallest = MAX_NUMBER;
	index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

int find_highest_value(t_stack *stack)
{
	int	highest;

	if (!stack)
		return (0);
	highest = stack->value;
	while (stack->next)
	{
		stack = stack->next;
		if (stack && highest < stack->value)
			highest = stack->value;
	}
	return (highest);
}

int	find_smallest_value(t_stack *stack)
{
	int	smallest;

	if (!stack)
		return (0);
	smallest = stack->value;
	while (stack->next)
	{
		if (smallest > stack->next->value)
			smallest = stack->next->value;
		stack = stack->next;
	}
	return (smallest);
}

int	location_in_reverse_sorted(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while(stack)
	{
		i++;
		if (stack->value > value && stack->next && stack->next->value < value)
			return (i);
		stack = stack->next;
	}
	return (0);
}
