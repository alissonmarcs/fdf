/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:54:31 by alisson           #+#    #+#             */
/*   Updated: 2023/11/10 10:47:07 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_hex_to_int(char *str)
{
	int	result;
	int	byte;

	result = 0;
	while (*str != ' ' && *str)
	{
		byte = *str++;
		if (byte >= '0' && byte <= '9')
			byte -= '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		result = (result << 4) | (byte & 0xF);
	}
	return (result);
}
