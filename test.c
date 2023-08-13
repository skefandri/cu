/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabr <ysabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:25:33 by ysabr             #+#    #+#             */
/*   Updated: 2023/08/11 15:05:20 by ysabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int main(int argc, char **argv) {
//     if (argc != 2 || !check_name_map(argv[1]))
//     {
//         errmsg("Usage: ./program mapfile.cub\n");
//         return (EXIT_FAILURE);
//     }

//     char *str = ft_read_map(argv[1]);
//     if (!str) {
//         errmsg("empty map\n");
//         return (EXIT_FAILURE);
//     }

//     t_Map map;
//     char **lines = ft_split(str, '\n');
//     int i = 0;
//     while(lines[i])
//     {
//         handle_line(lines[i], &map);
//         i++;
//     }
//     // Print some values to verify
//     printf("Resolution: %d %d\n", map.resolution[0], map.resolution[1]);
//     printf("North Texture: %s\n", map.northTexture);
//     printf("Floor Color: %d,%d,%d\n", map.floorColor[0], map.floorColor[1], map.floorColor[2]);

//     // Free lines, str, and other dynamically allocated memory

//     return (EXIT_SUCCESS);
// }

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	char	*str;

// 	str = ft_read_map(av[1]);
// 	if (!str)
// 	errmsg("empty map\n");

	
// }