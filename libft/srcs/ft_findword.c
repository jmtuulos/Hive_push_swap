/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:54:43 by jheiskan          #+#    #+#             */
/*   Updated: 2021/12/01 20:26:50 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_findword(const char *src, const char *word)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	j = 0;
	if (!word && src)
		return (0);
	while (src[i])
	{
		k = 0;
		if (src[i] == word[k])
		{
			j = i;
			while (src[j++] == word[k])
			{
				if (word[++k] == '\0')
					return (1);
			}
		}
		i++;
	}
	return (0);
}
