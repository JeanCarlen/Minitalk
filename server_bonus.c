/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:19:18 by jcarlen           #+#    #+#             */
/*   Updated: 2022/03/01 14:29:56 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	micheline(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			ft_putchar_fd('\n', 1);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
	usleep(25);
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa_signal;

	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = micheline;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
