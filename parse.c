/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:34:50 by dkoca             #+#    #+#             */
/*   Updated: 2024/04/07 12:28:10 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int parse_input(char *line)
{
	size_t num_input;

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

int is_valid_input(int fd, t_heaps *heap)
{
	char *line;
	int cur_input;
	size_t heap_count;
	
	heap_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			break;
		}
		cur_input = parse_input(line); //check if valid input
		free(line);
		if (cur_input == ERROR)
			return free(heap->heap), print_err(INPUT_ERROR), ERROR;
		heap->heap = ft_realloc(&heap->heap, heap_count + 1, 0);
		heap->heap[heap_count] = (size_t)cur_input; //fill array
		printf("sticks = %zu and heap = %zu\n", heap->heap[heap_count], heap_count);
		heap_count++;
		line = get_next_line(fd);		
	}
	if (line == NULL)
		return print_err(INPUT_ERROR), ERROR;
	close(fd);
	heap->heap_n = heap_count; 
	return (EXIT_SUCCESS);
	
}

int get_fd(int ac, char *argv[])
{
	int fd;

	if (ac > 2)
		return (ERROR);
	if (ac == 1)
		fd = STDIN_FILENO;
	else
		fd = open(argv[1], O_RDONLY);
	return (fd);
}


int parse_and_fill(int ac, char **argv, t_heaps *heap)
{
	int fd;
	
	if ((fd = get_fd(ac, argv)) == ERROR)
	{
		print_err(ERROR);
		return (EXIT_FAILURE);
	}
	if (is_valid_input(fd, heap))
		return (ERROR);
	return (EXIT_SUCCESS);
}