/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:31:05 by almarcos          #+#    #+#             */
/*   Updated: 2023/08/10 10:29:39 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	new_str_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return ((char *)ft_calloc(1, sizeof(char)));
	new_str_len = ft_strlen(s + start);
	if (len < new_str_len)
	{
		new_str = ft_calloc(len + 1, sizeof(char));
		if (!new_str)
			return (NULL);
		ft_strlcpy(new_str, s + start, len + 1);
		return (new_str);
	}
	return (ft_strdup(s + start));
}
