/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:50:35 by dkoca             #+#    #+#             */
/*   Updated: 2024/04/06 06:38:42 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

void print_err(int err)
{
	if (err == ERROR)
		ft_putendl_fd("ERROR.", STDERR_FILENO);
	else if (err == INPUT_ERROR)
		ft_putendl_fd("WRONG INPUT.", STDERR_FILENO);
	else if (err == ENOMEM)
		ft_putendl_fd("NO MEMORY LEFT.", STDERR_FILENO);
	else if (err == INVALID_MOVE)
		ft_putendl_fd("INVALID MOVE. TRY AGAIN.", STDERR_FILENO);
	else if (err == INCORRECT_BOARD)
		ft_putendl_fd("BOARD COULD NOT BE CREATED.", STDERR_FILENO);
}