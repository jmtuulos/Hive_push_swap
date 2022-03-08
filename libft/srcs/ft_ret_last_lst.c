/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret_last_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:44:26 by jheiskan          #+#    #+#             */
/*   Updated: 2021/12/01 19:50:23 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_ret_last_lst(t_list **list)
{
	t_list	*l_tmp;

	if (!(*list))
		return (NULL);
	l_tmp = *list;
	while (l_tmp->next != NULL)
		l_tmp = l_tmp->next;
	return (l_tmp);
}
