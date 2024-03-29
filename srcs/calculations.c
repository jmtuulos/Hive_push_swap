/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:09:21 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/08 11:25:42 by jheiskan         ###   ########.fr       */
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
		if (tmp->value > tmp->next->value)
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
