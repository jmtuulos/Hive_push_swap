/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:36:46 by jheiskan          #+#    #+#             */
/*   Updated: 2021/11/15 22:50:35 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	x;

	x = 0;
	while (dest[x])
		x++;
	i = 0;
	while (src[i])
	{
		dest[x + i] = src[i];
		i++;
	}
	dest[i + x] = '\0';
	return (dest);
}
