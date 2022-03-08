/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:23:37 by jheiskan          #+#    #+#             */
/*   Updated: 2022/03/08 14:48:50 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
	str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] <= '9' && str[i] >= '0')
		res = str[i++] - '0';
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (res > 9223372036854775807ull / 10 && sign == 1)
			return (-1);
		if (res > 9223372036854775807ull / 10 && sign == -1)
			return (0);
		res = res * 10 + str[i++] - '0';
	}
	return ((int)res * sign);
}
