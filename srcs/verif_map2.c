/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:35:33 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/21 12:13:14 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	p_extend(t_data *dta, int i, int i2, char **map)
{
	map_zero_to_p(i, i2, map);
	map_c_to_p(dta, i, i2, map);
	map_e_to_p(dta, i, i2, map);
}

char	**map_p(t_data *dta, char **map)
{
	int	i;
	int	i2;
	int	i3;

	i3 = -1;
	while (++i3 != dta->map_y * dta->map_x)
	{
		i = -1;
		while (++i != dta->map_y)
		{
			i2 = -1;
			while (++i2 != dta->map_x)
			{
				if (map[i][i2] == 'P')
					p_extend(dta, i, i2, map);
			}
		}
	}
	if (dta->nb_exit != 1)
		error_alert("Error on Exit");
	if (dta->nb_collectible != nb_char_in_map(dta->map_str, 'C'))
		error_alert("Error on Collectible");
	return (map);
}

void	verif_char2(t_data *dta, char **map)
{
	int	i;
	int	i2;
	int	i3;

	i3 = -1;
	while (++i3 != dta->map_y * dta->map_x)
	{
		i = -1;
		while (++i != dta->map_y)
		{
			i2 = -1;
			while (++i2 != dta->map_x)
			{
				if (map[i][i2] != '0' && map[i][i2] != '1'
					&& map[i][i2] != 'E' && map[i][i2] != 'C'
					&& map[i][i2] != 'P' && map[i][i2] != '\n')
					error_alert("Error on char Map");
			}
		}
	}
}

void	verif_char(t_data *dta)
{
	verif_char2(dta, dta->map);
	if (nb_char_in_map(dta->map_str, 'C') < 1
		|| nb_char_in_map(dta->map_str, 'E') != 1
		|| nb_char_in_map(dta->map_str, 'P') != 1)
		error_alert("Error on char Map");
}

void	map_shape(t_data *dta)
{
	int	i;

	i = 0;
	if (dta->map_y < 3)
		error_alert("Error size Map");
	while (i != dta->map_y)
	{
		if (len_map_x(dta, dta->map, i) != dta->map_x)
			error_alert("Error shape Map");
		i++;
	}
	i = 0;
	while (i != dta->map_x)
	{
		if (dta->map[0][i] != '1' || dta->map[dta->map_y - 1][i] != '1')
			error_alert("Error on walls");
		i++;
	}
	i = 0;
	while (i != dta->map_y)
	{
		if (dta->map[i][0] != '1' || dta->map[i][dta->map_x - 1] != '1')
			error_alert("Error on walls");
		i++;
	}
}
