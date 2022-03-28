#include "pushswap.h"

int	count_cells(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
