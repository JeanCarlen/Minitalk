/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:19:18 by jcarlen           #+#    #+#             */
/*   Updated: 2022/02/25 14:21:14 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_bit
{
	char		c;
	size_t		size;
}				t_bit;

static t_bit nxt_bit;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void			test1(int bit)
{
	nxt_bit.c += ((bit & 1) << nxt_bit.size);
	nxt_bit.size++;
	if (nxt_bit.size == 7)
	{
		ft_putchar(nxt_bit.c);
		if (!nxt_bit.c)
			ft_putchar('\n');
		nxt_bit.c = 0;
		nxt_bit.size = 0;
	}
}

void	test(int signum)
{
	if (signum == SIGUSR1)
		write(1, "0", 1);
	else if (signum == SIGUSR2)
		write(1, "1", 1);
}


int	main(void)
{
	signal(SIGUSR1, test1);
	signal(SIGUSR2, test1);
	printf("pid is :%d \n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}

/*
int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = test;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	printf("%d \n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
*/