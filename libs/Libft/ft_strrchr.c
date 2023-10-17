/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:29:50 by almarcos          #+#    #+#             */
/*   Updated: 2023/08/09 15:43:53 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*end;

	len = ft_strlen(s);
	end = (char *)(s + len);
	while (end != s && *end != (unsigned char)c)
		end--;
	if (*end == (unsigned char)c)
		return (end);
	return (NULL);
}
