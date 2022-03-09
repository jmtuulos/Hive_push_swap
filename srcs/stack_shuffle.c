#include "pushswap.h"

void	exec_rot(t_stack **stack)
{
	t_stack	*curr;


	if ((*stack)->next == NULL)
		return ;
	curr = *stack;
	while (curr)
		curr = curr->next;
	curr->next = *stack;
	(*stack)->next = NULL;
}

void	exec_rrot(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*prev;

	if ((*stack)->next == NULL)
		return ;
	curr = *stack;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = *stack;
	*stack = curr;
	prev->next = NULL;
}

void	exec_push(t_stack **first, t_stack **second)
{
	t_stack	*f_tmp;
	t_stack	*s_tmp;
	t_stack	*prev;

	if (!(*first))
		return ;
	f_tmp = (*first);
	s_tmp = (*second);
	while (f_tmp)
	{
		prev = f_tmp;
		f_tmp = f_tmp->next;
	}
	while (s_tmp)
		s_tmp = s_tmp->next;
	s_tmp->next = f_tmp;
	prev->next = NULL;

}

void	exec_swap(t_stack **stack)
{
	t_stack	*prev;
	t_stack *curr;
	int		tmp;

	if ((*stack)->next == NULL)
		return ;
	curr = *stack;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	tmp = curr->value;
	curr->value = prev->value;
	prev->value = tmp;
}

