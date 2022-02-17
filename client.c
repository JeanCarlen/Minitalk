/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:19:10 by jcarlen           #+#    #+#             */
/*   Updated: 2022/02/17 17:16:42 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <signal.h>
#include <unistd.h>

void	ft_putnbr_base(int pid, int nb);
int		ft_atoi(const char *str);

int	main(int argc, char const *argv[])
{
	ft_putnbr_base(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	nb;

	nb = 0;
	neg = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		++str;
	if (*str == '-')
	{
		neg *= -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while ('0' <= *str && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		++str;
	}
	return (nb * neg);
}

void	ft_putnbr_base(int pid, int nb)
{
	int	b_size;

	b_size = 2;
	if (nb / b_size)
		ft_putnbr_base(pid, nb / b_size);
	if (nb % b_size == 0)
		kill(pid, SIGUSR1);
	if (nb % b_size == 1)
		kill(pid, SIGUSR2);
	usleep(10);
}
