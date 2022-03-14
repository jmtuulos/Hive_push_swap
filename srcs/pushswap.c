#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		stack_size;
	char	*moves;

	if (argc < 2)
		return (0);
	validate_input(&a, argc, argv);
	stack_size = calc_stack_sz(a);
	moves = sort_stack(&a, stack_size);
	if (moves)
		ft_putstr(moves);
	return (0);
}



