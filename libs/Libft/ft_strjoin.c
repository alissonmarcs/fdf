/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:01:42 by almarcos          #+#    #+#             */
/*   Updated: 2023/08/02 13:08:46 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	new_str_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str_len = s1_len + s2_len + 1;
	new_str = (char *)ft_calloc(new_str_len, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, new_str_len);
	ft_strlcat(new_str, s2, new_str_len);
	return (new_str);
}
