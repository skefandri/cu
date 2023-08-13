NAME = cub3D

SRC_MAN = cub3d.c  ./utils/ft_atoi.c ./utils/ft_split.c ./utils/ft_strdup.c ./utils/ft_bzero.c ./utils/ft_strjoin.c ./utils/ft_strcmp.c \
		./utils/ft_calloc.c ./utils/ft_strlcpy.c  ./utils/ft_itoa.c ./utils/ft_strlen.c ./utils/ft_strncmp.c ./utils/my_check.c \
		./parse/pars_map.c 

CFLAGS =  -Wall -Wextra -Werror -fsanitize=address -g3  -lmlx -framework OpenGL -framework AppKit

all : $(NAME)
$(NAME) : $(SRC_MAN)
		cc  $(CFLAGS) $(SRC_MAN) -o $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

