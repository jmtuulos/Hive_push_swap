/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:10:51 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/07 21:27:27 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack **stack, char **solution)
{
	exec_rot(stack);
	*solution = join_n_del_first(*solution, "ra\n");
}

void	rb(t_stack **stack, char **solution)
{
	exec_rot(stack);
	*solution = join_n_del_first(*solution, "rb\n");
}

void	rra(t_stack **stack, char **solution)
{
	exec_rrot(stack);
	*solution = join_n_del_first(*solution, "rra\n");
}

void	rrb(t_stack **stack, char **solution)
{
	exec_rrot(stack);
	*solution = join_n_del_first(*solution, "rrb\n");
}

void	pb(t_stack **a, t_stack **b, char **solution)
{
	exec_push(a, b);
	*solution = join_n_del_first(*solution, "pb\n");
}
