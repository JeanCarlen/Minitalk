/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:19:10 by jcarlen           #+#    #+#             */
/*   Updated: 2022/03/01 14:24:31 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static int	g_signal;

void	send_bits(int pid, char const *text)
{
	int		bit;
	char	c;

	while (*text)
	{
		bit = 8;
		c = *text;
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			pause();
		}
		text++;
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		pause();
	}
}

void	ft_error(int sig)
{
	static int	count = -7;

	if (sig == SIGUSR1)
		count++;
	else
	{
		ft_putnbr_fd(count, 1);
		ft_putchar_fd('\n', 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char const *argv[])
{
	int			pid;

	g_signal = 1;
	if (argc != 3)
	{
		ft_putstr_fd("client: invalid arguments.\n", 1);
		ft_putstr_fd("correct format: [./client <PID> \"STR\"].\n", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_error);
	signal(SIGUSR2, ft_error);
	send_bits(pid, argv[2]);
}
