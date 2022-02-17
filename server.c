/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:19:18 by jcarlen           #+#    #+#             */
/*   Updated: 2022/02/17 17:16:41 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	test(int signum)
{
	if (signum == SIGUSR1)
		write(1, "0", 1);
	else if (signum == SIGUSR2)
		write(1, "1", 1);
}

int	main(void)
{
	signal(SIGUSR1, test);
	signal(SIGUSR2, test);
	printf("%d \n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
