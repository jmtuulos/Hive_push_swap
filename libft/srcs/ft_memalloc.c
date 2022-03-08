/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:23:52 by jheiskan          #+#    #+#             */
/*   Updated: 2021/11/16 18:23:56 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*n_mem;

	n_mem = (void *)malloc(size);
	if (!n_mem)
		return (NULL);
	ft_bzero(n_mem, size);
	return (n_mem);
}
