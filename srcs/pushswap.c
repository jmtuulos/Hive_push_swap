/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:23:10 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/13 20:42:42 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*best_solution(char **choices, int amount)
{
	int	i;
	int	count;
	int	best_count;
	int	best_index;

	best_index = 0;
	best_count = MAX_NUMBER;
	while (amount >= 0)
	{
		count = 0;
		i = 0;
		while (choices[amount][i])
			if (choices[amount][i++] == '\n')
				count++;
		if (best_count > count)
		{
			best_index = amount;
			best_count = count;
		}
		amount--;
	}
	return (free_choices(choices, best_index));
}

char	**allocate_array(void)
{
	char	**try_arr;

	try_arr = (char **)malloc(sizeof(char *) * TRY_SOLUTIONS + 1);
	if (!try_arr)
		exit(-1);
	try_arr[TRY_SOLUTIONS + 1] = NULL;
	return (try_arr);
}

char	*compare_solutions(t_stack **a, char **input)
{
	int		tries;
	int		size;
	char	**try_arr;
	int		sub_stack_size;

	size = calc_stack_size(*a);
	sub_stack_size = STACK_SZ_6_TO_100;
	if (size > 100)
		sub_stack_size = STACK_SZ_OVER_100;
	tries = TRY_SOLUTIONS;
	if (size <= 5)
	{
		free(free_choices(input, 0));
		return (sort_stack(a, size, 0));
	}
	try_arr = allocate_array();
	while (tries--)
	{
		del_stack(*a);
		*a = 0;
		create_stack(a, size, input);
		try_arr[tries] = sort_stack(a, calc_stack_size(*a), sub_stack_size--);
	}
	free(free_choices(input, 0));
	return (best_solution(try_arr, TRY_SOLUTIONS - 1));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	*moves;
	char	**input;

	if (argc < 2)
		return (0);
	if (argc == 2)
		input = ft_strsplit(argv[1], ' ');
	else
		input = allocate_starting_array(argv, argc - 1);
	argc = count_cells(input);
	validate_input(&a, argc, input);
	if (!*input)
		error();
	moves = compare_solutions(&a, input);
	del_stack(a);
	if (moves)
		ft_putstr(moves);
	free(moves);
	return (0);
}
