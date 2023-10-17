/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:58:55 by almarcos          #+#    #+#             */
/*   Updated: 2023/08/06 14:02:26 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	temp;

	temp = n;
	if (temp < 0)
	{
		ft_putchar_fd('-', fd);
		temp = -temp;
	}
	if (temp >= 10)
		ft_putnbr_fd(temp / 10, fd);
	ft_putchar_fd((char)(temp % 10) + '0', fd);
}
