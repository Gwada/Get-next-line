/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 11:24:32 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/20 14:42:53 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int i = -1;
	char	*testline;
	while (++i < 50)
	{
		printf ("i = %d | fd = %d\n", i, ((i + 10 + i % 3) % 15));
		get_next_line(((i + 10 + i % 3) % 15) , &testline);
	}
	return (0);
}
