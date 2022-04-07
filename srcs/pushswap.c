/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:23:10 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/07 17:27:38 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	calc_stack_sz(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

char	*best_solution(char **choices, int amount)
{
	int	i;
	int	count;
	int	best_count;
	int	best_index;

	best_index = 0;
	amount--;
	best_count = MAX_NUMBER;
	while (amount >= 0)
	{
		count = 0;
		i = 0;
		while (choices[amount][i])
		{
			if (choices[amount][i++] == '\n')
				count++;
		}
		if (best_count > count)
		{
			best_index = amount;
			best_count = count;
		}
		amount--;
	}
	return (choices[best_index]);
}

char	*compare_solutions(t_stack **a, char **input)
{
	int		tries;
	int		i;
	int		size;
	char	**try_arr;
	int		sub_stack_size;

	size = count_cells(input);
	sub_stack_size = STACK_SZ_6_TO_100;
	if (calc_stack_size(*a) > 100)
		sub_stack_size = STACK_SZ_OVER_100;
	tries = TRY_SOLUTIONS;
	try_arr = (char **)malloc(tries);
	if (size <= 5)
		return (sort_stack(a, size, 0));
	i = 0;
	while (tries--)
	{
		del_stack(*a);
		*a = 0;
		create_stack(a, size, input);
		try_arr[i++] = sort_stack(a, calc_stack_size(*a), sub_stack_size--);
	}
	return (best_solution(try_arr, TRY_SOLUTIONS));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	*moves;
	char	**input;
	int		sub_stack_size;

	if (argc < 2)
		return (0);
	input = &argv[1];
	if (argc == 2)
	{
		input = ft_strsplit(argv[1], ' ');
		argc = count_cells(input);
		validate_input(&a, argc, input);
	}
	else
		validate_input(&a, argc - 1, input);
	if (!*input)
		error();
	moves = compare_solutions(&a, input);
	if (moves)
		ft_putstr(moves);
	return (0);
}
