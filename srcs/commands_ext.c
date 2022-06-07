/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:11:40 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/07 20:33:30 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sb(t_stack **stack, char **solution)
{
	exec_swap(stack);
	*solution = ft_joindel(*solution, "sb\n");
}

void	sa(t_stack **stack, char **solution)
{
	exec_swap(stack);
	*solution = ft_joindel(*solution, "sa\n");
}

void	ss(t_stack **a, t_stack **b, char **solution)
{
	exec_swap(a);
	exec_swap(b);
	*solution = ft_joindel(*solution, "ss\n");
}

void	rr(t_stack **a, t_stack **b, char **solution)
{
	exec_rot(a);
	exec_rot(b);
	*solution = ft_joindel(*solution, "rr\n");
}

void	pa(t_stack **a, t_stack **b, char **solution)
{
	exec_push(b, a);
	*solution = ft_joindel(*solution, "pa\n");
}
