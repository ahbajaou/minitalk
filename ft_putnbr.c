/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:10:17 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/01/21 01:40:11 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int nb)
{
	int	np;

	np = 0;
	if (nb < 0)
	{
		np += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		np += ft_putnbr(nb / 10);
		np += ft_putnbr(nb % 10);
	}
	else
		np += ft_putchar(nb + '0');
	return (np);
}
