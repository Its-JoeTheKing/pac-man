CC = cc
RM = rm -f

utils = so_long.c utils/map_parsing.c utils/extra.c utils/config.c utils/movements.c \
	 utils/bloodfill.c utils/ft_atoi.c utils/get_next_line.c utils/get_next_line_utils.c

bonus_utils = so_long_bonus.c utils_bonus/map_parsing.c utils_bonus/path_tracing.c \
 	utils_bonus/flood_map.c utils_bonus/extra.c utils_bonus/config.c utils_bonus/movements.c \
	utils_bonus/bloodfill.c utils_bonus/ft_atoi.c utils_bonus/get_next_line.c utils_bonus/get_next_line_utils.c

utils_objs = ${utils:.c=.o}
bonus_utils_objs = ${bonus_utils:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
FLAGS = -lmlx -framework OpenGL -framework AppKit

name = so_long
bonus_name = so_long_bonus
header = utils/so_long.h
bonus_header = utils_bonus/so_long_bonus.h

all: $(name)
bonus: $(bonus_name)

utils/%.o: utils/%.c $(header)
	$(CC) $(CFLAGS) -c $< -o $@

utils_bonus/%.o: utils_bonus/%.c $(bonus_header)
	$(CC) $(CFLAGS) -c $< -o $@

$(name): $(utils_objs) $(header)
	$(CC) $(CFLAGS) $(utils_objs) $(FLAGS) -o $(name)

$(bonus_name): $(bonus_utils_objs) $(bonus_header)
	$(CC) $(CFLAGS) $(bonus_utils_objs) $(FLAGS) -o $(bonus_name)

clean:
	$(RM) $(utils_objs) $(bonus_utils_objs)

fclean: clean
	$(RM) $(name) $(bonus_name)

re: fclean all

.phony: clean