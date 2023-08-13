/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabr <ysabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:10:16 by ysabr             #+#    #+#             */
/*   Updated: 2023/08/11 14:14:36 by ysabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void parse_resolution(char *line, t_Map *map)
// {
//     char **tokens = ft_split(line, ' ');
//     for(int i = 0; tokens[i] ; i++)
//         printf("%s\n", tokens[i]);
//     if (tokens && tokens[1] && tokens[2])
//     {
//         map->resolution[0] = ft_atoi(tokens[1]);
//         map->resolution[1] = ft_atoi(tokens[2]);
//     }
// }

// char	*ft_strtrim(char *s)
// {
// 	size_t	start;
// 	size_t	end;
// 	char	*trim;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	start = 0;
// 	while (s[start] && (s[start] == ' ' || s[start] == '\t' || s[start] == '\n'))
// 		start++;
// 	end = ft_strlen(s) - 1;
// 	while (end > start && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
// 		end--;
// 	trim = (char *)malloc(end - start + 2);
// 	if (!trim)
// 		return (NULL);
// 	i = 0;
// 	while (start <= end)
// 		trim[i++] = s[start++];
// 	trim[i] = '\0';
// 	return (trim);
// }


// void parse_texture(char *line, t_Map *map)
// {
//     if (strncmp(line, "NO", 2) == 0)
//         map->northTexture = ft_strtrim(line + 3); // Skip "NO " prefix
//     // Handle other texture directions similarly
// }

// void parse_colors(char *line, t_Map *map)
// {
//     char **tokens;
//     if (line[0] == 'F')
//     {
//         tokens = ft_split(line + 2, ',');
//         if (tokens && tokens[0] && tokens[1] && tokens[2])
//         {
//             map->floorColor[0] = ft_atoi(tokens[0]);
//             map->floorColor[1] = ft_atoi(tokens[1]);
//             map->floorColor[2] = ft_atoi(tokens[2]);
//         }
//     }
//     // Handle ceiling color similarly
//     // Free tokens if necessary
// }

// void handle_line(char *line, t_Map *map)
// {
//     if (line[0] == 'R')
//         parse_resolution(line, map);
//     else if (ft_strncmp(line, "NO", 2) == 0)
//         parse_texture(line, map);
//     else if (line[0] == 'F' || line[0] == 'C')
//         parse_colors(line, map);
//     //else
//         // Handle other lines, like the map grid
// }
