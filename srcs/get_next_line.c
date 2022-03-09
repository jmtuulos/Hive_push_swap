/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:36:26 by jheiskan          #+#    #+#             */
/*   Updated: 2021/12/13 16:08:39 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*put_line(char **str)
{
	size_t	i;
	char	*tmp;
	char	*lc_ptr;

	i = 0;
	tmp = *str;
	lc_ptr = ft_strchr(tmp, '\n');
	if (lc_ptr)
		*lc_ptr = '\0';
	return (ft_strdup(tmp));
}

static int	save_str(char **fd_str, char **line, ssize_t b_read)
{
	char	*tmp;

	*line = put_line(fd_str);
	if (!*line)
		return (-1);
	if (b_read == 0 && **fd_str)
	{
		ft_memdel((void **)fd_str);
		return (1);
	}
	tmp = *fd_str;
	*fd_str = ft_strdup(ft_strchr(*fd_str, '\0') + 1);
	if (!*fd_str)
		return (-1);
	ft_memdel((void **)&tmp);
	return (1);
}

static int	calc_return(char **fd_str, ssize_t b_read, char **line)
{
	if (b_read < 0)
	{
		ft_strdel(fd_str);
		return (-1);
	}
	if (b_read == 0 && (fd_str[b_read] == NULL || *fd_str[b_read] == '\0'))
	{
		ft_strdel(fd_str);
		return (0);
	}
	return (save_str(fd_str, line, b_read));
}

int	get_next_line(const int fd, char **line)
{
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	static char		*fd_arr[MAX_FD];
	ssize_t			b_read;

	if (fd < 0 || !line || fd >= MAX_FD)
		return (-1);
	b_read = 1;
	ft_bzero(buf, BUFF_SIZE);
	while (b_read > 0 && (!fd_arr[fd] || !ft_strchr(fd_arr[fd], '\n')))
	{
		b_read = read(fd, buf, BUFF_SIZE);
		buf[b_read] = '\0';
		if (!fd_arr[fd] && b_read > -1)
			fd_arr[fd] = ft_strdup(buf);
		else if (b_read >= 0)
		{
			tmp = fd_arr[fd];
			fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
			ft_memdel((void **)&tmp);
		}
		if (!fd_arr[fd])
			return (-1);
	}
	return (calc_return(&fd_arr[fd], b_read, line));
}
