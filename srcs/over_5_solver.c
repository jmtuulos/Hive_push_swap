#include "pushswap.h"
#include "stdio.h" //testing

void	rotate_highest_to_top_b(t_stack **stack, char **solution)
{
	int	highest;
	int	stack_size;

	stack_size = calc_stack_size(*stack);
	highest = find_highest(*stack);
	if (highest < stack_size / 2)
	{
		while (highest--)
			rb(stack, solution);
	}
	else
	{
		highest = stack_size - highest;
		while (highest--)
			rrb(stack, solution);
	}

}

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

int	choose_index(t_stack *stack, int *indices)
{
	int	stack_size;

	stack_size = calc_stack_size(stack);
	if (indices[0] < stack_size - indices[1])
		return (indices[0]);
	else
		return (indices[1]);
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

int	*choice_rr_rrr(t_stack *a, t_stack *b, int *indices)
{
	int	i_a;
	int	i_b;
	int	*rr_rrr;

	rr_rrr = (int *)malloc(sizeof(int) * 2);
	rr_rrr[0] = 0;
	rr_rrr[1] = 0;
	i_a = choose_index(a, indices);
	i_b = location_in_reverse_sorted(b, value_in_index(a, i_a));
	if (i_b > calc_stack_size(b) / 2 && i_a > calc_stack_size(a) / 2)
	{
		if (i_b > i_a)
			rr_rrr[1] = calc_stack_size(b) - i_b;
		else
			rr_rrr[1] = calc_stack_size(a) - i_a;
	}
	else if (i_b < calc_stack_size(b) / 2 && i_a < calc_stack_size(a) / 2)
	{
		if (i_b < i_a)
			rr_rrr[0] = i_b;
		else
			rr_rrr[0] = i_a;
	}
	return (rr_rrr);
}

int	nb_of_rotations(t_stack *a, t_stack *b, int rot_a, int rot_b)
{
	if (rot_a > calc_stack_size(a) - rot_a)
		rot_a = calc_stack_size(a) - rot_a;
	if (rot_b > calc_stack_size(b) - rot_b)
		rot_b = calc_stack_size(b) - rot_b;
	return (rot_a + rot_b);

}

void	rotate_index_to_top(t_stack **a, t_stack **b, char **solution, int *indices)
{
	int	*rr_rrr;
	int	rot_a;
	int	rot_b;
	int	ra_rra;
	int	index;

	rr_rrr = choice_rr_rrr(*a, *b, indices); 	// amount of moves combined
	rot_a = choose_index(*a, indices); 			// The index that needs to be on top
	rot_b = location_in_reverse_sorted(*b, value_in_index(*a, rot_a));
	ra_rra = 0;
	if (rot_a > calc_stack_size(*a) / 2)
	{
		rot_a = calc_stack_size(*a) - rot_a;
		ra_rra = 1;
	}
	if (rot_b > calc_stack_size(*b) / 2)
		rot_b = calc_stack_size(*b) - rot_b;
	if ((rot_a + rot_b > rr_rrr[0] && rr_rrr[0] > 0) || (rr_rrr[1] > 0 && rot_a + rot_b > rr_rrr[1]))
	{
		while (rr_rrr[0] > 0 || rr_rrr[1] > 0)
		{
			if (rr_rrr[0]-- > 0)
				rr(a, b, solution);
			if (rr_rrr[1]-- > 0)
				rrr(a, b, solution);
			rot_a--;
			rot_b--;
		}
	}
	while (rot_a > 0)
	{
		if (!ra_rra)
			ra(a, solution);
		else
			rra(a, solution);
		rot_a--;
	}
}

void	push_to_reverse_sorted(t_stack **b, t_stack **a, char **solution, int *top_bottom)
{
	int	dest_index;
	int	stack_size;

	rotate_index_to_top(a, b, solution, top_bottom);
	stack_size = calc_stack_size(*b);
	dest_index = location_in_reverse_sorted(*b, (*a)->value); // needs to work without the stack being in order
	if (stack_size / 2 >= dest_index)
		*solution = ft_strjoin(*solution, push_from_top_b(b, a, dest_index));
	else
		*solution = ft_strjoin(*solution, push_from_bottom_b(b, a, dest_index, stack_size));
	// rotate_highest_to_top_b(b, solution);
}

void	move_next_in_range(t_stack **a, t_stack **b, char **solution, int max_of_range)
{
	int	*top_bottom;
	int	index;
	int	stack_size;

	stack_size = calc_stack_size(*a);
	top_bottom = find_ends_in_range(*a, top_bottom, max_of_range);
	push_to_reverse_sorted(b, a, solution, top_bottom);
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
	{
		rotate_highest_to_top_b(b, &solution);
		pa(a,b, &solution);
	}
	return(solution);
}

