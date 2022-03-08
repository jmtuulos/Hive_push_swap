/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:41:03 by jheiskan          #+#    #+#             */
/*   Updated: 2022/02/03 18:56:45 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp_lst;
	t_list	*mapped;
	t_list	*tmp;

	if (lst != NULL)
	{
		tmp_lst = lst;
		mapped = f(ft_lstnew(lst->content, lst->content_size));
		tmp_lst = tmp_lst->next;
		tmp = mapped;
		while (tmp_lst != NULL)
		{
			tmp->next = f(ft_lstnew(tmp_lst->content, tmp_lst->content_size));
			tmp = tmp->next;
			tmp_lst = tmp_lst->next;
		}
		return (mapped);
	}
	return (NULL);
}
