/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:33:19 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/28 13:35:07 by dlavaury         ###   ########.fr       */
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
# include <fcntl.h>

/*
**	MACCROS
*/

# define BUFF_SIZE 1

/*
**	STRUCTURES
*/

typedef struct		s_fd
{
	int				i;
	int				fd;
	int				nl;
	int				ret;
	char			buffer[BUFF_SIZE + 1];
	struct s_fd		*previous;
	struct s_fd		*next;
}					t_fd;

/*
**	PROTOTYPES
*/

int					get_next_line(const int fd, char **line);

#endif
