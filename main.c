/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 11:24:32 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/19 19:46:15 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int i = -1;
	char	*testline;
	while (++i < 10)
		get_next_line(5 , &testline);
	return (0);
}
