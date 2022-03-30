/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:01:19 by jheiskan          #+#    #+#             */
/*   Updated: 2022/03/29 23:19:07 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# define MAX_NUMBER 2147483647
# define MIN_NUMBER -2147483648
# define STACK_SZ_6_TO_100 30

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

int				find_highest(t_stack *stack);
int				is_stack_reverse_sorted(t_stack *stack);
void			rr(t_stack **a, t_stack **b, char **solution);
int				count_cells(char **array);
int				value_in_index(t_stack *stack, int index);
char			*push_from_bottom(t_stack **a, t_stack **b, int index, int stack_size);
char			*push_from_top(t_stack **a, t_stack **b, int index);
int				location_in_reverse_sorted(t_stack *stack, int value);
int				is_stack_sorted(t_stack *stack);
int				calc_stack_size(t_stack *stack);
void			push_to_sorted(t_stack **to, t_stack **from, char **solution);
char			*solve_6_to_100(t_stack **a, t_stack **b, int stack_size);
void			exec_error(t_stack **a, t_stack **b);
void			exec_swap(t_stack **stack);
void			exec_push(t_stack **from, t_stack **dest);
void			exec_rrot(t_stack **stack);
void			exec_rot(t_stack **stack);
void			add_to_end(t_stack **a, int value);
void			del_stack(t_stack *stack);
void			error();
t_stack			*new_node(int value);
long long int	ft_atoi_long(const char *str);
void			validate_input(t_stack **a, int size, char **argv);
void			add_to_start(t_stack **a, int value);
int				get_next_line(const int fd, char **line);
char			*sort_stack(t_stack **a, int stack_size);
void			ra(t_stack **stack, char **solution);
void			rb(t_stack **stack, char **solution);
void			rra(t_stack **stack, char **solution);
void			rrb(t_stack **stack, char **solution);
void			sb(t_stack **stack, char **solution);
void			sa(t_stack **stack, char **solution);
void			ss(t_stack **a, t_stack **b, char **solution);
void			rrr(t_stack **a, t_stack **b, char **solution);
void			pa(t_stack **a, t_stack **b, char **solution);
void			pb(t_stack **a, t_stack **b, char **solution);
int				location_in_sorted(t_stack *stack, int value);

#endif
