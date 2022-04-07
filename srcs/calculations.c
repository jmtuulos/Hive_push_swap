/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:09:21 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/07 16:59:45 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	value_in_i(t_stack *stack, int index)
{
	if (!stack)
		return (0);
	while (index--)
		stack = stack->next;
	return (stack->value);
}

char	*solve_s3_helper(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	if ((*stack)->value > tmp->next->value)
	{
		if ((*stack)->value > tmp->value)
		{
			exec_rrot(stack);
			exec_rrot(stack);
			return (ft_strdup("rra\nrra\n"));
		}
		exec_rot(stack);
			return (ft_strdup("ra\n"));
	}
	exec_swap(stack);
	return (ft_strdup("sa\n"));
}
