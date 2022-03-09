#include "pushswap.h"

void	stack_sorted(t_stack *a, t_stack *b)
{
	int	nb;


	nb = a->value
	if (b || b->value != (char)0)
	{
		while(a)
		{
			a = a->next;
			if(!(nb > a->value))// continue here

	}





	{
		write(1, "KO\n", 3);
		exit(0);
	}
}

void	chk_rot(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp("ra\n", command))
		exec_rot(a);
	if else (!ft_strcmp("rb\n", command))
		exec_rot(b);
	if else (!ft_strcmp("rr\n", command))
	{
		exec_rot(b);
		exec_rot(a);
	}
	if else (!ft_strcmp("rra\n", command))
		exec_rrot(a);
	if else (!ft_strcmp("rrb\n", command))
		exec_rrot(b);
	if else (!ft_strcmp("rrr\n", command))
	{
		exec_rrot(b);
		exec_rrot(a);
	}
	else
		exec_error();
}

void	chk_swap(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp("sa\n", command))
		exec_swap(a);
	if else (!ft_strcmp("sb\n", command))
		exec_swap(b);
	if else (!ft_strcmp("ss\n", command))
	{
		exec_swap(a, b)
		exec_swap(a, b);
	}
	else
		exec_error();
}

void	stack_shuffle(t_stack **a, t_stack **b, char *command)
{
	if (*command == 's')
		chk_swap(a, b, command);
	if else (*command == 'r')
		chk_rot(a, b, command);
	if else (!ft_strcmp("pa\n", command))
		exec_push(a, b);
	if else (!ft_strcmp("pb\n", command))
		exec_push(b, a);
	else
		exec_error(a, b);
}

int	main(int argc, char **argv)
{
	char	**line;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = new_node((char)0);
 	validate_input(&a, argc, argv);
	b = new_node((char)0);
	while (get_next_line(0, &line) > 0)
		stack_shuffle(&a, &b, *line); // validation should exit() and free stacks if fails
	stack_sorted(a,b); // checking if a is sorted and b is empty
	return (0);
}
