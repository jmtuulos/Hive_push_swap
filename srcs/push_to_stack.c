/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:17:17 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/08 10:57:06 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*push_bottom(t_stack **a, t_stack **b, int index, int stack_size)
{
	char	*ret;
	int		i;

	i = index;
	ret = ft_strnew(0);
	if (!ret)
		exit(-1);
	while (stack_size > i++)
		rra(a, &ret);
	pa(a, b, &ret);
	while (stack_size > index++)
		ra(a, &ret);
	ra(a, &ret);
	return (ret);
}

char	*push_top(t_stack **a, t_stack **b, int index)
{
	char	*ret;
	int		i;

	ret = ft_strnew(0);
	if (!ret)
		exit(-1);
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
	int	size;

	size = calc_stack_size(*to);
	index = location_in_sorted(*to, (*from)->value);
	if (size / 2 >= index)
		*solution = ft_joindel(*solution, push_top(to, from, index));
	else
		*solution = ft_joindel(*solution, push_bottom(to, from, index, size));
}
