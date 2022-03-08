/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:37:14 by jheiskan          #+#    #+#             */
/*   Updated: 2021/11/19 13:42:46 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;
	size_t	j;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		x = 0;
		j = i;
		while (needle[x] != '\0' && needle[x] == haystack[i] && i < len)
		{
			x++;
			if (needle[x] == '\0')
				return ((char *)&haystack[(i + 1) - x]);
			i++;
		}
		i = j + 1;
	}
	return (0);
}
