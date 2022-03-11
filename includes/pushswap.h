/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:01:19 by jheiskan          #+#    #+#             */
/*   Updated: 2022/03/10 17:20:01 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# define MAX_NUMBER 2147483647
# define MIN_NUMBER -2147483648

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

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



#endif