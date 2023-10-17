/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:18:46 by almarcos          #+#    #+#             */
/*   Updated: 2023/10/09 16:18:46 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s) + 1;
	new_str = (char *) ft_calloc(len, sizeof (char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, len);
	return (new_str);
}
