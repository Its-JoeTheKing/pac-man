CC = gcc
utils = utils/map_parsing.c utils/movements.c utils/path_finder_extra.c utils/path_tracing.c utils/flood_map.c
get_next_line = ff/get_next_line.c ff/get_next_line_utils.c
FLAGS = -lmlx -framework OpenGL -framework AppKit -o so_long -g
all:
	$(CC) so_long.c $(utils) $(get_next_line) $(FLAGS)