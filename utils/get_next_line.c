/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:47:14 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/16 13:55:13 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		readed;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (free(str), str = NULL, NULL);
	readed = 1;
	while (!ft_strchr(str, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		buff[readed] = '\0';
		if (readed == -1)
			return (free(buff), NULL);
		str = ft_strjoin(str, buff);
	}
	free(buff);
	if (!str || !*str)
		return (free(str), str = NULL, NULL);
	return (str);
}

char	*_get_line(char *line)
{
	char	*res;
	int		i;

	i = 0;
	if (!line || !*line)
		return (free(line), line = NULL, NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (!ft_strchr(line, '\n'))
		i--;
	res = malloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		res[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		res[i++] = '\n';
	res[i] = 0;
	return (res);
}

char	*get_rem(char *line)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (free(line), NULL);
	res = malloc(ft_strlen(line) - i);
	if (!res)
		return (free (line), NULL);
	j = 0;
	i++;
	while (line[i + j])
	{
		res[j] = line[i + j];
		j++;
	}
	res[j] = 0;
	return (free(line), res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rem_str = NULL;

	line = 0;
	if (BUFFER_SIZE <= 0
		|| read(fd, 0, 0) == -1 || BUFFER_SIZE > 2147483647)
		return (free(rem_str), rem_str = NULL, NULL);
	rem_str = ft_read(fd, rem_str);
	if (!rem_str)
		return (NULL);
	line = _get_line(rem_str);
	if (!line)
		return (free (rem_str), rem_str = NULL, NULL);
	rem_str = get_rem(rem_str);
	return (line);
}
