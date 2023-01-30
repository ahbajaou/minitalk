/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:27:31 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/01/30 03:59:44 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + str[i] - 48;
		i++;
	}
	return (k * j);
}

void	ft_send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		if (msg[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

char	*to_binary(char msg)
{
	int		i;
	char	*new;

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
	int		pid;
	int		i;
	char	*msg;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			msg = to_binary(av[2][i]);
			ft_send_msg(pid, msg);
			i++;
		}
		free(msg);
	}
	else
		write(1, "Rah Khass Ekono 3 dl'param\n", 28);
	return (0);
}
