/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:51:22 by almarcos          #+#    #+#             */
/*   Updated: 2023/10/17 08:46:40 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_parse(char formater, va_list args);
static int	ft_putnbr_base(long long n, char *base);
static int	ft_putptr(unsigned long n, char *base);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		index;
	int		bytes;

	if (!format)
		return (-1);
	va_start(args, format);
	bytes = 0;
	index = 0;
	while (format[index])
	{
		if (format[index] == '%' && format[index + 1] != '\0')
			bytes += ft_parse(format[++index], args);
		else
			bytes += ft_putchar_fd(format[index], 1);
		index++;
	}
	va_end(args);
	return (bytes);
}

static int	ft_parse(char formater, va_list args)
{
	int	bytes;

	bytes = 0;
	if (formater == 'c')
		bytes += ft_putchar_fd(va_arg(args, int), 1);
	else if (formater == 's')
		bytes += ft_putstr_fd(va_arg(args, char *), 1);
	else if (formater == 'x')
		bytes += ft_putnbr_base(va_arg(args, unsigned int), HEXA_LOW_BASE);
	else if (formater == 'X')
		bytes += ft_putnbr_base(va_arg(args, unsigned int), HEXA_UP_BASE);
	else if (formater == 'u')
		bytes += ft_putnbr_base(va_arg(args, unsigned int), DECIMAL_BASE);
	else if (formater == 'i' || formater == 'd')
		bytes += ft_putnbr_base(va_arg(args, int), DECIMAL_BASE);
	else if (formater == 'p')
		bytes += ft_putptr(va_arg(args, unsigned long), HEXA_LOW_BASE);
	else if (formater == '%')
		bytes += ft_putchar_fd('%', 1);
	return (bytes);
}

static int	ft_putnbr_base(long long n, char *base)
{
	int	bytes;
	int	base_size;

	bytes = 0;
	base_size = ft_strlen(base);
	if (n < 0)
	{
		bytes += ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= base_size)
		bytes += ft_putnbr_base((n / base_size), base);
	bytes += ft_putchar_fd(base[n % base_size], 1);
	return (bytes);
}

static int	ft_putptr(unsigned long n, char *base)
{
	int	base_size;
	int	bytes;

	if (n == 0)
		return (ft_putstr_fd("(nil)", 1));
	bytes = 0;
	base_size = ft_strlen(base);
	if (n >= (unsigned long)base_size)
		bytes += ft_putptr((n / base_size), base);
	else
		bytes += ft_putstr_fd("0x", 1);
	bytes += ft_putchar_fd(base[n % base_size], 1);
	return (bytes);
}
