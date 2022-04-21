/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:14:55 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/21 15:24:12 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		if (stack_size == 5)
			pb(a, b, &solution);
		pb(a, b, &solution);
		if (!is_stack_sorted(*a))
			solution = ft_strjoin(solution, solve_stack_3(a));
		while (*b)
			push_to_sorted(a, b, &solution);
	}
	return (solution);
}

char	*solve_over_6(t_stack **a, t_stack **b, int stack_size, int sub_stack)
{
	int		max_of_range;
	char	*solution;
	int		range_size;

	solution = ft_strnew(0);
	if (is_stack_sorted(*a))
		return (solution);
	while (*a)
	{
		if (sub_stack <= calc_stack_size(*a))
			range_size = sub_stack;
		else
			range_size = calc_stack_size(*a);
		max_of_range = max_of_stack(*a, range_size);
		while (range_size--)
			move_next_in_range(a, b, &solution, max_of_range);
	}
	while (*b)
	{
		rotate_highest_to_top_b(b, &solution);
		pa(a, b, &solution);
	}
	return (solution);
}

char	*sort_stack(t_stack **a, int stack_size, int sub_stack_size)
{
	t_stack	*b;

	b = 0;
	if (stack_size == 1)
		return (NULL);
	if (stack_size > 5)
		return (solve_over_6(a, &b, stack_size, sub_stack_size));
	if (stack_size <= 5)
		return (solve_5(a, &b, stack_size));
	return (NULL);
}
