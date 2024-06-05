/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:26:03 by yutsasak          #+#    #+#             */
/*   Updated: 2024/06/05 22:12:01 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_special_formats(va_list *ap, const char *fmt, int *len)
{
	char	*str;

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
}

static int	put_fmt(va_list *ap, const char *fmt, int *len)
{
	int	ret;

	if (*fmt == '%')
	{
		ret = ft_putchar('%');
		if (ret == -1)
			return (-1);
		*len += ret;
	}
	else if (*fmt == 'd' || *fmt == 'i')
	{
		ret = ft_putnbr(va_arg(*ap, int), "0123456789");
		if (ret == -1)
			return (-1);
		*len += ret;
	}
	else if (*fmt == 'u' || *fmt == 'x' || *fmt == 'X')
	{
		if (handle_unsigned(ap, fmt, len) == -1)
			return (-1);
	}
	else
		handle_special_formats(ap, fmt, len);
	return (0);
}

int	handle_unsigned(va_list *ap, const char *fmt, int *len)
{
	int	ret;

	if (*fmt == 'u')
	{
		ret = ft_putnbr(va_arg(*ap, unsigned int), "0123456789");
		if (ret == -1)
			return (-1);
		*len += ret;
	}
	else if (*fmt == 'x')
	{
		ret = ft_putnbr(va_arg(*ap, unsigned int), "0123456789abcdef");
		if (ret == -1)
			return (-1);
		*len += ret;
	}
	else if (*fmt == 'X')
	{
		ret = ft_putnbr(va_arg(*ap, unsigned int), "0123456789ABCDEF");
		if (ret == -1)
			return (-1);
		*len += ret;
	}
	return (0);
}

static int	handle_char(const char **fmt, va_list *ap, int *len)
{
	int	ret;

	if (**fmt == '%')
	{
		(*fmt)++;
		ret = put_fmt(ap, *fmt, len);
		if (ret == -1)
			return (-1);
	}
	else
	{
		ret = ft_putchar(**fmt);
		if (ret == -1)
			return (-1);
		*len += ret;
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (handle_char(&fmt, &ap, &len) == -1)
		{
			va_end(ap);
			return (-1);
		}
		fmt++;
	}
	va_end(ap);
	return (len);
}
