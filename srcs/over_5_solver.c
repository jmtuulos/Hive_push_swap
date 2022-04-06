#include "pushswap.h"

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

// OLD VERSION
// int	choose_index(t_stack *stack, int *indices)
// {
// 	int	stack_size;

// 	if (indices[1] == -1)
// 		return (indices[0]);
// 	stack_size = calc_stack_size(stack);
// 	if (indices[0] > stack_size / 2)
// 		indices[0] = stack_size - indices[0];
// 	else if (indices[1] > stack_size / 2)
// 		indices[1] = stack_size - indices[1];
// 	if (indices[1] < indices[0])
// 		return(indices[1]);
// 	return (indices[0]);
// }


// FIXED VERSION:
int	choose_index(t_stack *stack, int *indices)
{
	int	stack_size;
	int	tmp_0;
	int	tmp_1;

	tmp_0 = indices[0];
	tmp_1 = indices[1];
	if (indices[1] == -1)
		return (indices[0]);
	stack_size = calc_stack_size(stack);
	if (indices[0] > stack_size / 2)
		tmp_0 = stack_size - indices[0];
	if (indices[1] > stack_size / 2)
		tmp_1 = stack_size - indices[1];
	if (tmp_1 < tmp_0)
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
	int	*rr_rrr;

	rr_rrr = (int *)malloc(sizeof(int) * 2);
	rr_rrr[0] = 0;
	rr_rrr[1] = 0;
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

void	rotate_index_to_top(t_stack **a, t_stack **b, char **solution, int rot_a)
{
	int	*rr_rrr;
	int	rot_b;
	int	ra_rra;
	int	index;

	rr_rrr = choice_rr_rrr(*a, *b, rot_a);
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
		while (rr_rrr[0] > 0)
		{
			if (rr_rrr[0]-- > 0)
				rr(a, b, solution);
			if (rr_rrr[1]-- > 0)
				rrr(a, b, solution);
			rot_a--;
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
	while (*b)
	{
		i = 0;
		count = 0;
		while (solution[i])
		{
			if (solution[i++] == '\n')
				count++;
		}
		rotate_highest_to_top_b(b, &solution);
		pa(a,b, &solution);
	}
	return(solution);
}

