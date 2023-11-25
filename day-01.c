/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:47:31 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/25 11:02:00 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static void	first_part(int day);
static void	second_part(int day);
static int	count_increasement(t_list *input);

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
	input = from_txt_to_struct(file);
	ft_printf("depth increased: %d\n", count_increasement(input));
	ft_lstclear(&input, &del);
}

void	second_part(int day)
{
	ft_printf("second part result day %.2d\n", day);
}

int	count_increasement(t_list *input)
{
	int		index;
	int		prev_depth_measurement;
	int		deepth;
	t_list	*tmp;

	index = 0;
	deepth = 0;
	tmp = input;
	prev_depth_measurement = 0;
	while (tmp)
	{
		if (index)
		{
			if (*((int *)(tmp->content)) > prev_depth_measurement)
				deepth++;
		}
		index++;
		prev_depth_measurement = *((int *)(tmp->content));
		tmp = tmp->next;
	}
	return (deepth);
}

// int	(t_list *input)
// {
// 	int		index;
// 	int		prev_depth_measurement;
// 	int		deepth;
// 	t_list	*tmp;

// 	index = 0;
// 	deepth = 0;
// 	tmp = input;
// 	prev_depth_measurement = 0;
// 	while (tmp)
// 	{
// 		if (index)
// 		{
// 			if (tmp->content > prev_depth_measurement)
// 				deepth++;
// 		}
// 		index++;
// 		prev_depth_measurement = tmp->content;
// 		tmp = tmp->next;
// 	}
// 	return (deepth);
// }
