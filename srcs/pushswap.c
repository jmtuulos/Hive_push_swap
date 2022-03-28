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

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		stack_size;
	char	*moves;
	char	**input;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		input = ft_strsplit(argv[1], ' ');
		argc = count_cells(input);
		validate_input(&a, argc - 1, input);
	}
	else
		validate_input(&a, argc - 2, &argv[1]);
	stack_size = calc_stack_sz(a);
	moves = sort_stack(&a, stack_size);
	if (moves)
		ft_putstr(moves);
	return (0);
}



