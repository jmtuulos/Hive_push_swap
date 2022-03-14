#include "pushswap.h"

void	del_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack != NULL)
	{
		next = stack->next;
		stack->value = 0;
		free(stack);
		stack = next;
	}
}

t_stack	*new_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	return (new);
}

void	add_to_start(t_stack **a, int value)
{
	t_stack	*tmp;
	if ((*a)->value == (char)0)
		(*a)->value = value;
	else
	{
		tmp = new_node(value);
		tmp->next = *a;
		*a = tmp;
	}

}

void	add_to_end(t_stack **a, int value)
{
	t_stack	*tmp;

	if ((*a)->value == (char)0)
		(*a)->value = value;
	else
	{
		tmp = *a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node(value);
	}
}
