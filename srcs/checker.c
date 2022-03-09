#include "pushswap.h"

void	error()
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	//char	**line;
	int		size;
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = new_node((char)0);
 	validate_input(&a, argc, argv);
	// a = malloc_stack(argc - 1);
	size = 0;
	// while (get_next_line(0, &line) > 0)
	// {
	// 	validate_line();
	// }
	// checker(a,argc - 1);
	return (0);
}
