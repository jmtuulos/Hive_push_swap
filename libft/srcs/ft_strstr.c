/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:37:33 by jheiskan          #+#    #+#             */
/*   Updated: 2021/11/16 20:14:16 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	if (*needle == 0)
		return (haystack);
	while (haystack[i] != '\0')
	{
		x = 0;
		if (needle[x] == haystack[i])
		{
			y = i;
			while (needle[x] != '\0' && needle[x] == haystack[y])
			{
				x++;
				if (needle[x] == '\0')
					return (&haystack[(y + 1) - x]);
				y++;
			}
		}
		i++;
	}
	return (0);
}
