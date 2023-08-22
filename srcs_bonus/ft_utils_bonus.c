/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:01:53 by galtange          #+#    #+#             */
/*   Updated: 2022/10/31 18:01:55 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_image	ft_new_sprite(void *ptr, char *path)
{
	t_image	img;

	img.pointer = mlx_xpm_file_to_image(ptr, path, &img.size.x, &img.size.y);
	return (img);
}

int	ft_check_nbrpaths(int i)
{
	int	fd[10];

	fd[0] = open("img_bonus/n0.xpm", O_RDONLY);
	fd[1] = open("img_bonus/n1.xpm", O_RDONLY);
	fd[2] = open("img_bonus/n2.xpm", O_RDONLY);
	fd[3] = open("img_bonus/n3.xpm", O_RDONLY);
	fd[4] = open("img_bonus/n4.xpm", O_RDONLY);
	fd[5] = open("img_bonus/n5.xpm", O_RDONLY);
	fd[6] = open("img_bonus/n6.xpm", O_RDONLY);
	fd[7] = open("img_bonus/n7.xpm", O_RDONLY);
	fd[8] = open("img_bonus/n8.xpm", O_RDONLY);
	fd[9] = open("img_bonus/n9.xpm", O_RDONLY);
	while (++i < 10)
	{	
		close (fd[i]);
		if (fd[i] < 0)
			return (ft_error("Please check the image paths!\n"));
	}
	return (1);
}

int	ft_check_imgpaths(int i)
{
	int	fd[16];

	fd[0] = open("imgs/E.xpm", O_RDONLY);
	fd[1] = open("imgs/0.xpm", O_RDONLY);
	fd[2] = open("imgs/1.xpm", O_RDONLY);
	fd[3] = open("imgs/10.xpm", O_RDONLY);
	fd[4] = open("imgs/11.xpm", O_RDONLY);
	fd[5] = open("imgs/20.xpm", O_RDONLY);
	fd[6] = open("imgs/21.xpm", O_RDONLY);
	fd[7] = open("imgs/30.xpm", O_RDONLY);
	fd[8] = open("imgs/31.xpm", O_RDONLY);
	fd[9] = open("imgs/40.xpm", O_RDONLY);
	fd[10] = open("imgs/41.xpm", O_RDONLY);
	fd[11] = open("imgs/C.xpm", O_RDONLY);
	fd[12] = open("img_bonus/T.xpm", O_RDONLY);
	fd[13] = open("img_bonus/DIED.xpm", O_RDONLY);
	fd[14] = open("imgs/won.xpm", O_RDONLY);
	fd[15] = open("img_bonus/T1.xpm", O_RDONLY);
	while (++i < 16)
	{	
		close (fd[i]);
		if (fd[i] < 0)
			return (ft_error("Please check the image paths!\n"));
	}
	return (ft_check_nbrpaths(-1));
}

int	ft_extmap(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = (int) ft_strlen(str) - 4;
	if (ft_strncmp(&str[i], ".ber", 4) != 0)
		return (0);
	return (1);
}
