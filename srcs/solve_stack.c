#include "pushswap.h"

int	is_stack_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value >= stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_stack_reverse_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value <= stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	calc_stack_size(t_stack *stack)
{
	int	stack_size;

	if (!stack)
		return (0);
	stack_size = 0;
	while (stack)
	{
		stack_size++;
		stack = stack->next;
	}
	return (stack_size);
}

char *solve_s3_helper(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	if ((*stack)->value > tmp->next->value)
	{
		if ((*stack)->value > tmp->value)
		{
			exec_swap(stack);
			exec_rrot(stack);
			return (ft_strdup("sa\nrra\n"));
		}
		exec_rot(stack);
		return (ft_strdup("ra\n"));
	}
	exec_swap(stack);
	return (ft_strdup("sa\n"));
}

char	*solve_stack_3(t_stack **stack)
{

	if (is_stack_sorted(*stack))
		return (NULL);
	if ((*stack)->value > (*stack)->next->value)
		return (solve_s3_helper(stack));
	if ((*stack)->value < (*stack)->next->next->value)
	{
		exec_swap(stack);
		exec_rot(stack);
		return (ft_strdup("sa\nra\n"));
	}
	exec_rrot(stack);
	return (ft_strdup("rra\n"));
}

char	*solve_stack_2(t_stack **stack)
{
	if ((*stack)->value < (*stack)->next->value)
		return (NULL);
	else
		exec_rot(stack);
	return (ft_strdup("ra\n"));
}

char	*push_from_bottom(t_stack **a, t_stack **b, int index, int stack_size)
{
	char	*ret;
	int		i;

	i = index;
	ret = ft_strnew(0);
	while (stack_size > i++)
		rra(a, &ret);
	pa(a,b, &ret);
	while (stack_size > index++)
		ra(a, &ret);
	ra(a, &ret);
	return (ret);
}

char	*push_from_top(t_stack **a, t_stack **b, int index)
{
	char	*ret;
	int		i;

	ret = ft_strnew(0);
	if (index == 0)
	{
		pa(a, b, &ret);
		return (ret);
	}
	i = index;
	while (i-- > 1)
		ra(a, &ret);
	pa(a, b, &ret);
	sa(a, &ret);
	while (++i < index)
		rra(a, &ret);
	return (ret);
}

void	push_to_sorted(t_stack **to, t_stack **from, char **solution)
{
	int	index;
	int	stack_size;

	stack_size = calc_stack_size(*to);
	index = location_in_sorted(*to, (*from)->value);
	if (stack_size / 2 >= index)
		*solution = ft_strjoin(*solution, push_from_top(to, from,  index));
	else
		*solution = ft_strjoin(*solution, push_from_bottom(to, from, index, stack_size));
}

char	*solve_5(t_stack **a, t_stack **b, int stack_size)
{
	char	*solution;

	solution = ft_strnew(0);
	if (stack_size == 3)
		solution = solve_stack_3(a);
	else if (stack_size < 3)
		solution = solve_stack_2(a);
	else if (!is_stack_sorted(*a))
	{
		//not push pb for stack size 4?
		pb(a, b, &solution);
		pb(a, b, &solution);
		if (!is_stack_sorted(*a))
			solution = ft_strjoin(solution, solve_stack_3(a));
		while (*b)
			push_to_sorted(a, b, &solution);
	}
	return (solution);
}

char	*sort_stack(t_stack **a, int stack_size, int sub_stack_size)
{
	t_stack	*b;

	b = 0;
	if (stack_size > 5)
		return (solve_6_to_100(a, &b, stack_size, sub_stack_size));
	if (stack_size <= 5)
		return (solve_5(a, &b, stack_size));
	return (NULL);
}
