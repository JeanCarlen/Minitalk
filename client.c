/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:19:10 by jcarlen           #+#    #+#             */
/*   Updated: 2022/02/25 11:333:5:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <signal.h>
#include <unistd.h>

void	send_bits(int pid, char const *text, int len);
void	ft_putnbr_base(int pid, int nb);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

size_t	ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


int	main(int argc, char const *argv[])
{
	int			pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_bits(pid, argv[2], ft_strlen(argv[2]));
	}
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

void	send_bits(int pid, char const *text, int len)
{
	int		nxt_char;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		nxt_char = 0;
		while (nxt_char < 7)
		{
			if ((text[i] >> nxt_char) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			nxt_char++;
			usleep(100);
		}
		i++;
	}
}
