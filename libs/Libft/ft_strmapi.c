/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:37:50 by almarcos          #+#    #+#             */
/*   Updated: 2023/08/05 14:27:52 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	s_len;
	size_t	index;

	index = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	new_str = ft_calloc(s_len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	while (index < s_len)
	{
		new_str[index] = f(index, s[index]);
		index++;
	}
	new_str[s_len] = '\0';
	return (new_str);
}
