/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:27:31 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/01/30 23:36:48 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_error(void)
{
	write(1, "---PID INVALID---\n", 19);
	exit(0);
}

int	ft_atoi(char	*str)
{
	unsigned long	i;
	unsigned long	j;
	int				k;

	i = 0;
	j = 0;
	k = 1;
	while (str[i] == 32 || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k *= -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			j = (j * 10) + str[i++] - 48;
	}
	else
		check_error();
	return (k * j);
}

void	ft_send_msg(int pid, unsigned char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		if (msg[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		i++;
	}
	free(msg);
}

unsigned char	*to_binary(unsigned char msg)
{
	int				i;
	unsigned char	*new;

	i = 7;
	new = malloc(9);
	while (i >= 0)
	{
		new[i] = (msg % 2) + '0';
		msg = msg / 2;
		i--;
	}
	new[8] = '\0';
	return (new);
}

int	main(int ac, char **av)
{
	int				pid;
	int				i;
	unsigned char	*msg;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == -1 || pid == 0)
			return (1);
		while (av[2][i])
		{
			msg = (unsigned char *)to_binary(av[2][i]);
			ft_send_msg(pid, msg);
			i++;
		}
	}
	else
		write(1, "---Please enter three argument---\n", 35);
	return (0);
}
