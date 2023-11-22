/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:59:30 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/22 10:05:52 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_file(int fd, char *buffer);
static char	*ft_make_line(char *content);
static char	*ft_update_buffer(char *buffer);
static char	*ft_join_and_free(char const *s1, char const *s2);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*after_new_line_content;

	if (fd < 0)
	{
		free(after_new_line_content);
		after_new_line_content = NULL;
		return (NULL);
	}
	after_new_line_content = ft_read_file(fd, after_new_line_content);
	if (after_new_line_content == NULL)
		return (NULL);
	line = ft_make_line(after_new_line_content);
	after_new_line_content = ft_update_buffer(after_new_line_content);
	return (line);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*file_content;
	ssize_t	num_bytes;

	if (ft_strchr(buffer, '\n'))
		return (buffer);
	file_content = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!file_content)
		return (NULL);
	num_bytes = 1;
	while (!ft_strchr(buffer, '\n') && num_bytes)
	{
		num_bytes = read(fd, file_content, BUFFER_SIZE);
		if (num_bytes < 0)
		{
			free(file_content);
			free(buffer);
			return (NULL);
		}
		file_content[num_bytes] = '\0';
		buffer = ft_join_and_free(buffer, file_content);
	}
	free(file_content);
	return (buffer);
}

static char	*ft_make_line(char *content)
{
	char	*line;
	size_t	line_size;
	char	*new_line_position;

	if (content[0] == '\0')
		return (NULL);
	new_line_position = ft_strchr(content, '\n');
	if (new_line_position == NULL)
		return (ft_strdup(content));
	else
		line_size = (new_line_position - content) + 2;
	line = malloc((line_size) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, content, line_size);
	return (line);
}

static char	*ft_update_buffer(char *buffer)
{
	char	*new_buffer;
	char	*new_line_position;

	new_line_position = ft_strchr(buffer, '\n');
	if (new_line_position == NULL)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(new_line_position + 1);
	free(buffer);
	return (new_buffer);
}

static char	*ft_join_and_free(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	new_str_len;

	if (s1 == NULL)
		s1 = ft_strdup("");
	new_str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(new_str_len * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, new_str_len);
	ft_strlcat(new_str, s2, new_str_len);
	free((char *)s1);
	return (new_str);
}
