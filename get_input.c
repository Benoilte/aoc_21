/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:35:55 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/25 10:44:10 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	*get_int_ptr(int value);

t_list	*from_txt_to_struct(char *file)
{
	int		fd;
	int		is_line;
	char	*line;
	char	*str;
	int		value;
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
			value = ft_atoi(str);
			free(str);
			free(line);
			ft_lstadd_back(&input, ft_lstnew(get_int_ptr(value)));
		}
		else
			is_line = 0;
	}
	free(line);
	close(fd);
	return (input);
}

int	*get_int_ptr(int value)
{
	int	*ptr;

	ptr = ft_calloc(1, sizeof(int *));
	*ptr = value;
	return (ptr);
}
