/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:00:39 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/01/29 23:47:22 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	bin_to_char(char *msg)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c = c * 2 + (msg[i] - '0');
		i++;
	}
	write(1, &c, 1);
}

void	signal_handler(int sig)
{
	static char	msg[9];
	static int	i = 0;

	if (sig == SIGUSR1)
		msg[i] = '0';
	else
		msg[i] = '1';
	i++;
	if (i == 8)
	{
		msg[i] = '\0';
		bin_to_char(msg);
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Processe ID : %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
