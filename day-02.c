/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:03:57 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/27 10:16:41 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	first_part(void);
static int	second_part(void);
static int	count_direction(t_list *input);

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
	return (0);
}

int	second_part(void)
{
	ft_printf("second part result\n");
	return (0);
}

static int	count_direction(t_list *input)
{
	t_list	*tmp;
	char	**data;
	int		forward;
	int		deepth;

	tmp = input;
	deepth = 0;
	forward = 0;
	while (tmp)
	{
		data = ft_split(tmp->content, ' ');
		// ft_printf("data 0: %s, data 1: %s\n", data[0], data[1]);
		if (ft_strncmp(data[0], "up", 2) == 0)
			deepth -= ft_atoi(data[1]);
		else if (ft_strncmp(data[0], "down", 4) == 0)
			deepth += ft_atoi(data[1]);
		else if (ft_strncmp(data[0], "forward", 7) == 0)
			forward += ft_atoi(data[1]);
		tmp = tmp->next;
	}
	// ft_printf("forward: %d\n", forward);
	// ft_printf("deepth: %d\n", deepth);
	return (forward * deepth);
}
