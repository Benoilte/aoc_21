/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:04:33 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/27 09:05:09 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

/*
parse txt file and return an arry of int.
text file should have 1 number on each line
*/
int	*from_txt_to_array_of_int(int fd, int size)
{
	int		is_line;
	char	*line;
	char	*str;
	int		*input;
	int		i;

	is_line = 1;
	input = ft_calloc(size, sizeof(int));
	i = 0;
	while (is_line)
	{
		line = get_next_line(fd);
		if (line)
		{
			str = ft_substr(line, 0, ft_strlen(line) - 1);
			input[i++] = ft_atoi(str);
			free(line);
			free(str);
		}
		else
			is_line = 0;
	}
	return (input);
}

/*
Go through a text file and count and return numbers line
*/
int	count_line(int fd)
{
	int		is_line;
	int		count;
	char	*line;

	is_line = 1;
	count = 0;
	while (is_line)
	{
		line = get_next_line(fd);
		if (line)
			count++;
		else
			is_line = 0;
		free(line);
	}
	return (count);
}
