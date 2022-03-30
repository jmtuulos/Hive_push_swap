#include "pushswap.h"

int	value_in_index(t_stack *stack, int index)
{
	while (index--)
		stack = stack->next;
	return (stack->value);
}
