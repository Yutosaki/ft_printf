/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:02:05 by yutsasak          #+#    #+#             */
/*   Updated: 2024/05/08 20:07:59 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));

void	put_fmt(va_list ap, const char *fmt, int *len);
void	handle_basic_formats(va_list ap, const char *fmt, int *len);
void	handle_hex_formats(va_list ap, const char *fmt, int *len);
void	handle_pointer_format(va_list ap, int *len);
void	handle_string_format(va_list ap, int *len);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long long nbr, char *base);
int		ft_putaddress(unsigned long long nbr, char *base);

#endif