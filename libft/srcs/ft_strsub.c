/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:14:21 by jheiskan          #+#    #+#             */
/*   Updated: 2021/11/16 20:14:46 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;

	i = 0;
	if (s == NULL)
		return (NULL);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	return (new);
}
