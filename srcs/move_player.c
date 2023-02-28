/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:53:14 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/21 11:05:26 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_right(t_prog *prog)
{
	if (prog->map[prog->y][prog->x + 1] != '1')
	{
		if (prog->map[prog->y][prog->x + 1] == 'E')
			return (0);
		if (prog->map[prog->y][prog->x] == 'F')
			put_img(prog, prog->img_floor2);
		else
			put_img(prog, prog->img_floor);
		prog->x += 1;
		prog->nb_mouv += 1;
		ft_printf("Number of mouvements -> %d\n", prog->nb_mouv);
		if (prog->map[prog->y][prog->x] == 'C')
		{
			put_img(prog, prog->img_floor);
			prog->map[prog->y][prog->x] = '0';
			prog->nb_collectible -= 1;
		}
		put_img(prog, prog->img_player_right);
	}
	return (0);
}

int	move_left(t_prog *prog)
{
	if (prog->map[prog->y][prog->x - 1] != '1')
	{
		if (prog->map[prog->y][prog->x - 1] == 'E')
			return (0);
		if (prog->map[prog->y][prog->x] == 'F')
			put_img(prog, prog->img_floor2);
		else
			put_img(prog, prog->img_floor);
		prog->x -= 1;
		prog->nb_mouv += 1;
		ft_printf("Number of mouvements -> %d\n", prog->nb_mouv);
		if (prog->map[prog->y][prog->x] == 'C')
		{
			put_img(prog, prog->img_floor);
			prog->map[prog->y][prog->x] = '0';
			prog->nb_collectible -= 1;
		}
		put_img(prog, prog->img_player_left);
	}
	return (0);
}

int	move_up(t_prog *prog)
{
	if (prog->map[prog->y - 1][prog->x] != '1')
	{
		if (prog->map[prog->y - 1][prog->x] == 'E')
			return (0);
		if (prog->map[prog->y][prog->x] == 'F')
			put_img(prog, prog->img_floor2);
		else
			put_img(prog, prog->img_floor);
		prog->y -= 1;
		prog->nb_mouv += 1;
		ft_printf("Number of mouvements -> %d\n", prog->nb_mouv);
		if (prog->map[prog->y][prog->x] == 'C')
		{
			put_img(prog, prog->img_floor);
			prog->map[prog->y][prog->x] = '0';
			prog->nb_collectible -= 1;
		}
		put_img(prog, prog->img_player_up);
	}
	return (0);
}

int	move_down(t_prog *prog)
{
	if (prog->map[prog->y + 1][prog->x] != '1')
	{
		if (prog->map[prog->y + 1][prog->x] == 'E')
			return (0);
		if (prog->map[prog->y][prog->x] == 'F')
			put_img(prog, prog->img_floor2);
		else
			put_img(prog, prog->img_floor);
		prog->y += 1;
		prog->nb_mouv += 1;
		ft_printf("Number of mouvements -> %d\n", prog->nb_mouv);
		if (prog->map[prog->y][prog->x] == 'C')
		{
			put_img(prog, prog->img_floor);
			prog->map[prog->y][prog->x] = '0';
			prog->nb_collectible -= 1;
		}
		put_img(prog, prog->img_player);
	}
	return (0);
}

int	verif_exit(t_prog *prog)
{
	(void)prog;
	if (prog->nb_collectible == 0)
	{
		mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
			prog->img_exit_open, prog->exit_position_x * 32,
			prog->exit_position_y * 32);
		prog->map[prog->exit_position_y][prog->exit_position_x] = 'O';
		return (0);
	}
	return (0);
}
