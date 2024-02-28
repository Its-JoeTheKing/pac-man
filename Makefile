CC = gcc
utils = utils/map_parsing.c utils/path_tracing.c utils/flood_map.c utils/extra.c utils/config.c utils/movements.c
get_next_line = ff/get_next_line.c ff/get_next_line_utils.c
FLAGS = -lmlx -framework OpenGL -framework AppKit -o so_long
all:
	$(CC) $(get_next_line) $(utils) so_long.c $(FLAGS) -g