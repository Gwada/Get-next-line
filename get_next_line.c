/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:32:58 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/20 20:21:30 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_fd	*ft_b(t_fd *cr, int fd, int opt)
{
	//printf ("in ft-first\n");
	if (opt == 1 && !cr)
	{
		//printf ("cur = NULL | opt = %d | fd = %d\n", opt, fd);
		if (!(cr = (t_fd*)malloc(sizeof(t_fd))))
			return (NULL);
		//printf("malloc ok\n");
		cr->fd = fd;
		cr->c = RED;
		/*(!root->prt) ? printf("root->prt NULL\n") : printf("NON NULL\n");*/cr->p = NULL;
		//(!cur->lft) ? printf("current noeud lft = NULL\n") : printf("current NON NULL\n");
		//(!cur->rgt) ? printf("current noeud rgt = NULL\n") : printf("current NON NULL\n");
		//(!cur->clr) ? printf("current noeud clr = NULL\n") : printf("current NON NULL\n");
	}
	if (opt == 2 && fd != cr->fd)
	{
		//printf ("cur->fd = %d opt = %d fd = %d\n", cr->fd, opt, fd);
		if (fd > cr->fd)
		{
			if (cr->r)
				cr->r->p = cr;
			return (cr->r ? ft_b(cr->r, fd, 2) : (cr->r = ft_b(cr->r, fd, 1)));
		}
		else
		{
			if (cr->l)
				cr->l->p = cr;
			return (cr->l ? ft_b(cr->l, fd, 2) : (cr->l = ft_b(cr->l, fd, 1)));
		}
	}
	/*if (opt == 3)
	{
		ft_b(cr) 
	}*/
	//if (opt == 2 && fd == cr->fd)
	//	printf ("fd == cur->fd\n");
	//printf ("root->fd = %d root->idx = %d\n", root->fd, root->idx);
	//printf("out ft_find\n");
	return (cr);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd		*rt;
	t_fd			*tmp;
	
	//printf("in get_next_line\n");
	//if (!rt)
		//printf ("!rt\n");
	if (fd < 0 || !line || BUFF_SIZE < 1 || (!rt && !(rt = ft_b(rt, fd, 1))))
		return (-1);
	//printf("re get_next_line\n");
	if (!(tmp = ft_b(rt, fd, 2)))
		return (-1);
	printf ("current fd = %d | fd = %d\nend gnl\n", tmp->fd, fd);
	printf ("rt->fd = %d | %d\n\n", rt->fd, tmp->c);
	tmp->idx++;
	line = &tmp->line;
	rt->c = BLACK;
	return (0);
}
