/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aicu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:35:03 by dkoca             #+#    #+#             */
/*   Updated: 2024/04/06 06:35:30 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include "../libft/libft.h"
#include <fcntl.h>


/*main.c*/
int main (int ac, char *argv[]);

/*parse.c*/
int get_fd(int ac, char *argv[]);
int is_valid_input(int fd);
unsigned int parse_input(char *line);

/*errors.c*/
void print_err(int err);

#endif