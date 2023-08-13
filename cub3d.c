/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabr <ysabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:25:29 by ysabr             #+#    #+#             */
/*   Updated: 2023/08/12 09:03:31 by ysabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"


int	ft_sttrlen(char *str, char set)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != set)
		len++;
	return (len);
}

int	check_name_map(char *parm)
{
	int	name_len;

	name_len = ft_sttrlen(parm, '\0');
	if ((name_len < 5) || parm[name_len - 1] != 'b'
		|| parm[name_len - 2] != 'u'
		|| parm[name_len - 3] != 'c' || parm[name_len - 4] != '.'
		|| parm[name_len - 5] == '/')
		return (0);
	return (1);
}

void	errmsg(char *str)
{
	write(2, str, ft_strlen(str));
}
int	ft_open(int fd, char *filename)
{
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}
	return (fd);
}

// char	*read_file(char *filename)
// {
// 	int		fd;
// 	char	*str;
// 	int		i;
// 	char	c;
// 	int		d;

// 	fd = open(filename, O_RDONLY, 0777);
// 	if (fd == -1)
// 		return (NULL);
// 	d = 0;
// 	while (1)
// 	{
// 		i = read(fd, &c, 1);
// 		if (i == 0)
// 			break ;
// 		if (i == -1)
// 			return (NULL);
// 		d += i;
// 	}
// 	close(fd);
// 	str = malloc(d + 1);
// 	fd = open(filename, O_RDONLY, 0777);
// 	read(fd, str, d);
// 	str[d] = '\0';
// 	close(fd);
// 	if (str[0] == '\0')
// 		return (NULL);
// 	return (str);
// }

// char	*ft_read_map(char *filename)
// {
// 	char	*file_contents;

// 	file_contents = read_file(filename);
// 	return (file_contents);
// }


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	char map[10][10] = {
		"1111111111",
		"1000000001",
		"1100W00011",
		"1100000011",
		"1111111111",
		"1100000011",
		"1111111111",
		"1110000001",
		"1111111111",
		"1111111111",
	
	};
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 40 * 10, 40 * 10, "Hello World!");
	img.img = mlx_new_image(mlx, 40 * 10, 40 * 10);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int x = 0;
	int y = 0;
	while(y < 40 * 10)
	{
		x = 0;
		while(x < 40 * 10)
		{
			if (y % 40 == 0 || x % 40 == 0)
				my_mlx_pixel_put(&img, x, y, 0);
			else if (map[y / 40][x / 40] == '1')
				my_mlx_pixel_put(&img, x, y, 255);
			else
				my_mlx_pixel_put(&img, x, y, 0x00FF00);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0,0);
	mlx_loop(mlx);
}


// // int	main(int ac, char **av)
// // {
// // 	t_info	info;
// // 	void	*mlx;
// // 	void	*mlx_win;
// // 	t_data	img;

// // 	if (ac != 2 || !check_name_map(av[1]))
// //     {
// //         errmsg("Usage: ./program mapfile.cub\n");
// //         return (EXIT_FAILURE);
// //     }

// //     char *str = ft_read_map(av[1]);
// //     if (!str) {
// //         errmsg("empty map\n");
// //         return (EXIT_FAILURE);
// //     }

// // 	char **map = ft_split(str, &info);
// // 	mlx = mlx_init();
// // 	mlx_win = mlx_new_window(mlx, 40 * 10, 40 * 10, "Hello World!");
// // 	img.img = mlx_new_image(mlx, 40 * 10 , 40 * 10);
// // 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// // 	int x = 0;
// // 	int y = 0;
// // 	while(y < 40 * 10)
// // 	{
// // 		x = 0;
// // 		while(x < 40 * 10)
// // 		{
// // 			if (y % 40 == 0 || x % 40 == 0)
// // 				my_mlx_pixel_put(&img, x, y, 0);
// // 			else if (map[y / 40][x / 40] == '1')
// // 				my_mlx_pixel_put(&img, x, y, 255);
// // 			else
// // 				my_mlx_pixel_put(&img, x, y, 0x00FF00);
// // 			x++;
// // 		}
// // 		y++;
// // 	}
// // 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0,0);
// // 	mlx_loop(mlx);
// // }

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include "mlx.h"
// #include <math.h>

// #define TILE_SIZE 40
// #define MAP_COLUMNS 10 // Set this based on your .cub file

// // typedef struct  s_data {
// //     void        *img;
// //     char        *addr;
// //     int         bits_per_pixel;
// //     int         line_length;
// //     int         endian;
// // }               t_data;

// // Read file function
// char	*ft_read_map(char *filename)
// {
// 	int		fd;
// 	char	*str;
// 	int		i;
// 	char	c;
// 	int		d;

// 	fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 		return (NULL);
// 	d = 0;
// 	while ((i = read(fd, &c, 1)) > 0)
// 	{
// 		d += i;
// 	}
// 	close(fd);
// 	str = malloc(d + 1);
// 	fd = open(filename, O_RDONLY);
// 	read(fd, str, d);
// 	str[d] = '\0';
// 	close(fd);
// 	if (str[0] == '\0')
// 		return (NULL);
// 	return (str);
// }

// static int	count_word(const char *s, int c)
// {
// 	int	count;
// 	int	i;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }


// Split map into 2D array
// char	**ft_split(char *str, int *rows)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	**result;

// 	i = 0;
// 	*rows = 0;
// 	while (str[i])
// 		if (str[i++] == '\n')
// 			(*rows)++;
// 	result = (char **)malloc((*rows + 1) * sizeof(char *));
// 	i = 0;
// 	k = 0;
// 	while (i < *rows)
// 	{
// 		result[i] = (char *)malloc(MAP_COLUMNS + 1); // set map_columns properly
// 		j = 0;
// 		while (str[k] != '\n' && str[k])
// 			result[i][j++] = str[k++];
// 		result[i][j] = '\0';
// 		i++;
// 		k++;
// 	}
// 	result[i] = NULL;
// 	return (result);
// }

// int main(int ac, char **av)
// {
//     (void)ac;
//     t_data img;
//     void *mlx;
//     void *mlx_win;
//     char *str = read_file(av[1]);
//     int rows;
//     char **map = ft_split(str, &rows);

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, TILE_SIZE * MAP_COLUMNS, TILE_SIZE * rows, "2D RayCasting");
//     img.img = mlx_new_image(mlx, TILE_SIZE * MAP_COLUMNS, TILE_SIZE * rows);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//     int x = 0;
//     int y = 0;
//     while(y < TILE_SIZE * rows)
//     {
//         x = 0;
//         while(x < TILE_SIZE * MAP_COLUMNS)
//         {
//             if (y % TILE_SIZE == 0 || x % TILE_SIZE == 0)
//                 my_mlx_pixel_put(&img, x, y, 0xFFFFFF); // Grid
//             else if (map[y / TILE_SIZE][x / TILE_SIZE] == '1')
//                 my_mlx_pixel_put(&img, x, y, 0x000000); // Wall
//             else
//                 my_mlx_pixel_put(&img, x, y, 0x00FF00); // Floor
//             x++;
//         }
//         y++;
//     }

//     // Player position
//     int player_x = TILE_SIZE * 5;
//     int player_y = TILE_SIZE * 5;
//     int ray_length = 100; // Length of the rays

//     // Draw the player
//     my_mlx_pixel_put(&img, player_x, player_y, 0xFF0000);

//     // Draw rays in 8 directions
//     for (int i = 0; i < 8; i++)
// 	{
//         int dx = ray_length * cos(i * M_PI / 4);
//         int dy = ray_length * sin(i * M_PI / 4);
//         draw_ray(&img, player_x, player_y, player_x + dx, player_y + dy, 0x0000FF);
//     }

//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//     mlx_loop(mlx);
//     return (0);
// }
