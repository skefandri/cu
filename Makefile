CC	= cc

NAME	= cub3D

BONUS	= cub3D_bonus

MLX_DIR	= /nfs/homes/yachaab/Desktop/minilibx-linux

MLX_LIB	= -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

CFLAGS	= -Werror -Wall -Wextra -fsanitize=address -g3 

SRC_PAR	= parse.c texture.0.0.c texture.0.1.c map.0.0.c map.0.1.c \
		util/ft_split.c util/util.0.0.c util/util.0.1.c util/util.0.2.c

SRC_REN	= main.c rendering/drawing.c \
		rendering/raycasting.c \
		rendering/key_event.c

SRC_BON	= main.c  rendering_bonus/drawing.c rendering_bonus/raycasting.c \
		rendering_bonus/key_event.c 

SRC_PAR_PRE	= $(addprefix parssing/, $(SRC_PAR))

SRC_REN_PRE = $(addprefix Mandatory/, $(SRC_REN))

SRC_BON_PRE = $(addprefix bonus/, $(SRC_BON))

OBJ_DIR = objects

OBJ_PAR = $(addprefix $(OBJ_DIR)/, $(SRC_PAR_PRE:.c=.o))

OBJ_REN = $(addprefix $(OBJ_DIR)/, $(SRC_REN_PRE:.c=.o))

OBJ_BON = $(addprefix $(OBJ_DIR)/, $(SRC_BON_PRE:.c=.o))

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJ_PAR)  $(OBJ_REN)
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX_LIB)

$(BONUS) : $(OBJ_BON) $(OBJ_PAR) 
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX_LIB)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

git : 
	make fclean && git add . && git commit -m "AFTER MERGE | SEGV RENDRING PART" && git push -f origin master

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME) $(BONUS)

re : fclean $(NAME)
