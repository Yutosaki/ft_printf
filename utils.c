/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:25 by yutsasak          #+#    #+#             */
/*   Updated: 2024/05/26 19:50:36 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_fmt(va_list ap, const char *fmt, int *len)
{
	if (*fmt == '%')
		*len += ft_putchar('%');
	else if (*fmt == 'c' || *fmt == 'd' || *fmt == 'i' || *fmt == 'u')
		handle_basic_formats(ap, fmt, len);
	else if (*fmt == 'x' || *fmt == 'X')
		handle_hex_formats(ap, fmt, len);
	else if (*fmt == 'p')
		handle_pointer_format(ap, len);
	else if (*fmt == 's')
		handle_string_format(ap, len);
}

int	ft_putaddress(unsigned long long nbr, char *base)
{
	unsigned long long	base_digits;
	int					len;
	int					more;

	base_digits = 0;
	while (base[base_digits])
	{
		base_digits++;
	}
	if (nbr < base_digits)
	{
		return (ft_putchar(base[nbr]));
	}
	else
	{
		len = ft_putnbr(nbr / base_digits, base);
		if (len == -1)
			return (-1);
		more = ft_putnbr(nbr % base_digits, base);
		if (more == -1)
			return (-1);
		return (len + more);
	}
}

int	ft_putnbr(long long nbr, char *base)
{
	long long	base_digits;

	int (more), len, neg = 0;
	base_digits = 0;
	while (base[base_digits])
		base_digits++;
	if (nbr < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nbr = -nbr;
		neg++;
	}
	if (nbr < base_digits)
		return (ft_putchar(base[nbr]));
	else
	{
		len = ft_putnbr(nbr / base_digits, base);
		if (len == -1)
			return (-1);
		more = ft_putnbr(nbr % base_digits, base);
		if (more == -1)
			return (-1);
		return (len + more + neg);
	}
}

int	ft_putstr(char *s)
{
	int		len;
	ssize_t	result;

	len = 0;
	if (!s)
		return (-1);
	while (s[len])
		len++;
	result = write(1, s, len);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_putchar(char c)
{
	ssize_t	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (result);
}
