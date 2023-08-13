/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabr <ysabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:25:41 by ysabr             #+#    #+#             */
/*   Updated: 2023/08/12 00:13:40 by ysabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
#include <mlx.h>

typedef struct
{
	int		resolution[2];
	char	*northTexture;
	int		floorColor[3];
	int		ceilingColor[3];
	int		**mapGrid;
} t_Map;

typedef struct
{
	int	col_len;
	int	row_len;
}	t_info;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_plit
{
	int		i;
	int		j;
	int		y;
	char	**resl;
}			t_split;

//libft
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
// char	**ft_split(char *str, t_info *data);
char		*ft_strchr(char *str, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*malloc(size_t size);

//utils
void handle_line(char *line, t_Map *map);
void parse_colors(char *line, t_Map *map);
void parse_texture(char *line, t_Map *map);
char	*ft_strtrim(char *s);
void parse_resolution(char *line, t_Map *map);
void	errmsg(char *str);
int	ft_sttrlen(char *str, char set);


#endif