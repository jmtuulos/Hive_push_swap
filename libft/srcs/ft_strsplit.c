/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:24:28 by jheiskan          #+#    #+#             */
/*   Updated: 2021/12/01 21:48:14 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	array_clear(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (0);
}

static size_t	f_words(const char *s, char c, int *w_found)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
			{
				i++;
				*w_found = 1;
			}
			while (s[i] == c && s[i])
				i++;
			if (*w_found)
				words++;
		}
	}
	return (words);
}

static size_t	traverse_word(const char *s, size_t *i, char c)
{
	size_t	x;

	x = 0;
	while (s[*i] == c && s[*i])
		(*i)++;
	while (s[*i] != c && s[*i])
	{
		x++;
		(*i)++;
	}
	return (x);
}

static int	popul_chars(char **new, const char *s, char c, size_t words)
{
	size_t	i;
	size_t	w_index;
	size_t	x;

	i = 0;
	w_index = 0;
	while (words > w_index)
	{
		x = traverse_word(s, &i, c);
		if (x > 0)
		{
			new[w_index] = ft_strnew(x);
			if (!new[w_index])
				return (array_clear(new, w_index));
			ft_strncpy(new[w_index++], &s[i - x], x);
		}
	}
	new[words] = 0;
	return (1);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	**new;
	int		w_found;

	if (!s)
		return (NULL);
	w_found = 0;
	words = f_words(s, c, &w_found);
	new = (char **)malloc((words + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	if (popul_chars(new, s, c, words) == 0)
		return (NULL);
	return (new);
}
