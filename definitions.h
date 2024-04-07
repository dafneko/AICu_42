/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:23:29 by dkoca             #+#    #+#             */
/*   Updated: 2024/04/07 06:18:07 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define  DEFINITIONS_H


/*errors*/
enum errors
{
    INPUT_ERROR,
    ENOMEM,
	INVALID_MOVE,
	INCORRECT_BOARD,
};

#define AI_WINS 0
#define PLAYER_WINS 1

#define ERROR -1


#endif