/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:02:05 by yutsasak          #+#    #+#             */
/*   Updated: 2024/06/05 22:13:40 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long long nbr, char *base);
int		ft_putaddress(unsigned long long nbr, char *base);
void	handle_special_formats(va_list *ap, const char *fmt, int *len);
int		handle_unsigned(va_list *ap, const char *fmt, int *len);

#endif
