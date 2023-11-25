/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:47:31 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/25 12:59:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static void	first_part(int day);
static void	second_part(int day);
static int	count_drop(t_list *input);
static int	count_drop_with_filter(int *input, int size);

void	day_01(void)
{
	first_part(1);
	second_part(1);
}

void	first_part(int day)
{
	char	*file;
	t_list	*input;

	(void)day;
	file = "input/day-01.txt";
	input = from_txt_to_struct_of_int(file);
	ft_printf("depth increased: %d\n", count_drop(input));
	ft_lstclear(&input, &del);
}

void	second_part(int day)
{
	int		fd;
	char	*file;
	int		size;
	int		*input;

	(void)day;
	file = "input/day-01.txt";
	fd = open(file, O_RDONLY);
	size = count_line(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	input = from_txt_to_array_of_int(fd, size);
	close(fd);
	ft_printf("deepth increased: %d\n", count_drop_with_filter(input, size));
	free(input);
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
