/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:32:58 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/18 20:01:00 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_string_traitement(t_fd *file)
{
	size_t len;

	len = 0;
	file->idx = -1;
	while (++file->idx < file->ret/* && file->buff[file->idx] != '\n'*/)
	{
		if (file->buff[file->idx] == '\n')
		{
			if (!file->line)
				if (!(file->temp = ft_strsub(file->buff, 0, file->idx)))
					return (0);
		}
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_fd		file[FD_SIZE_MAX];

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	file[fd].read = 1;
	while (file[fd].read == 1)
	{
		ft_bzero(file[fd].buff, BUFF_SIZE + 1);
		if ((file[fd].ret = read(fd, file[fd].buff, BUFF_SIZE)) == -1)
			return (-1);
		if (!ft_string_traitement(&file[fd]))
			return (-1);;
	}
	return (file[fd].read);
}
