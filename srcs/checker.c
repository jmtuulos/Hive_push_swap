/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:09:41 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/13 16:33:01 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_sorted(char **input, t_stack *a, t_stack *b)
{
	int	nb;

	if (b)
		wrong_answer(input);
	while (a->next)
	{
		nb = a->value;
		a = a->next;
		if (nb > a->value)
			wrong_answer(input);
	}
	write(1, "OK\n", 3);
	del_stack(a);
	free(free_choices(input, 0));
	exit(0);
}

void	chk_rot(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp("ra", command))
		exec_rot(a);
	else if (!ft_strcmp("rb", command))
		exec_rot(b);
	else if (!ft_strcmp("rr", command))
	{
		exec_rot(b);
		exec_rot(a);
	}
	else if (!ft_strcmp("rra", command))
		exec_rrot(a);
	else if (!ft_strcmp("rrb", command))
		exec_rrot(b);
	else if (!ft_strcmp("rrr", command))
	{
		exec_rrot(b);
		exec_rrot(a);
	}
	else
		exec_error(a, b);
}

void	chk_swap(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp("sa", command))
		exec_swap(a);
	else if (!ft_strcmp("sb", command))
		exec_swap(b);
	else if (!ft_strcmp("ss", command))
	{
		exec_swap(a);
		exec_swap(b);
	}
	else
		exec_error(a, b);
}

void	stack_shuffle(t_stack **a, t_stack **b, char *command)
{
	if (*command == 's')
		chk_swap(a, b, command);
	else if (*command == 'r')
		chk_rot(a, b, command);
	else if (!ft_strcmp("pa", command))
		exec_push(b, a);
	else if (!ft_strcmp("pb", command))
		exec_push(a, b);
	else
		exec_error(b, a);
	free(command);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;
	char	**input;

	b = 0;
	a = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
		input = ft_strsplit(argv[1], ' ');
	else
		input = allocate_starting_array(argv, argc - 1);
	argc = count_cells(input);
	if (argc == 0)
		return (0);
	validate_input(&a, argc, input);
	while (get_next_line(0, &line) > 0)
		stack_shuffle(&a, &b, line);
	stack_sorted(input, a, b);
	return (0);
}
