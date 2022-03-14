#include "pushswap.h"

int	is_stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value >= stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

char *solve_s3_helper(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	if ((*stack)->value > tmp->next->value)
	{
		if ((*stack)->value > tmp->value)
		{
			exec_swap(a);
			exec_rrot(a);
			return (ft_strdup("sa\nrra\n"));
		}
		exec_rot(a);
		return (ft_strdup("ra\n"));
	}
	exec_swap(a);
	return (ft_strdup("sa\n"));
}

char	*solve_stack_3(t_stack **stack)
{

	if (is_stack_sorted(stack))
		return (NULL);
	if ((*stack)->value > (*stack)->next->value)
		return (solve_s3_helper(a));
	if ((*stack)->value < (*stack)->next->next->value)
	{
		exec_swap(a);
		exec_rot(a);
		return (t_strdup("sa ra\n"));
	}
	exec_rrot(a);
	return (ft_strdup("rra\n"));
}

char	*solve_stack_2(t_stack **stack)
{
	if ((*stack)->value < (*stack)->next->value)
		return (NULL);
	else
		exec_rot(stack);
	return (ft_strdup("ra"));

}

char	*solve_remainder(t_stack **a, t_stack **b, char **solution)
{

	if ((*a)->value > (*b)->value)
	{
		exec_push(b, a);
		ft_strjoin(*solution, "pb\n");
	}
	if else((*b)->value > (*a)->next->next->value))
	{
		exec_push(b, a);
		exec_rot(a);
		ft_strjoin(*solution, "pb\nra\n");
	}
	else if ((*b)->value)


}

char	*solve_5(t_stack **a, t_stack **b, int stack_size, char **solution)
{
	t_stack	*tmp;

	if (stack_size == 3)
		*solution = solve_stack_3(a);
	else if (stack_size < 3)
		*solution = solve_stack_2(a);
	else
	{
		tmp = *a;
		exec_push(*a, *b);
		exec_push(*a, *b);
		*solution = solve_stack_3(a);
		*solution = solve_remainder(a,b);


	}

	return (solution);
}

char	*sort_stack(t_stack **a, int stack_size)
{
	t_stack	*b;
	char	*solution;

	b = new_node((char)0);
	if (stack_size <= 5)
		solve_5(&a, &b, stack_size, &solution);
	ft_putstr(solution);
	del_stack(*a);
	del_stack(*b);
	exit(0);


}
