/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 11:24:32 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/28 13:45:59 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*testline;

	i = 0;
	(void)argc;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("false open\n");
		return (-1);
	}
	while (get_next_line(fd, &testline) > 0)
	{
		printf("%s\n", testline);
		free(testline);
		testline = NULL;
	}
	close(fd);
	return (0);
}
