/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_5_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:30:09 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/07 20:33:00 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*choice_rr_rrr(t_stack *a, t_stack *b, int i_a)
{
	int	i_b;
	int	*rr_rrr;

	rr_rrr = (int *)malloc(sizeof(int) * 2);
	rr_rrr[0] = 0;
	rr_rrr[1] = 0;
	i_b = index_in_r_sorted(b, value_in_i(a, i_a));
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

void	rotate_a(t_stack **a, int rot, int ra_rra, char **ret)
{
	while (rot > 0)
	{
		if (!ra_rra)
			ra(a, ret);
		else
			rra(a, ret);
		rot--;
	}
}

void	rotate_index_to_top(t_stack **a, t_stack **b, char **ret, int rot_a)
{
	int	*rr_rrr;
	int	rot_b;
	int	ra_rra;

	rr_rrr = choice_rr_rrr(*a, *b, rot_a);
	ra_rra = rot_a > calc_stack_size(*a) / 2;
	rot_b = distance_to_edges(*b, index_in_r_sorted(*b, value_in_i(*a, rot_a)));
	rot_a = distance_to_edges(*a, rot_a);
	if ((rot_a + rot_b > rr_rrr[0] && rr_rrr[0] > 0) || \
	(rr_rrr[1] > 0 && rot_a + rot_b > rr_rrr[1]))
	{
		while (rr_rrr[0] > 0 || rr_rrr[1] > 0)
		{
			if (rr_rrr[0]-- > 0)
				rr(a, b, ret);
			if (rr_rrr[1]-- > 0)
				rrr(a, b, ret);
			rot_a--;
		}
	}
	rotate_a(a, rot_a, ra_rra, ret);
	free (rr_rrr);
}

void	push_to_r_sorted(t_stack **b, t_stack **a, char **solution, int index)
{
	int	dest_i;
	int	size;

	rotate_index_to_top(a, b, solution, index);
	size = calc_stack_size(*b);
	if (!(*a))
		dest_i = 0;
	else
		dest_i = index_in_r_sorted(*b, (*a)->value);
	if (size / 2 >= dest_i)
		*solution = ft_joindel(*solution, push_top_b(b, a, dest_i));
	else
		*solution = ft_joindel(*solution, push_bottom_b(b, a, dest_i, size));
}

void	move_next_in_range(t_stack **a, t_stack **b, char **ret, int max_range)
{
	int	closest_index;

	closest_index = find_ends_in_range(*a, max_range);
	push_to_r_sorted(b, a, ret, closest_index);
}
