
HEAD = includes/

SRCS =  src/ft_interior.c  src/ft_interior2.c  src/ft_isspace.c\
		src/ft_map_validator.c src/ft_move.c \
		src/ft_parser.c src/ft_parser2.c   src/ft_parser4.c src/ft_parser5.c\
		src/ft_parser6texture.c src/ft_raycaster.c src/ft_raycaster2.c src/ft_map_validator2.c src/ft_printscreen.c \
		src/ft_sprite_parser.c src/ft_sprite.c src/ft_sprite2.c src/ft_sprite3.c

NORM = src/ft_engine.c src/ft_move2music.c src/ft_parser3init.c

SRCSBONUS = src/bonus/ft_engine_bonus.c src/bonus/ft_move2music_bonus.c src/bonus/ft_parser3init_bonus.c \

NAME = cub3D

OBJS = $(patsubst %.c,%.o,$(SRCS))
NOBJS = $(patsubst %.c,%.o,$(NORM))
BOBJS = $(patsubst %.c,%.o,$(SRCSBONUS))

LIBFT = ./libft/libft.a
MLX = -L . -lmlx
MLX_LIB = libmlx.dylib
FLAGS = -I $(HEAD) -Wall -Wextra -Werror
RM = rm -rf
CC = gcc

ifdef WITH_BONUS
	AOFILES := $(OBJS) $(BOBJS)
else
	AOFILES := $(OBJS) $(NOBJS)
endif

$(NAME): $(HEAD)*.h $(LIBFT) $(MLX_LIB) $(AOFILES)
	gcc $(FLAGS) $(AOFILES)  $(LIBFT) $(MLX) -o $(NAME)


all:	lib mlxlib $(NAME)

bonus: 
	$(MAKE) WITH_BONUS=1 all

lib:
	@make -C ./libft

mlxlib:
	@make -C ./mlx $(MLX_LIB)


$(LIBFT):
	$(MAKE) -C ./libft

$(MLX_LIB):
	$(MAKE) -C ./mlx
	mv ./mlx/libmlx.dylib $(MLX_LIB)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c  $< -o $@ -I$(HEAD)


clean:
		${RM}	$(OBJS)
		${RM}	$(NOBJS)
		${RM}	$(BOBJS)
		$(MAKE)	fclean -C ./libft
		$(MAKE)	clean -C ./mlx

fclean: clean
		${RM}	$(NAME)
		${RM}	screenshot.bmp
		${RM}	libmlx.dylib
		$(MAKE)	fclean -C ./libft


re: fclean all


.PHONY:  all, clean, fclean, re