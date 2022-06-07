/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:10:51 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/07 20:33:23 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack **stack, char **solution)
{
	exec_rot(stack);
	*solution = ft_joindel(*solution, "ra\n");
}

void	rb(t_stack **stack, char **solution)
{
	exec_rot(stack);
	*solution = ft_joindel(*solution, "rb\n");
}

void	rra(t_stack **stack, char **solution)
{
	exec_rrot(stack);
	*solution = ft_joindel(*solution, "rra\n");
}

void	rrb(t_stack **stack, char **solution)
{
	exec_rrot(stack);
	*solution = ft_joindel(*solution, "rrb\n");
}

void	pb(t_stack **a, t_stack **b, char **solution)
{
	exec_push(a, b);
	*solution = ft_joindel(*solution, "pb\n");
}
