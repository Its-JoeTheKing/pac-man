/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:08:46 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/22 08:49:08 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	nb_len(int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_atoi(int nb)
{
	long	r;
	int		i;
	char	*res;

	r = nb;
	i = nb_len(r) - 1;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	if (r == 0)
	{
		res[0] = '0';
		return (free(res), res);
	}
	while (i >= 0)
	{
		res[i] = r % 10 + '0';
		r /= 10;
		i--;
	}
	res[nb_len(nb) + 1] = '\0';
	return (free(res), res);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	close_win(t_info *infos)
{
	exit_game(infos, 1);
	return (0);
}
