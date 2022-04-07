/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:32:06 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/06 20:39:33 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*push_top_b(t_stack **b, t_stack **a, int index)
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

char	*push_bottom_b(t_stack **b, t_stack **a, int index, int stack_size)
{
	char	*ret;
	int		i;

	i = index;
	ret = ft_strnew(0);
	while (stack_size > i++)
		rrb(b, &ret);
	pb(a, b, &ret);
	return (ret);
}

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
		return (indices[1]);
	return (indices[0]);
}

int	find_ends_in_range(t_stack *stack, int max_of_range)
{
	int		*top_bottom;
	int		i;
	t_stack	*tmp;
	int		first_found;

	i = 0;
	tmp = stack;
	first_found = 0;
	top_bottom = (int *)malloc(sizeof(int) * 2);
	top_bottom[1] = -1;
	while (stack)
	{
		if (stack->value <= max_of_range && !first_found)
		{
			top_bottom[0] = i;
			first_found = 1;
		}
		if (stack->value <= max_of_range)
			top_bottom[1] = i;
		stack = stack->next;
		i++;
	}
	i = choose_index(tmp, top_bottom);
	free (top_bottom);
	return (i);
}
