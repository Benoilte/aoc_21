/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:04:14 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/29 00:20:17 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	first_part(void);
static int	second_part(void);
static int	get_power_consumption(t_list *input);
static int	get_co2_scrubber_and_oxygen_gen(t_list *input);

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
	ft_printf("life support: %d\n", get_co2_scrubber_and_oxygen_gen(input));
	return (0);
}

static int	get_power_consumption(t_list *input)
{
	int		*bit;
	size_t	size;

	size = ft_strlen((char *)(input->content));
	bit = get_msb(input, size);
	return (compute_power_consumption(bit, size));
}

static int	get_co2_scrubber_and_oxygen_gen(t_list *input)
{
	int		oxygen_generator;
	int		co2_scrubber;
	size_t	size;
	t_list	*input_backup;

	input_backup = ft_lstmap(input, &copy, &del);
	size = ft_strlen((char *)(input->content));
	oxygen_generator = get_oxygen(input, size);
	co2_scrubber = get_co2(input_backup, size);
	return (oxygen_generator * co2_scrubber);
}
