/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:32:58 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/19 19:46:20 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_fd	*ft_first(t_fd *root, int fd)
{
	//printf ("in ft-first\n");
	if (!root)
	{
		//printf("ptr NULL\n");
		if (!(root = (t_fd*)malloc(sizeof(t_fd))))
			return (NULL);
		//printf("malloc ok\n");
		root->fd = fd;
		root->ret = 1;
		root->rd = 0;
		root->idx = 0;
		ft_bzero(root->buf, BUFF_SIZE + 1);
		root->tmp = NULL;
		root->line = NULL;
		root->prt = NULL;
		root->lft = NULL;
		root->rgt = NULL;
	}
	//printf ("root->fd = %d root->idx = %d\n", root->fd, root->idx);
	//printf("out ft_first\n");
	return (root);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd		*root;
	
	//printf("in get_next_line\n");
	(void)line;
	if (fd < 0 || !(root = ft_first(root, fd)) || !line || BUFF_SIZE < 0)
		return (-1);
	//printf("re get_next_line\n");
	printf ("fd = %d root->idx = %d\nend gnl\n", root->fd,root->idx);
	printf ("%d\n", root->clr);
	root->idx++;
	return (0);
}
