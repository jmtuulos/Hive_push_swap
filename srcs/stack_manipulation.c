/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:21:48 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/13 20:45:34 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	del_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack != NULL)
	{
		next = stack->next;
		stack->value = 0;
		free(stack);
		stack = next;
	}
}

t_stack	*new_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	return (new);
}

void	add_to_start(t_stack **a, int value)
{
	t_stack	*tmp;

	if (!a || !*a)
		(*a) = new_node(value);
	else
	{
		tmp = new_node(value);
		tmp->next = *a;
		*a = tmp;
	}
}

void	add_to_end(t_stack **a, int value)
{
	t_stack	*tmp;

	if (!a || !*a)
		(*a) = new_node(value);
	else
	{
		tmp = *a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node(value);
	}
}

char	*free_choices(char **choices, int best_index)
{
	char	*ret;
	char	**tmp1;
	char	*tmp;

	tmp1 = choices;
	ret = ft_strdup(choices[best_index]);
	if (!ret)
		exit(-1);
	while (*choices)
	{
		tmp = *choices++;
		free(tmp);
	}
	free(tmp1);
	return (ret);
}
