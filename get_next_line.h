/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:33:19 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/18 20:00:57 by dlavaury         ###   ########.fr       */
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

/*
**	MACCROS
*/

# define BUFF_SIZE 20
# define FD_SIZE_MAX 1024

/*
**	STRUCTURES
*/

typedef struct	s_fd
{
	int		ret;
	int		read;
	int		idx;
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	char	*line;
}				t_fd

/*
**	PROTOTYPES
*/

int	get_next_line(const int fd, char **line);

# endif
