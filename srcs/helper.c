/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:13:04 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/09 19:33:19 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	wrong_answer(void)
{
	write(1, "KO\n", 3);
	exit(0);
}

int	count_cells(char **array)
{
	int	i;

	i = 0;
	if (!array || !*array)
		exit(-1);
	while (array[i])
		i++;
	return (i);
}

int	location_in_sorted(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value > value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
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

int	max_of_stack(t_stack *a, int stack_size)
{
	t_stack	*tmp;
	int		max_of_stack;
	int		reference;

	tmp = a;
	reference = find_smallest_value(a) - 1;
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
