/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:23:37 by jheiskan          #+#    #+#             */
/*   Updated: 2022/03/08 14:59:52 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi_long(const char *str)
{
	int					i;
	int					sign;
	long long int		res;

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
		if (res > 922337203685477580ll / 10 && sign == 1)
			return (-1);
		if (res > 922337203685477580ll / 10 && sign == -1)
			return (0);
		res = res * 10 + str[i++] - '0';
	}
	return (res * sign);
}
