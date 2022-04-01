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

int	max_of_stack(t_stack *a, int stack_size)
{
	t_stack	*tmp;
	int		max_of_stack;
	int		reference;

	tmp = a;
	reference = find_smallest_value(a) - 1; // Could cause problems if smallest is negative?
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
	int	first;
	int	last;

	if (indices[1] == -1)
		return (indices[0]);
	stack_size = calc_stack_size(stack);
	first = indices[0];
	last = indices[1];
	if (indices[0] > stack_size / 2)
		first = stack_size - indices[0];
	else if (indices[1] > stack_size / 2)
		last = stack_size - indices[1];
	if (last < first)
		return(indices[1]);
	return (indices[0]);
}

int	find_ends_in_range(t_stack *stack, int max_of_range)
{
	t_stack	*tmp;
	int		*top_bottom;
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
	top_bottom[1] = -1; //-------------------- To prevent it being 0 when not matches is found
	while (tmp)
	{
		if (tmp->value <= max_of_range)
			top_bottom[1] = i;
		tmp = tmp->next;
		i++;
	}
	i = choose_index(stack, top_bottom);
	free (top_bottom);
	return (i);
}

int	*choice_rr_rrr(t_stack *a, t_stack *b, int i_a)
{
	int	i_b;
	int	to_top;
	int	to_bottom;
	int	lowest;
	int	*rr_rrr;

	rr_rrr = (int *)malloc(sizeof(int) * 2);
	rr_rrr[0] = 0;
	rr_rrr[1] = 0;
	i_b = location_in_reverse_sorted(b, value_in_index(a, i_a));
	// calculate how many rotations to top and how many rotations to bottom, take the highest
	to_top = i_a;
	to_bottom = calc_stack_size(a) - i_a;
	if (i_b > to_top)
		to_top = i_b;
	if (to_bottom < calc_stack_size(b) - i_b)
		to_bottom = calc_stack_size(b) - i_b;
	rr_rrr[1] = to_bottom;
	rr_rrr[0] = to_top;
	return (rr_rrr);
}

int	get_rotation_from_index(t_stack *stack, int index)
{
	if (index > calc_stack_size(stack) / 2)
		return (calc_stack_size(stack) - index);
	return (index);
}

void	rotate_index_to_top(t_stack **a, t_stack **b, char **solution, int rot_a)
{
	int	*rr_rrr;
	int	rotations;
	int	rot_b;
	int	ra_rra;
	int	index;

	rr_rrr = choice_rr_rrr(*a, *b, rot_a);
	rot_b = location_in_reverse_sorted(*b, value_in_index(*a, rot_a));
	ra_rra = rot_a > calc_stack_size(*a) / 2;
	rot_a = get_rotation_from_index(*a, rot_a);
	rot_b = get_rotation_from_index(*b, rot_b);
	if (rot_a + rot_b > rr_rrr[0] || rot_a + rot_b > rr_rrr[1])
	{
		ra_rra = rr_rrr[0] >= rr_rrr[1];
		while (rot_b > 0 && rot_a > 0)
		{
			if (!ra_rra)
				rr(a, b, solution);
			if (ra_rra)
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
	free (rr_rrr);
}

void	push_to_reverse_sorted(t_stack **b, t_stack **a, char **solution, int closest_index)
{
	int	dest_index;
	int	stack_size;

	rotate_index_to_top(a, b, solution, closest_index);
	stack_size = calc_stack_size(*b);
	if (find_highest_value(*b) < (*a)->value)
		dest_index = find_highest(*b);
	else if (find_smallest_value(*b) > (*a)->value)
		dest_index = find_smallest(*b);
	else
		dest_index = location_in_reverse_sorted(*b, (*a)->value);
	if (stack_size / 2 >= dest_index)
		*solution = ft_strjoin(*solution, push_from_top_b(b, a, dest_index));
	else
		*solution = ft_strjoin(*solution, push_from_bottom_b(b, a, dest_index, stack_size));
	// rotate_highest_to_top_b(b, solution);
}

void	move_next_in_range(t_stack **a, t_stack **b, char **solution, int max_of_range)
{
	int	closest_index;
	int	index;
	int	stack_size;

	stack_size = calc_stack_size(*a);
	closest_index = find_ends_in_range(*a, max_of_range);
	push_to_reverse_sorted(b, a, solution, closest_index);
}

char	*solve_6_to_100(t_stack **a, t_stack **b, int stack_size, int sub_stack_size)
{
	int		max_of_range;
	char	*solution;
	int		range_size;


	solution = ft_strnew(0);
	if (is_stack_sorted(*a))
		return (solution);
	while (*a)
	{
		if (sub_stack_size <= calc_stack_size(*a))
			range_size = sub_stack_size;
		else
			range_size = calc_stack_size(*a);
		max_of_range = max_of_stack(*a, range_size);
		while (range_size--)
			move_next_in_range(a, b, &solution, max_of_range);
	}
	int i; //test
	int count;//test
	printf("stuck after here?");
	while (*b)
	{
		// i = 0;
		// count = 0;
		// while (solution[i])
		// {
		// 	if (solution[i++] == '\n')
		// 		count++;
		// }
		rotate_highest_to_top_b(b, &solution);
		pa(a,b, &solution);
	}
	return(solution);
}

