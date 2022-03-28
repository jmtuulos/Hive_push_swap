#include "pushswap.h"

char	*push_from_top_b(t_stack **b, t_stack **a, int index)
{
	char	*ret;
	int		i;

	ret = ft_strnew(0);
	if (index == 0)
	{
		pb(a, b, &ret);
		return (ret);
	}
	i = index;
	while (i-- > 1)
		rb(b, &ret);
	pb(a, b, &ret);
	sb(b, &ret);
	while (++i < index)
		rrb(b, &ret);
	return (ret);
}

char	*push_from_bottom_b(t_stack **b, t_stack **a, int index, int stack_size)
{
	char	*ret;
	int		i;

	i = index;
	ret = ft_strnew(0);
	while (stack_size > i++)
		rrb(b, &ret);
	pb(a,b, &ret);
	while (stack_size > index++)
		rb(b, &ret);
	rb(b, &ret);
	return (ret);
}

int	find_smallest(t_stack *stack)
{
	int	smallest;

	smallest = stack->value;
	while (stack->next)
	{
		if (smallest > stack->next->value)
			smallest = stack->next->value;
		stack = stack->next;
	}
	return (smallest);
}

int	max_of_stack(t_stack *a, int stack_size)
{
	t_stack	*tmp;
	int		max_of_stack;
	int		reference;

	tmp = a;
	reference = find_smallest(a) - 1; // Could cause problems if smallest is negative?
	while (stack_size--)
	{
		max_of_stack = MAX_NUMBER;
		tmp = a;
		while (tmp)
		{
			if (max_of_stack > tmp->value && tmp->value > reference)
				max_of_stack = tmp->value;
			tmp = tmp->next;
		}
		reference = max_of_stack;
	}
	return (max_of_stack);
}

int	*find_ends_in_range(t_stack *stack, int *top_bottom, int max_of_range)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	top_bottom = (int *)malloc(sizeof(int) * 2);
	while (tmp)
	{
		if (tmp->value <= max_of_range)
		{
			tmp = tmp->next;
			top_bottom[0] = i;
			i++;
			break;
		}
		tmp = tmp->next;
		i++;
	}
	while (tmp)
	{
		if (tmp->value <= max_of_range)
			top_bottom[1] = i;
		tmp = tmp->next;
		i++;
	}
	return (top_bottom);
}

void	rotate_index_to_top(t_stack **stack, char **solution, int index, int stack_size)
{
	int	i;

	i = index;
	while (i--)
	{
		if (stack_size / 2 >= index)
			ra(stack, solution);
		else
			rra(stack, solution);
	}
}

void	push_to_reverse_sorted(t_stack **b, t_stack **a, char **solution)
{
	int	index;
	int	stack_size;

	stack_size = calc_stack_size(*b);
	index = location_in_reverse_sorted(*b, (*a)->value);
	if (stack_size / 2 >= index)
		*solution = ft_strjoin(*solution, push_from_top_b(b, a, index));
	else
		*solution = ft_strjoin(*solution, push_from_bottom_b(b, a, index, stack_size));
}

void	move_next_in_range(t_stack **a, t_stack **b, char **solution, int max_of_range)
{
	int	*top_bottom;
	int	index;
	int	stack_size;

	stack_size = calc_stack_size(*a);
	top_bottom = find_ends_in_range(*a, top_bottom, max_of_range);
	if (top_bottom[0] < stack_size - top_bottom[1])
		rotate_index_to_top(a, solution, top_bottom[0], stack_size);
	else
		rotate_index_to_top(a, solution, top_bottom[1], stack_size);
	push_to_reverse_sorted(b, a, solution);
}

char	*solve_6_to_100(t_stack **a, t_stack **b, int stack_size)
{
	int		max_of_range;
	char	*solution;
	int		range_size;


	solution = ft_strnew(0);
	if (is_stack_sorted(*a))
		return (solution);
	while (*a)
	{
		if (STACK_SZ_6_TO_100 <= calc_stack_size(*a))
			range_size = STACK_SZ_6_TO_100;
		else
			range_size = calc_stack_size(*a);
		max_of_range = max_of_stack(*a, range_size);
		while (range_size--)
			move_next_in_range(a, b, &solution, max_of_range);
	}
	while (*b)
		pa(a,b, &solution);
	return(solution);
}

