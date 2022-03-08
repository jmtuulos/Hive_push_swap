/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:14:50 by jheiskan          #+#    #+#             */
/*   Updated: 2021/11/16 20:16:01 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	i;
	char	*new;

	i = 0;
	start = 0;
	if (s == NULL)
		return (NULL);
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (s[start] == '\0')
	{
		new = ft_strnew(0);
		if (!new)
			return (NULL);
		return (new);
	}
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	new = ft_strnew((i + 1) - start);
	if (!new)
		return (NULL);
	ft_strncpy(new, &s[start], ((i + 1) - start));
	return (new);
}
