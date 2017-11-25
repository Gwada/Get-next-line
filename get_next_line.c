/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:32:58 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/24 10:41:16 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	puttree(t_fd *cur)
{
	printf ("in puttree\n");
	if (!cur)
	{
		printf ("!cur\n");
		return ;
	}
	while (cur->previous)
		cur = cur->previous;
	while (cur)
	{
		printf ("%d\n", cur->fd);
		cur = cur->next;
	}
	printf ("end puttree\n ");
}

static t_fd		*ft_create_one(t_fd *current, int fd)
{
	t_fd	*new;

	printf ("in create\n");
	if (!(new = (t_fd*)malloc(sizeof(t_fd))))
		return (NULL);
	new->fd = fd;
	new->ret = 0;
	ft_bzero(new->buffer, BUFF_SIZE + 1);
	new->line = NULL;
	/*if (!current)
	{
		new->previous = NULL;
		new->next = NULL;
	}*/
	else if (fd < current->fd)
	{
		new->previous = current->previous;
		if (current->previous)
			current->previous->next = new;
		new->next = current;
	}
	else if (fd > current->fd)
	{
		new->next = current->next;
		if (current->next)
			curent->next->previous = new;
		new->previous = current;
	}
	printf ("malloc ok out create\n");
	return (new);
}

static	t_fd	*ft_del_one(t_fd *current)
{
	if (current && !current->previous && !current->next)
		free(current);
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
		current = current->previous;
		current->next->next->previous = current;
		current = current->next->next;
		free(current->previous);
		current->previous->next = current;
	}
	return (current ? current : NULL);
}

static	t_fd	*ft_find(t_fd *current, int fd)
{
	printf ("in ft-first\n");
	if (!current)
	{
		printf ("current NULL -> go malloc\n");
		return (ft_create_one(current, fd));
		printf("malloc ok si visible problem\n");
	}
	if (fd > current->fd)
	{
		printf("fd > current->fd\n");
		if (current->next && fd >= current->next-fd)
		{
			printf("go current->next\n");
			return (ft_find(current->next, fd));
		}
		//printf("!current->next\n");
		return ((current = ft_create_one(current, fd)) ? current : NULL);
		printf ("malloc current->next ok\n");
		/*current->next->previous = current;
		current = current->next;*/
	}
	if (fd < current->fd)
	{
		printf ("fd < current->fd\n");
		if (current->previous && fd <= current->previous->fd)
		{
			printf ("current->fd\n");
			return (ft_find(current->previous, fd));
		}
		printf ("curren->previous = NULL\n");
		return ((current = ft_create_one(current, fd))? current : NULL);
		/*if (current->previous)
		if (current->previous)	printf ("malloc current->previous ok\n");
		current->previous->previous	?	printf ("current->previous->previous\n")	:	printf("current->previous->previous = NULL\n");
		(current->previous->next) ? printf ("current->previous->next\n")	:	printf("current->previous->next = NULL\n");
		current->previous->next = current;
		current->previous->next ? printf("%d %d\n", current->previous->fd, current->previous->next->fd)	:	printf("NULL\n");
		current = current->previous;*/
	}
	return (current);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*cur;
	printf ("fd = %d\n", fd);
	if (!cur)
		printf ("!rt\n");
	//printf(" fd = %d\n", fd);
	if (fd < 0 || !line || BUFF_SIZE < 1 || !(cur = ft_find(cur, fd)))
		return (-1);
	printf ("out ft_find main\n");
	//printf ("current fd = %d | fd = %d\nend gnl\n", tmp->fd, fd);
	//printf ("rt->fd = %d\n\n", rt->fd);
	//printf ("(ret = %d) \n", cur->ret);
	if (cur->ret == 2)
		cur = ft_del_one(cur);
	puttree(cur);
	printf ("\n");
	line = &cur->line;
	return (0);
}
