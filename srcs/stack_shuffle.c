#include "pushswap.h"

void	exec_rot(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*tmp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	curr = *stack;
	tmp = (*stack)->next;
	while (curr->next)
		curr = curr->next;
	curr->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
}

void	exec_rrot(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*prev;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	curr = *stack;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = *stack;
	*stack = curr;
	prev->next = NULL;
}

void	exec_push(t_stack **from, t_stack **dest)
{
	t_stack	*tmp;

	if (!(*from))
		return ;
	add_to_start(dest, (*from)->value);
	tmp = *from;
	*from = (*from)->next;
	free(tmp);
}

void	exec_swap(t_stack **stack)
{
	int		tmp;

	if ((*stack)->next == NULL)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

