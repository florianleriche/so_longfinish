/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:41:21 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/21 11:41:41 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_zero_to_p(int i, int i2, char **map)
{
	if (map[i][i2 - 1] == '0')
		map[i][i2 - 1] = 'P';
	if (map[i][i2 + 1] == '0')
		map[i][i2 + 1] = 'P';
	if (map[i - 1][i2] == '0')
		map[i - 1][i2] = 'P';
	if (map[i + 1][i2] == '0')
		map[i + 1][i2] = 'P';
}

void	map_c_to_p(t_data *dta, int i, int i2, char **map)
{
	if (map[i][i2 - 1] == 'C')
	{
		map[i][i2 - 1] = 'P';
		dta->nb_collectible++;
	}
	if (map[i][i2 + 1] == 'C')
	{
		map[i][i2 + 1] = 'P';
		dta->nb_collectible++;
	}
	if (map[i - 1][i2] == 'C')
	{
		map[i - 1][i2] = 'P';
		dta->nb_collectible++;
	}
	if (map[i + 1][i2] == 'C')
	{
		map[i + 1][i2] = 'P';
		dta->nb_collectible++;
	}
}

void	map_e_to_p(t_data *dta, int i, int i2, char **map)
{
	if (map[i][i2 - 1] == 'E')
	{
		map[i][i2 - 1] = 'P';
		dta->nb_exit++;
	}
	if (map[i][i2 + 1] == 'E')
	{
		map[i][i2 + 1] = 'P';
		dta->nb_exit++;
	}
	if (map[i - 1][i2] == 'E')
	{
		map[i - 1][i2] = 'P';
		dta->nb_exit++;
	}
	if (map[i + 1][i2] == 'E')
	{
		map[i + 1][i2] = 'P';
		dta->nb_exit++;
	}
}
