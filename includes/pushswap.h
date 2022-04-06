/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:01:19 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/06 16:18:01 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# define MAX_NUMBER 2147483647
# define MIN_NUMBER -2147483648
# define STACK_SZ_6_TO_100 20
# define STACK_SZ_OVER_100 50
# define TRY_SOLUTIONS 10

//with string : "29 21 92 91 67 54 30 99 53 89 60 40 63 79 15 13 24 96 41 84 75 82 43 17 7 31 93 52 14 59 70 11 33 37 10 87 97 56 88 62 16 57 25 3 66 42 80 9 74 95 19 39 23 49 69 71 1 27 35 61 90 76 18 8 78 51 48 46 45 83 20 6 58 47 81 2 73 5 85 72 65 12 68 26 64 50 94 44 77 28 55 32 34 98 0 36 86 4 22 38"
//For 100: 12 resulted in 700 moves
//For 100: 1 resulted in 1501 moves
//For 100: 16 resulted in 658 moves
//For 100: 17 resulted in 691 moves
//For 100: 18 resulted in 698 moves
//For 100: 19 resulted in 657 moves-------- The best so far

// Could we try out different stack sizes until best found?


//For 500: 26 resulted in 7855 moves
//For 500: 27 resulted in 17855 moves-- Weird
//For 500: 28 resulted in 7852 moves
//For 500: 29 resulted in 7548 moves
//For 500: 30 resulted in 10933 moves
//For 500: 41 resulted in 10933 moves
//For 500: 42 resulted in 7290 moves
//For 500: 44 resulted in 7147 moves -------- The best so far

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

void			wrong_answer();
int				find_smallest(t_stack *stack);
int				find_smallest_value(t_stack *stack);
int 			find_highest_value(t_stack *stack);
int				create_stack(t_stack **a, int size, char **argv);
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
char			*solve_6_to_100(t_stack **a, t_stack **b, int stack_size, int sub_stack_size);
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
char			*sort_stack(t_stack **a, int stack_size, int sub_stack_size);
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
