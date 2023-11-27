/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:47:31 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/27 09:36:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	first_part(void);
static int	second_part(void);
static int	count_drop(t_list *input);
static int	count_drop_with_filter(int *input, int size);

void	day_01(void)
{
	first_part();
	second_part();
}

int	first_part(void)
{
	char	*file;
	int		fd;
	t_list	*input;

	file = "input/day-01.txt";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (file_not_exist());
	input = from_txt_to_struct_of_int(fd);
	close(fd);
	ft_printf("depth increased: %d\n", count_drop(input));
	ft_lstclear(&input, &del);
	return (0);
}

int	second_part(void)
{
	int		fd;
	char	*file;
	int		size;
	int		*input;

	file = "input/day-01.txt";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (file_not_exist());
	size = count_line(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	input = from_txt_to_array_of_int(fd, size);
	close(fd);
	ft_printf("deepth increased: %d\n", count_drop_with_filter(input, size));
	free(input);
	return (0);
}

int	count_drop(t_list *input)
{
	int		prev_deepth;
	int		drop;
	t_list	*tmp;

	drop = 0;
	tmp = input;
	prev_deepth = 0;
	while (tmp)
	{
		if (prev_deepth)
		{
			if (*((int *)(tmp->content)) > prev_deepth)
				drop++;
		}
		prev_deepth = *((int *)(tmp->content));
		tmp = tmp->next;
	}
	return (drop);
}

int	count_drop_with_filter(int *input, int size)
{
	int	i;
	int	prev_deepth;
	int	drop;

	i = 0;
	prev_deepth = 0;
	drop = 0;
	while (i + 2 < size)
	{
		if (prev_deepth)
		{
			if ((input[i] + input[i + 1] + input[i + 2]) > prev_deepth)
				drop++;
		}
		prev_deepth = (input[i] + input[i + 1] + input[i + 2]);
		i++;
	}
	return (drop);
}
