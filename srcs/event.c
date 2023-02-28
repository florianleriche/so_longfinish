/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:09:16 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/21 11:45:51 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_img(t_prog *prog, void *img)
{
	mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
		img, prog->x * 32, prog->y * 32);
}

void	lose(void)
{
	ft_printf("You LOSE\n");
	exit(1);
}

int	verif_end(t_prog *prog)
{
	if (prog->map[prog->y][prog->x] == 'O')
	{
		ft_printf("You WIN\n");
		exit(1);
	}
	return (0);
}
