#include "pushswap.h"

int	find_middle_value(t_stack *stack)
{
	int		middle;
	int		index;
	int		stack_size;

	stack_size = calc_stack_size(stack);
	middle = find_smallest_value(stack);
	while (stack)
	{
		if (stack->value > middle)
		{
			middle = stack->value;
		}
		stack = stack->next;
	}
	return (middle);
}
