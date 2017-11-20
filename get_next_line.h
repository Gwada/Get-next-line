/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:33:19 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/20 14:57:03 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
**	BIBLIOTHEQUE
*/

# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"
# include <stdio.h>

/*
**	MACCROS
*/

# define BUFF_SIZE 20

/*
**	STRUCTURES
*/

enum color
{
	BLACK,
	RED
};

typedef struct		s_fd
{
	int				fd;
	int				ret;
	int				rd;
	int				idx;
	char			b[BUFF_SIZE + 1];
	char			*t;
	char			*line;
	struct s_fd		*p;
	struct s_fd		*l;
	struct s_fd		*r;
	enum color		c;
}					t_fd;

/*
**	PROTOTYPES
*/

int	get_next_line(const int fd, char **line);

# endif
