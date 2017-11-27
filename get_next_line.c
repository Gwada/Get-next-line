/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:32:58 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/27 19:46:46 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	puttree(t_fd *cur)
{
	if (!cur)
	{
		printf("!cur\n");//
		return ;
	}
	printf("NULL -> ");//
	while (cur->previous)
		cur = cur->previous;
	while (cur)
	{
		printf("%d -> ", cur->fd);//
		cur = cur->next;
	}
	printf("NULL\n");//
}

static t_fd		*ft_create_one(t_fd *current, int fd)
{
	t_fd	*new;

	if (!(new = (t_fd*)malloc(sizeof(t_fd))))
		return (NULL);
	new->fd = fd;
	new->ret = 0;
	ft_bzero(new->buffer, BUFF_SIZE + 1);
	new->tmp = NULL;
	if (current && fd < current->fd)
	{
		new->previous = current->previous ? current->previous : NULL;
		if (current->previous)
			current->previous->next = new;
		new->next = current;
		current->previous = new;
	}
	else if (current && fd > current->fd)
	{
		new->next = current->next ? current->next : NULL;
		if (current->next)
			current->next->previous = new;
		new->previous = current;
		current->next = new;
	}
	return (new);
}

static	t_fd	*ft_del_one(t_fd *current)
{
	if (current && !current->previous && !current->next)
	{
		free(current);
		current = NULL;
	}
	else if (current && !current->previous && current->next)
	{
		current = current->next;
		free(current->previous);
		current->previous = NULL;
	}
	else if (current && current->previous && !current->next)
	{
		current = current->previous;
		free(current->next);
		current->next = NULL;
	}
	else if (current && current->previous && current->next)
	{
		current->next->previous = current->previous;
		current = current->next;
		free(current->previous->next);
		current->previous->next = current;
	}
	return (current);
}

static	t_fd	*ft_find(t_fd *current, int fd)
{
	if (!current)
	{
		if (!(current = ft_create_one(current, fd)))
			return (NULL);
		current->previous = NULL;
		current->next = NULL;
		return (current);
	}
	if (fd > current->fd)
	{
		if (current->next && fd >= current->next->fd)
			return (ft_find(current->next, fd));
		return (ft_create_one(current, fd));
	}
	if (fd < current->fd)
	{
		if (current->previous && fd <= current->previous->fd)
			return (ft_find(current->previous, fd));
		return (ft_create_one(current, fd));
	}
	return (current);
}

static	char	*ft_make_line(t_fd *cur, char **line, int i)
{
	char		*new;

	new = NULL;
	printf ("in make\n");//
	if (cur->buffer[i] == '\n')
	{
		cur->nl = 1;
		printf("buffer[i] == '\\n'\n");//
	}
	if (!*line)
		if (!(new = ft_strsub(cur->buffer, 0, i)))
			return (NULL);
//		printf ("new = %s\n", new);//
//		ft_bzero(cur->buffer, BUFF_SIZE + 1);
//	}
	if (*line)
	{
//		printf ("test\n");
		if (!(new = ft_strnew(ft_strlen(*line) + i)))
			return (NULL);
		printf ("test\n");

		ft_strcpy(new, *line);
		ft_strcat(new, cur->buffer);
	}
//	printf ("end make\n");//
//	if (!cur->nl)
//		ft_bzero(cur->buffer, i + 1);
//	else
//	{
		ft_strncpy(cur->buffer, &cur->buffer[i + 1], BUFF_SIZE);
//	}
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*cur;
	int				i;

	if (fd < 0 || !line || BUFF_SIZE < 1 || !(cur = ft_find(cur, fd)))
		return (-1);
	line = NULL;
	cur->nl = 0;
	printf ("gnl\n");//
	while (!cur->nl)
	{
		i = 0;
		if ((cur->ret = read(fd, cur->buffer, BUFF_SIZE)) == -1)
			return (-1);
		while (cur->buffer[i] && cur->buffer[i] != '\n')
			i++;
		printf ("i = %d buffer = %s cur->ret = %d\n", i, cur->buffer, cur->ret);//
		*line = ft_make_line(cur, line, i);
		printf ("line = %s\nafter make line\ncur->ret = %d\n", *line, cur->ret);//
		if (!cur->ret || cur->ret < BUFF_SIZE)
		{
			ft_del_one(cur);
			return (0);
		}
		printf ("test\n");//
	}
	puttree(cur);
	printf ("end gnl\n");//
	return (1);
}
