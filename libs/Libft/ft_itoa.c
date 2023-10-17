/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:13:39 by almarcos          #+#    #+#             */
/*   Updated: 2023/08/10 10:24:43 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_negative(long n)
{
	return (n < 0);
}

static size_t	ft_count_digits(long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		digits++;
	while (n)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*new_str;
	long	temp;
	int		is_negative;
	size_t	size_to_alloc;

	temp = n;
	is_negative = ft_is_negative(temp);
	size_to_alloc = ft_count_digits(temp) + is_negative;
	new_str = ft_calloc(size_to_alloc + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	if (temp == 0)
		new_str[0] = '0';
	if (is_negative)
	{
		new_str[0] = '-';
		temp = -temp;
	}
	while (temp)
	{
		new_str[--size_to_alloc] = (temp % 10) + '0';
		temp /= 10;
	}
	return (new_str);
}
