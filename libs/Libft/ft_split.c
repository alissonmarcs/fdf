/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:22:35 by almarcos          #+#    #+#             */
/*   Updated: 2023/08/06 13:55:15 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, int c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s != c && *s)
				s++;
		}
		if (*s == '\0')
			return (words);
		s++;
	}
	return (words);
}

static char	**ft_alloc_words(char **array, const char *s, int c)
{
	size_t	current_word_len;
	size_t	index;

	index = 0;
	while (*s)
	{
		current_word_len = 0;
		while (s[current_word_len] != c && s[current_word_len])
			current_word_len++;
		array[index] = (char *)ft_calloc((current_word_len + 1), sizeof(char));
		ft_strlcpy(array[index], s, current_word_len + 1);
		index++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	array = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!array)
		return (NULL);
	while (*s == (unsigned char)c && *s)
		s++;
	ft_alloc_words(array, s, c);
	return (array);
}
