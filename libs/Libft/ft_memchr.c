/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:12:12 by almarcos          #+#    #+#             */
/*   Updated: 2023/08/09 10:05:46 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*byte;

	byte = (unsigned char *)s;
	while (byte < ((unsigned char *)s + n))
	{
		if (*byte == (unsigned char)c)
			return (byte);
		byte++;
	}
	return (0);
}
