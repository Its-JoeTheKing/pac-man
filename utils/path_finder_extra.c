/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:46:25 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/06 17:48:43 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	aff_map(char **map, t_point size)
{
	int	i_row;
	int	i_dice;

	i_row = -1;
	while (++i_row < size.y)
	{
		i_dice = -1;
		while (++i_dice < size.x)
			printf ("%c ", map[i_row][i_dice]);
		printf("\n");
	}
}
