/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:51:53 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/01/21 01:39:45 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexad(unsigned long int nb, char *h, int *np)
{
	if (nb >= 16)
		ft_hexad((nb / 16), h, np);
	*np += ft_putchar(h[nb % 16]);
}
