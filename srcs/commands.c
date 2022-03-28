#include "pushswap.h"

void	ra(t_stack **stack, char **solution)
{
	exec_rot(stack);
	*solution = ft_strjoin(*solution, "ra\n");
}

void	rb(t_stack **stack, char **solution)
{
	exec_rot(stack);
	*solution = ft_strjoin(*solution, "rb\n");
}

void	rra(t_stack **stack, char **solution)
{
	exec_rrot(stack);
	*solution = ft_strjoin(*solution, "rra\n");
}

void	rrb(t_stack **stack, char **solution)
{
	exec_rrot(stack);
	*solution = ft_strjoin(*solution, "rrb\n");
}

void	sb(t_stack **stack, char **solution)
{
	exec_swap(stack);
	*solution = ft_strjoin(*solution, "sb\n");
}

void	sa(t_stack **stack, char **solution)
{
	exec_swap(stack);
	*solution = ft_strjoin(*solution, "sa\n");
}

void	ss(t_stack **a, t_stack **b, char **solution)
{
	exec_swap(a);
	exec_swap(b);
	*solution = ft_strjoin(*solution, "ss\n");
}

void	rrr(t_stack **a, t_stack **b, char **solution)
{
	exec_rrot(a);
	exec_rrot(b);
	*solution = ft_strjoin(*solution, "rrr\n");
}

void	pa(t_stack **a, t_stack **b, char **solution)
{
	exec_push(b, a);
	*solution = ft_strjoin(*solution, "pa\n");
}

void	pb(t_stack **a, t_stack **b, char **solution)
{
	exec_push(a, b);
	*solution = ft_strjoin(*solution, "pb\n");
}
