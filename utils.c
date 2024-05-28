/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:25 by yutsasak          #+#    #+#             */
/*   Updated: 2024/05/28 15:12:17 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long long nbr, char *base)
{
	unsigned long long	base_digits;
	int					len;

	len = 0;
	base_digits = 0;
	while (base[base_digits])
		base_digits++;
	if (nbr < base_digits)
		len += ft_putchar(base[nbr]);
	else
	{
		len += ft_putaddress(nbr / base_digits, base);
		len += ft_putaddress(nbr % base_digits, base);
	}
	return (len);
}

int	ft_putnbr(long long nbr, char *base)
{
	long long	base_digits;
	int			len;

	len = 0;
	base_digits = 0;
	while (base[base_digits])
		base_digits++;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < base_digits)
		len += ft_putchar(base[nbr]);
	else
	{
		len += ft_putnbr(nbr / base_digits, base);
		len += ft_putnbr(nbr % base_digits, base);
	}
	return (len);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[len])
		len++;
	return (write(1, s, len));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
