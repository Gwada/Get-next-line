/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 11:24:32 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/29 04:34:02 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
//	int		j;
	int k;
	int	fd;
//	int		fd[3];
	char	*testline;

	i = -1;
	(void)argc;
	/*while (++i < 3)
	{
		if ((fd[i] = open(argv[i + 1], O_RDONLY)) == -1)
		{
			printf("false open\n");
			return (-1);
		}
		printf ("open %d RAS\n", i + 1);
	}
	i = -1;
	k = 0;
	while (++i < 15)
	{
		printf ("\n");
		j = -1;
		while (++j < 3)
		{
			printf ("j = %d	GNL = %d	", j, (k = get_next_line(fd[j]), &testline[j]));
			printf("	%d	%s\n",k, testline[j]);
			free(testline[j]);
			testline[j] = NULL;
//		}
	}
	//i = 0;
	//while (i < 3)
	//{
		//close(fd[i]);
		//close(fd);
	//	i++;
	//}*/
	fd = open(argv[1], O_RDONLY);
	k = 0;
	int l = 0;
	while ((l = get_next_line(fd, &testline)) > 0)
	{
		//printf ("_______________________________________________________________________\n");
		printf ("%s\n", testline);
		//printf ("_______________________________________________________________________\n\n\n");
		//printf("\nverif main:	appel n: %d		retour gnl = %d		testline = %s\n\n\n", ++k, l,testline);//
		free (testline);
	}
	//printf("%d	end\n",k);//
	close (fd);
	return (0);
}
