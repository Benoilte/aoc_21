/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:35:55 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/25 13:04:35 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	*get_int_ptr(int value);

/*
parse txt file and return a linked list of struct with a int as member.
text file should have 1 number on each line
*/
t_list	*from_txt_to_struct_of_int(char *file)
{
	int		fd;
	int		is_line;
	char	*line;
	char	*str;
	t_list	*input;

	input = NULL;
	is_line = 1;
	fd = open(file, O_RDONLY);
	while (is_line)
	{
		line = get_next_line(fd);
		if (line)
		{
			str = ft_substr(line, 0, ft_strlen(line) - 1);
			ft_lstadd_back(&input, ft_lstnew(get_int_ptr(ft_atoi(str))));
			free(line);
			free(str);
		}
		else
			is_line = 0;
	}
	free(line);
	close(fd);
	return (input);
}

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
return a pointer of int and assign its value withh the parameter
*/
int	*get_int_ptr(int value)
{
	int	*ptr;

	ptr = ft_calloc(1, sizeof(int *));
	*ptr = value;
	return (ptr);
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
