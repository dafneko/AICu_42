/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:34:50 by dkoca             #+#    #+#             */
/*   Updated: 2024/04/06 06:40:22 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

unsigned int parse_input(char *line)
{
	unsigned int num_input;

	num_input = 0;
	while (*line && *line != '\n')
	{
		if (ft_isdigit(*line))
			num_input = num_input * 10 + (*line - '0'); 
		else
			return ERROR;
		if (num_input > 1000 || num_input < 1)
			return ERROR;
		line++;
	}
	return(num_input);
}

int is_valid_input(int fd)
{
	char *line;
	int cur_input;
	
	//store the values somewhere (perhaps heaps)
	line = get_next_line(fd);
	while (line && line[0] != '\n')
	{
		cur_input = parse_input(line);
		free(line);
		if (cur_input == ERROR)
			return print_err(INPUT_ERROR), ERROR; 
		line = get_next_line(fd);		
	}
	// if (not EOF) clean still reachables 
	return (EXIT_SUCCESS);
	
}

int get_fd(int ac, char *argv[])
{
	int fd;

	if (ac > 2)
		return (ERROR);
	if (ac == 1)
		fd = STDOUT_FILENO;
	else
		fd = open(argv[1], O_RDONLY);
	return (fd);
}
