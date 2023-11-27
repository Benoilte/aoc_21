/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:03:57 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/27 11:36:51 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	first_part(void);
static int	second_part(void);
static int	count_direction(t_list *input);
static int	count_direction_with_aim(t_list *input);

void	day_02(void)
{
	first_part();
	second_part();
}

int	first_part(void)
{
	char	*file;
	int		fd;
	t_list	*input;

	file = "input/day-02.txt";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (file_not_exist());
	input = from_txt_to_struct_of_str(fd);
	close(fd);
	ft_printf("direction : %d\n", count_direction(input));
	ft_lstclear(&input, &del);
	return (0);
}

int	second_part(void)
{
	char	*file;
	int		fd;
	t_list	*input;

	file = "input/day-02.txt";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (file_not_exist());
	input = from_txt_to_struct_of_str(fd);
	close(fd);
	ft_printf("direction : %d\n", count_direction_with_aim(input));
	ft_lstclear(&input, &del);
	return (0);
}

static int	count_direction(t_list *input)
{
	t_list	*tmp;
	char	**data;
	int		horizontal;
	int		depth;

	tmp = input;
	depth = 0;
	horizontal = 0;
	while (tmp)
	{
		data = ft_split(tmp->content, ' ');
		if (ft_strncmp(data[0], "up", 2) == 0)
			depth -= ft_atoi(data[1]);
		else if (ft_strncmp(data[0], "down", 4) == 0)
			depth += ft_atoi(data[1]);
		else if (ft_strncmp(data[0], "forward", 7) == 0)
			horizontal += ft_atoi(data[1]);
		tmp = tmp->next;
		free_array(data, 2);
	}
	return (depth * horizontal);
}

/*
direction[0] == depth / direction[1] == horizontal
*/
static int	count_direction_with_aim(t_list *input)
{
	t_list	*tmp;
	char	**data;
	int		direction[2];
	int		aim;

	tmp = input;
	aim = 0;
	ft_bzero(direction, 2);
	while (tmp)
	{
		data = ft_split(tmp->content, ' ');
		if (ft_strncmp(data[0], "up", 2) == 0)
			aim -= ft_atoi(data[1]);
		else if (ft_strncmp(data[0], "down", 4) == 0)
			aim += ft_atoi(data[1]);
		else if (ft_strncmp(data[0], "forward", 7) == 0)
		{
			direction[1] += ft_atoi(data[1]);
			direction[0] += (aim * ft_atoi(data[1]));
		}
		tmp = tmp->next;
		free_array(data, 2);
	}
	return (direction[0] * direction[1]);
}
