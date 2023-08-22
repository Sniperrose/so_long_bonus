/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:13:25 by galtange          #+#    #+#             */
/*   Updated: 2023/03/28 01:13:27 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	change_trap(char **map, char t)
{
	t_vector	pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x] != '\0')
		{
			if (map[pos.y][pos.x] == 'T' || map[pos.y][pos.x] == 'S')
				map[pos.y][pos.x] = t;
			pos.x++;
		}
		pos.y++;
	}
}

static void	enemy_animation(t_game *game)
{
	static int	basic_count;

	if (basic_count == game->spr)
		change_trap(game->map, 'T');
	else if (basic_count > game->spr * 2)
	{
		change_trap(game->map, 'S');
		basic_count = 0;
	}
	basic_count++;
}

void	render(t_game game)
{
	display_game(&game, game.type);
	display_moves(&game, game.moves);
}

int	update(t_game *game)
{
	enemy_animation(game);
	render(*game);
	return (1);
}
