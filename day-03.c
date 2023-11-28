/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:04:14 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/28 08:15:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	first_part(void);
static int	second_part(void);
static int	get_power_consumption(t_list *input);
static int	compute_most_and_least_common_bit(int *bit, int size);

void	day_03(void)
{
	first_part();
	second_part();
}

int	first_part(void)
{
	char	*file;
	int		fd;
	t_list	*input;

	file = "input/day-03.txt";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (file_not_exist());
	input = from_txt_to_struct_of_str(fd);
	close(fd);
	ft_printf("power consumption : %d\n", get_power_consumption(input));
	ft_lstclear(&input, &del);
	return (0);
}

int	second_part(void)
{
	char	*file;
	int		fd;
	t_list	*input;

	file = "input/day-03.txt";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (file_not_exist());
	input = from_txt_to_struct_of_str(fd);
	close(fd);
	// ft_printf("power consumption : %d\n", get_power_consumption(input));
	ft_lstclear(&input, &del);
	return (0);
}

static int	get_power_consumption(t_list *input)
{
	int		*bit;
	size_t	size;

	size = ft_strlen((char *)(input->content));
	bit = get_most_common_bit(input, size);
	return (compute_most_and_least_common_bit(bit, size));
}

static int	compute_most_and_least_common_bit(int *bit, int size)
{
	int	i;
	int	gamma_rate;

	i = size;
	gamma_rate = 0;
	while (--i >= 0)
	{
		if (bit[i] == 1)
			gamma_rate += power_of_two((size - 1) - i);
	}
	return (gamma_rate * (gamma_rate ^ (power_of_two(size) - 1)));
}
