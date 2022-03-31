#include "pushswap.h"
#include <stdio.h>

void	wrong_answer()
{
	write(1, "KO\n", 3);
	exit(0);
}

void	stack_sorted(t_stack *a, t_stack *b)
{
	int	nb;

	if (b)
		wrong_answer();
	while(a->next)
	{
		nb = a->value;
		a = a->next;
		if(nb > a->value)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
	}
	write(1, "OK\n", 3);
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
	else if(*command == 'r')
		chk_rot(a, b, command);
	else if (!ft_strcmp("pa", command))
		exec_push(b, a);
	else if (!ft_strcmp("pb", command))
		exec_push(a, b);
	else
		exec_error(b, a);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;
	char	**input;

	input = argv;
	b = 0;
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
		validate_input(&a, argc - 2, input);
	while (get_next_line(0, &line) > 0)
		stack_shuffle(&a, &b, line); // validation should exit() and free stacks if fails
	stack_sorted(a, b); // checking if a is sorted and b is empty
	return (0);
}
