/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joindel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:40:29 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/08 10:56:45 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joindel(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (!new)
		exit(-1);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (new);
}
