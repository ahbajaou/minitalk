/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:53:38 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/01/21 01:49:43 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_two_printf(va_list ar, char str)
{
	int	np;

	np = 0;
	if (str == 'c')
		np += ft_putchar(va_arg(ar, int));
	else if (str == 's')
		np += ft_putstr(va_arg(ar, char *));
	else if (str == 'i' || str == 'd')
		np += ft_putnbr(va_arg(ar, int));
	else if (str == 'u')
		np += ft_putnbr(va_arg(ar, unsigned int));
	else if (str == 'x')
		ft_hexad(va_arg(ar, unsigned int), "0123456789abcdef", &np);
	else if (str == 'X')
		ft_hexad(va_arg(ar, unsigned int), "0123456789ABCDEF", &np);
	else if (str == 'p')
	{
		np += ft_putstr("0x");
		ft_hexad(va_arg(ar, unsigned long int), "0123456789abcdef", &np);
	}
	else
		np += ft_putchar(str);
	return (np);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			np;
	va_list		ar;

	i = 0;
	np = 0;
	va_start(ar, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			np += ft_two_printf(ar, str[i]);
		}
		else
			np += ft_putchar(str[i]);
		i++;
	}
	va_end(ar);
	return (np);
}
// int	main()
// {
// 	ft_printf("%x\n",-000000000000);
// }