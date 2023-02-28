/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:47:43 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/21 11:11:22 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map(char *map, t_data *dta, t_prog *prog)
{
	int		fd;
	char	*buffer;
	ssize_t	nread;

	nread = 1;
	buffer = malloc(sizeof(char) * 1024);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		exit(1);
	}
	nread = read(fd, buffer, 1024);
	if (nread < -1)
	{
		ft_printf("Error opening file\n");
		exit(1);
	}
	dta->map_str = buffer;
	dta->map_buf = ft_split(buffer, '\n');
	dta->map = ft_split(buffer, '\n');
	prog->map = ft_split(buffer, '\n');
	close(fd);
	free(buffer);
}
