#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"
#include <math.h>

#define TILE_SIZE 40
#define MAP_COLUMNS 10 // Set this based on your .cub file

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

// Read file function
char	*read_file(char *filename)
{
	int		fd;
	char	*str;
	int		i;
	char	c;
	int		d;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	d = 0;
	while ((i = read(fd, &c, 1)) > 0)
	{
		d += i;
	}
	close(fd);
	str = malloc(d + 1);
	fd = open(filename, O_RDONLY);
	read(fd, str, d);
	str[d] = '\0';
	close(fd);
	if (str[0] == '\0')
		return (NULL);
	return (str);
}

// Split map into 2D array
char	**ft_split(char *str, int *rows)
{
	int		i;
	int		j;
	int		k;
	char	**result;

	i = 0;
	*rows = 0;
	while (str[i])
		if (str[i++] == '\n')
			(*rows)++;
	result = (char **)malloc((*rows + 1) * sizeof(char *));
	i = 0;
	k = 0;
	while (i < *rows)
	{
		result[i] = (char *)malloc(MAP_COLUMNS + 1); // set map_columns properly
		j = 0;
		while (str[k] != '\n' && str[k])
			result[i][j++] = str[k++];
		result[i][j] = '\0';
		i++;
		k++;
	}
	result[i] = NULL;
	return (result);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_ray(t_data *img, int x0, int y0, int x1, int y1, int color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;

    for (;;) {
        my_mlx_pixel_put(img, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 <  dy) { err += dx; y0 += sy; }
    }
}

int main(int ac, char **av)
{
    (void)ac;
    t_data img;
    void *mlx;
    void *mlx_win;
    char *str = read_file(av[1]);
    int rows;
    char **map = ft_split(str, &rows);

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, TILE_SIZE * MAP_COLUMNS, TILE_SIZE * rows, "2D RayCasting");
    img.img = mlx_new_image(mlx, TILE_SIZE * MAP_COLUMNS, TILE_SIZE * rows);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    int x = 0;
    int y = 0;
    while(y < TILE_SIZE * rows)
    {
        x = 0;
        while(x < TILE_SIZE * MAP_COLUMNS)
        {
            if (y % TILE_SIZE == 0 || x % TILE_SIZE == 0)
                my_mlx_pixel_put(&img, x, y, 0xFFFFFF); // Grid
            else if (map[y / TILE_SIZE][x / TILE_SIZE] == '1')
                my_mlx_pixel_put(&img, x, y, 0x000000); // Wall
            else
                my_mlx_pixel_put(&img, x, y, 0x00FF00); // Floor
            x++;
        }
        y++;
    }

    // Player position
    int player_x = TILE_SIZE * 5;
    int player_y = TILE_SIZE * 5;
    int ray_length = 100; // Length of the rays

    // Draw the player
    my_mlx_pixel_put(&img, player_x, player_y, 0xFF0000);

    // Draw rays in 8 directions
    for (int i = 0; i < 8; i++) {
        int dx = ray_length * cos(i * M_PI / 4);
        int dy = ray_length * sin(i * M_PI / 4);
        draw_ray(&img, player_x, player_y, player_x + dx, player_y + dy, 0x0000FF);
    }

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    return (0);
}
