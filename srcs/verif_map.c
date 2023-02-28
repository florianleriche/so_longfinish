/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:09:38 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/28 11:35:05 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_alert(char *alert)
{
	ft_printf("Error\n");
	ft_printf("%s\n", alert);
	exit(1);
}

int	len_map_x(t_data *dta, char **map, int x)
{
	int	i;

	i = 0;
	if (x == len_map_y(dta, map) - 1)
	{
		while (map[x][i] == '1')
			i++;
		return (i);
	}
	while (map[x][i] != '\0')
		i++;
	if (x == 0)
		dta->map_x = i;
	return (i);
}

int	len_map_y(t_data *dta, char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	dta->map_y = i;
	return (i);
}

int	nb_char_in_map(char *map_str, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == c)
			result++;
		i++;
	}
	return (result);
}

void	verif_map(t_data *dta)
{
	dta->nb_exit = 0;
	dta->nb_collectible = 0;
	len_map_x(dta, dta->map, 0);
	len_map_y(dta, dta->map);
	verif_char(dta);
	map_shape(dta);
	map_p(dta, dta->map_buf);
}
