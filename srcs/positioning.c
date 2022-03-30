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

int	location_in_reverse_sorted(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while(stack)
	{
		if (stack->value > value && stack->next && stack->next->value < value)
			return (i + 1);
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
