// # include <stdint.h>
// # include <stdbool.h>
// # include <stdlib.h>
// # include <string.h>
// # include <stdio.h>
// # include <ctype.h>
// # include <fcntl.h>
// # include <stdio.h>
// # include <unistd.h>
// #include <mlx.h>
// #include <math.h>

// // #define M_PI 3.14
// // Define player and map dimensions
// typedef struct {
// 	int x;
// 	int y;
// 	double direction;
// } t_player;

// typedef struct
// {
// 	int	col_len;
// 	int	row_len;
// }	t_info;

// typedef struct {
// 	int row_len;
// 	int col_len;
// 	char **map;
// } t_map;

// typedef struct s_plit
// {
// 	int		i;
// 	int		j;
// 	int		y;
// 	char	**resl;
// }			t_split;

// int	ft_sttrlen(char *str, char set)
// {
// 	int	len;

// 	len = 0;
// 	if (!str)
// 		return (0);
// 	while (str[len] && str[len] != set)
// 		len++;
// 	return (len);
// }

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// void	errmsg(char *str)
// {
// 	write(2, str, ft_strlen(str));
// }

// char	**ft_malloc(t_split *split, t_info *data)
// {
// 	char	**resl;

// 	split->j = 0;
// 	split->i = 0;
// 	resl = malloc(sizeof(char *) * (data->row_len + 1));
// 	if (!resl)
// 		errmsg("malloc failed !");
// 	resl[data->row_len] = NULL;
// 	return (resl);
// }

// char	**ft_split(char *str, t_info *data)
// {
// 	t_split	split;

// 	split.resl = ft_malloc(&split, data);
// 	data->col_len = ft_sttrlen(str, '\n');
// 	while (split.resl && str[split.i])
// 	{
// 		split.y = 0;
// 		split.resl[split.j] = malloc(sizeof(char) * (data->col_len + 1));
// 		if (!split.resl[split.j])
// 			errmsg("malloc failed !");
// 		while (str[split.i + split.y] && str[split.i + split.y] != '\n')
// 		{
// 			split.resl[split.j][split.y] = str[split.i + split.y];
// 			split.y++;
// 		}
// 		split.resl[split.j][split.y] = '\0';
// 		if (!str[split.i + split.y])
// 			return (split.resl);
// 		split.i += split.y;
// 		split.j++;
// 		split.i++;
// 		if (str[split.i] && data->col_len != ft_sttrlen(&str[split.i], '\n'))
// 			errmsg ("The lines in the map are not compatible !");
// 	}
// 	return (split.resl);
// }
// void read_map(char *filename, t_map *map)
// {
// 	int fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error reading map");
// 		exit(EXIT_FAILURE);
// 	}

// 	char buffer[4096];
// 	int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
// 	if (bytes_read <= 0) {
// 		perror("Error reading map file");
// 		close(fd);
// 		exit(EXIT_FAILURE);
// 	}
// 	buffer[bytes_read] = '\0';

// 	int row_len = 0;
// 	int col_len = 0;
// 	int i = 0;
// 	while (i < bytes_read)
// 	{
// 		if (buffer[i] == '\n')
// 		{
// 			row_len++;
// 			if (col_len == 0)
// 				col_len = i;
// 		}
// 		i++;
// 	}
// 	if (buffer[i - 1] != '\n')
// 		row_len++;
// 	t_info info;
// 	info.row_len = row_len;
// 	info.col_len = col_len;

// 	map->row_len = row_len;
// 	map->col_len = col_len;
// 	map->map = ft_split(buffer, &info);

// 	close(fd);
// }

// void render_player(t_player *player)
// {
// 	printf("Player is at (%d, %d) facing direction %.2lf radians\n",
// 		   player->x, player->y, player->direction);
// }

// void render_rays(t_player *player, t_map *map)
// {
// 	int num_rays = 60;
// 	double fov = M_PI / 3;
// 	double angle_step = fov / num_rays;
// 	int max_distance = 20;
// 	int i = 0;
// 	int d = 0;

// 	while (i < num_rays)
// 	{
// 		double angle = player->direction - fov / 2 + i * angle_step;
// 		while ( d < max_distance)
// 		{
// 			int x = player->x + d * cos(angle);
// 			int y = player->y + d * sin(angle);
// 			if (x < 0 || y < 0 || x >= map->col_len || y >= map->row_len || map->map[y][x] == '1')
// 			{
// 				printf("Ray %d hit a wall at (%d, %d)\n", i, x, y);
// 				break ;
// 			}
// 			d++;
// 		}
// 		i++;
// 	}
// }
// void calculate_map_size(char *filename, int *row_len, int *col_len)
// {
// 	int fd = open(filename, O_RDONLY);
// 	int i = 0;
// 	if (fd == -1) {
// 		perror("Error reading map");
// 		exit(EXIT_FAILURE);
// 	}

// 	char buffer[4096];
// 	int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
// 	if (bytes_read <= 0) {
// 		perror("Error reading map file");
// 		close(fd);
// 		exit(EXIT_FAILURE);
// 	}
// 	buffer[bytes_read] = '\0';

// 	*row_len = 0;
// 	*col_len = 0;

// 	while (i < bytes_read)
// 	{
// 		if (buffer[i] == '\n')
// 		{
// 			(*row_len)++;
// 			if (*col_len == 0)
// 				*col_len = i;
// 		}
// 		i++;
// 	}

// 	if (buffer[bytes_read - 1] != '\n')
// 		(*row_len)++;

// 	close(fd);
// }

// typedef struct	s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }
// void draw_player(t_data *data, t_player *player)
// {
// 	int player_size = 5;
// 	int y = player->y * 40 - player_size;
// 	int x = player->x * 40 - player_size;
// 	while (y <= player->y * 40 + player_size)
// 	{
// 		while (x <= player->x * 40 + player_size)
// 		{
// 			my_mlx_pixel_put(data, x, y, 0xFF0000);
// 			x++;
// 		}
// 		y++;
// 	}
// }


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include <math.h>

#define CELL_SIZE 40
#define PLAYER_SIZE 10

#define MOVE_SPEED 0.005
#define TURN_ANGLE (M_PI / 60)

typedef struct {
	int x;
	int y;
	double direction;
} t_player;

typedef struct {
	int row_len;
	int col_len;
	char **map;
} t_map;

void move_player(t_player *player, t_map *map, double forward, double right);

int ft_strlen(char *str) {
	int i = 0;
	while (str[i]) i++;
	return i;
}

void handle_error(char *message) {
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

char **ft_split(char *str, int row_len, int col_len) {
	char **resl = malloc(sizeof(char *) * (row_len + 1));
	if (!resl) handle_error("malloc failed !");
	resl[row_len] = NULL;
	int i = 0, j = 0, y = 0;
	while (resl && str[i]) {
		y = 0;
		resl[j] = malloc(sizeof(char) * (col_len + 1));
		if (!resl[j]) handle_error("malloc failed !");
		while (str[i + y] && str[i + y] != '\n') {
			resl[j][y] = str[i + y];
			y++;
		}
		resl[j][y] = '\0';
		if (!str[i + y]) return resl;
		i += y;
		j++;
		i++;
	}
	return resl;
}

void calculate_map_size(char *buffer, int bytes_read, int *row_len, int *col_len)
{
	int i = 0;
	*row_len = 0;
	*col_len = 0;
	while (i < bytes_read) {
		if (buffer[i] == '\n') {
			(*row_len)++;
			if (*col_len == 0) *col_len = i;
		}
		i++;
	}
	if (buffer[bytes_read - 1] != '\n') (*row_len)++;
}

void read_map(char *filename, t_map *map)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1) handle_error("Error reading map");
	char buffer[4096];
	int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read <= 0) handle_error("Error reading map file");
	int row_len, col_len;
	calculate_map_size(buffer, bytes_read, &row_len, &col_len);
	map->row_len = row_len;
	map->col_len = col_len;
	map->map = ft_split(buffer, row_len, col_len);
	close(fd);
}

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
	t_map	map;
	t_player player;
	void	*mlx;
	void	*mlx_win;
}	t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;
    while (1)
	{
        my_mlx_pixel_put(data, x0, y0, color);
        if (x0 == x1 && y0 == y1)
			break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 <  dy) { err += dx; y0 += sy; }
    }
}

void draw_player(t_data *data, t_player *player)
{
    int player_size = 5;
    int y = player->y - player_size;
    while ( y <= player->y + player_size)
    {
        int x = player->x  - player_size;
        while (x <= player->x + player_size)
        {
            my_mlx_pixel_put(data, x, y, 0xFF0000); // Player color (red)
            x++;
        }
        y++;
    }
    
    int line_length = 20;
    int line_x = player->x + line_length * cos(player->direction);
    int line_y = player->y - line_length * sin(player->direction);
    draw_line(data, player->x, player->y, line_x, line_y, 0x0000FF);
}



void render_map(t_data *data, t_map *map)
{
    int x = 0, y = 0;
    while (y < map->row_len * CELL_SIZE)
    {
		x = 0;
        while (x < map->col_len * CELL_SIZE)
        {
            if (y % CELL_SIZE == 0 || x % CELL_SIZE == 0)
                my_mlx_pixel_put(data, x, y, 0);
           	else if (map->map[y / CELL_SIZE][x / CELL_SIZE] == '1')
                my_mlx_pixel_put(data, x, y, 255);
            else if (y / CELL_SIZE == data->player.y && x / CELL_SIZE == data->player.x)
            {
                // Draw player as a smaller square in the middle of the grid square
                if ((y % CELL_SIZE >= (CELL_SIZE - PLAYER_SIZE) / 2 && y % CELL_SIZE < (CELL_SIZE + PLAYER_SIZE) / 2) &&
                    (x % CELL_SIZE >= (CELL_SIZE - PLAYER_SIZE) / 2 && x % CELL_SIZE < (CELL_SIZE + PLAYER_SIZE) / 2))
                    my_mlx_pixel_put(data, x, y, 0xFF0000); // Player color (red)
                else
                    my_mlx_pixel_put(data, x, y, 0x00FF00); // Background color (green)
            }
            else
                my_mlx_pixel_put(data, x, y, 0x00FF00); // Background color (green)
			x++;
        }
		y++;
    }
}



#define TURN_ANGLE (M_PI / 60)


void draw_direction_line(t_data *data, t_player *player)
{
    int line_length = 20; // Adjust the length as needed
    int x1 = player->x + cos(player->direction) * line_length;
    int y1 = player->y + sin(player->direction) * line_length;
    draw_line(data, player->x, player->y, x1, y1, 0x0000FF); // Blue color
}

void rotate_player(t_player *player, double angle) {
    player->direction += angle;

    // Normalize the direction to be in the range [0, 2*PI]
    while (player->direction < 0) {
        player->direction += 2 * M_PI;
    }
    while (player->direction >= 2 * M_PI) {
        player->direction -= 2 * M_PI;
    }
}

int key_hook(int keycode, void *param)
{
    t_data *data = (t_data *)param;

    if (keycode == 53) // ESC key to exit
        exit(0);
    if (keycode == 13) // W key to move forward
        move_player(&data->player, &data->map, 1, 0);
    if (keycode == 1) // S key to move backward
        move_player(&data->player, &data->map, -1, 0);
    if (keycode == 0) // A key to move left
        move_player(&data->player, &data->map, 0, -1);
    if (keycode == 2) // D key to move right
        move_player(&data->player, &data->map, 0, 1);
    if (keycode == 123) // Key 123 to rotate counterclockwise
        rotate_player(&data->player, -TURN_ANGLE);
    if (keycode == 124) // Key 124 to rotate clockwise
        rotate_player(&data->player, TURN_ANGLE);

    render_map(data, &data->map);
    draw_player(data, &data->player); // Rendering player
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
    return 0;
}


void move_player(t_player *player, t_map *map, double forward, double right)
{

    double new_x = player->x + right;
    double new_y = player->y + forward;

    if (new_x >= 0 && new_y >= 0 && new_x < map->col_len * CELL_SIZE && new_y < map->row_len * CELL_SIZE &&
        map->map[(int)(new_y / CELL_SIZE)][(int)(new_x / CELL_SIZE)] != '1')
    {
        player->x = new_x;
        player->y = new_y;
    }
}



int main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	t_map map;
	read_map(argv[1], &map);
	t_player player = {2 * 40 + 20, 2 * 40 + 20, M_PI / 4};
	img.map = map;
	img.player = player;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 40 * map.col_len, 40 * map.row_len, "Hello World!");
	img.mlx = mlx;
	img.mlx_win = mlx_win;
	img.img = mlx_new_image(mlx, 40 * map.col_len, 40 * map.row_len);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	render_map(&img, &map);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0,0);
	mlx_hook(mlx_win, 2, 1L << 0, key_hook, &img);
    render_map(&img, &map);
    draw_player(&img, &player); // Adding the draw_player call here
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
