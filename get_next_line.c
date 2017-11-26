/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:32:58 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/26 20:59:29 by dlavaury         ###   ########.fr       */
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
	new->line = NULL;
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

static	void	ft_make_line(t_fd *cur)
{
	if (cur->buffer[cur->i] == '\n' || cur->i < BUFF_SIZE - 1)
		cur->again = 0;
	if (cur->again)
	{
		if (!(line = (char*)malloc(sizeof())))
		
	}
	if (!(line = (char*)malloc(sizeof(char) * 
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*cur;
	int				i;

	if (fd < 0 || !line || BUFF_SIZE < 1 || !(cur = ft_find(cur, fd)))
		return (-1);
	cur->again = 1;
	i = 0;
	while (cur->again == 1)
	{
		if ((cur->ret = read(fd, cur->buffer, BUFF_SIZE) == -1))
			return (-1);
		while (cur->buffer[i] != '\n' && cur->buffer[i] && i < BUFF_SIZE)
			i++;
		cur->i = i;
		ft_make_line(cur);
	}
	//++cur->ret;
	if (cur->ret < 0)
		cur = ft_del_one(cur);
	puttree(cur);
	//line = &cur->line;
	return (0);
}
