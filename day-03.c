/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:04:14 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/28 00:07:47 by bebrandt         ###   ########.fr       */
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
	size_t	i;
	int		*bit;
	size_t	size;
	t_list	*tmp;

	i = 0;
	tmp = input;
	size = ft_strlen((char *)(tmp->content));
	bit = ft_calloc(size, sizeof(int));
	if (!bit)
		return (0);
	while (i < size)
		bit[i++] = 0;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (((char *)(tmp->content))[i] == '0')
				bit[i]--;
			else if (((char *)(tmp->content))[i] == '1')
				bit[i]++;
			i++;
		}
		tmp = tmp->next;
	}
	return (compute_most_and_least_common_bit(bit, size));
}

static int	compute_most_and_least_common_bit(int *bit, int size)
{
	int	i;
	int	gamma_rate;

	i = 0;
	while (i < size)
	{
		if (bit[i] > 0)
			bit[i] = 1;
		else
			bit[i] = 0;
		i++;
	}
	gamma_rate = 0;
	while (--i >= 0)
	{
		if (bit[i] == 1)
			gamma_rate += power_of_two((size - 1) - i);
	}
	return (gamma_rate * (gamma_rate ^ (power_of_two(size) - 1)));
}
