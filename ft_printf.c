/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:26:03 by yutsasak          #+#    #+#             */
/*   Updated: 2024/05/28 15:39:45 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_special_formats(va_list *ap, const char *fmt, int *len)
{
	if (*fmt == 'c')
	{
		*len += ft_putchar((char)va_arg(*ap, int));
	}
	else if (*fmt == 'p')
	{
		*len += ft_putstr("0x");
		*len += ft_putaddress(va_arg(*ap, unsigned long long),
				"0123456789abcdef");
	}
	else if (*fmt == 's')
	{
		handle_string_format(ap, len);
	}
}

void	handle_string_format(va_list *ap, int *len)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
	{
		*len += ft_putstr("(null)");
	}
	else
	{
		*len += ft_putstr(str);
	}
}

static void	put_fmt(va_list *ap, const char *fmt, int *len)
{
	if (*fmt == '%')
	{
		*len += ft_putchar('%');
	}
	else if (*fmt == 'd' || *fmt == 'i')
	{
		*len += ft_putnbr(va_arg(*ap, int), "0123456789");
	}
	else if (*fmt == 'u')
	{
		*len += ft_putnbr(va_arg(*ap, unsigned int), "0123456789");
	}
	else if (*fmt == 'x')
	{
		*len += ft_putnbr(va_arg(*ap, unsigned int), "0123456789abcdef");
	}
	else if (*fmt == 'X')
	{
		*len += ft_putnbr(va_arg(*ap, unsigned int), "0123456789ABCDEF");
	}
	else
	{
		handle_special_formats(ap, fmt, len);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			put_fmt(&ap, fmt, &len);
		}
		else
			len += ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (len);
}
