#include "pushswap.h"

void	wrong_answer()
{
	write(1, "KO\n", 3);
	exit(0);
}

int	count_cells(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
