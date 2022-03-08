#include "ft_pushswap.h"

int	chk_duplicates(int size, char **argv)
{
	int	i;
	while (size > 0)
	{
		i = size - 1;
		while (i != 0)
		{
			if (!ft_strcmp(argv[size], argv[i--]))
				return (0);
		}
		size--;
	}
	return (1);
}

int	chk_int(int size, char **argv)
{
	long int	number;
	while (size > 0)
	{
		if (ft_strlen(argv[size]) > 11)
			return (0);
		number = ft_atoi_long(argv[size]);
		if (number > MAX_NUMBER || number < MIN_NUMBER)
			return (0);
		size--;
	}
	return (1);
}

int	validate_input(int size, char **argv)
{
	size -= 1;
	if (!chk_int(size, argv) || !chk_duplicates(size, argv))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!validate_input(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	
	return (0);
}
