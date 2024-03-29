/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:22:10 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/13 20:13:50 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	exec_error(t_stack **a, t_stack **b)
{
	del_stack(*a);
	del_stack(*b);
	error();
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	chk_duplicates(int size, char **argv)
{
	int	i;

	size--;
	while (size > 0)
	{
		i = size - 1;
		while (i >= 0)
		{
			if (!ft_strcmp(argv[size], argv[i--]))
				return (0);
		}
		size--;
	}
	return (1);
}

int	create_stack(t_stack **a, int size, char **argv)
{
	long int	number;
	int			i;

	size -= 1;
	while (size >= 0)
	{
		i = 0;
		if (argv[size][i] == '-' || argv[size][i] == '+')
			i++;
		if (argv[size][i] == '\0')
			return (0);
		while (argv[size][i] != '\0')
		{
			if (!ft_isdigit(argv[size][i]) || i > 10)
				return (0);
			i++;
		}
		number = ft_atoi_long(argv[size]);
		if (number > MAX_NUMBER || number < MIN_NUMBER)
			return (0);
		add_to_start(a, number);
		size--;
	}
	return (1);
}

void	validate_input(t_stack **a, int size, char **argv)
{
	*a = NULL;
	if (!create_stack(a, size, argv) || !chk_duplicates(size, argv))
	{
		del_stack(*a);
		error();
	}
}
