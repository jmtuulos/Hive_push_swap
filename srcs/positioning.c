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
		if (stack->value < value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}
