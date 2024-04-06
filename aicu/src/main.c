/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:26:46 by dkoca             #+#    #+#             */
/*   Updated: 2024/04/06 06:41:35 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int main (int ac, char *argv[])
{
	int fd;

	if ((fd = get_fd(ac, argv)) == ERROR)
	{
		print_err(ERROR);
		return (EXIT_FAILURE);
	}
	if (is_valid_input(fd))
		return (ERROR);
	//start the game
	return (EXIT_SUCCESS);	
}