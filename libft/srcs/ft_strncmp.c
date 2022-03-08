/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:36:40 by jheiskan          #+#    #+#             */
/*   Updated: 2021/11/23 14:28:48 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	if (str1[i] == '\0')
		return (-str2[i]);
	if (str2[i] == '\0')
		return (str1[i]);
	while (str2[i] != '\0' && str1[i] != '\0' && str1[i] == str2[i])
	{
		if (i == n - 1)
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
