/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:11:40 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/07 21:27:31 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sb(t_stack **stack, char **solution)
{
	exec_swap(stack);
	*solution = join_n_del_first(*solution, "sb\n");
}

void	sa(t_stack **stack, char **solution)
{
	exec_swap(stack);
	*solution = join_n_del_first(*solution, "sa\n");
}

void	ss(t_stack **a, t_stack **b, char **solution)
{
	exec_swap(a);
	exec_swap(b);
	*solution = join_n_del_first(*solution, "ss\n");
}

void	rr(t_stack **a, t_stack **b, char **solution)
{
	exec_rot(a);
	exec_rot(b);
	*solution = join_n_del_first(*solution, "rr\n");
}

void	pa(t_stack **a, t_stack **b, char **solution)
{
	exec_push(b, a);
	*solution = join_n_del_first(*solution, "pa\n");
}
