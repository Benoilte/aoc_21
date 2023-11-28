/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-03-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:05:16 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/28 08:15:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

int	*get_most_common_bit(t_list *input, size_t size)
{
	size_t	i;
	int		*bit;
	t_list	*tmp;

	i = 0;
	tmp = input;
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
			else
				bit[i]++;
			i++;
		}
		tmp = tmp->next;
	}
	filter_most_common_bit(bit, size);
	return (bit);
}

void	filter_most_common_bit(int *bit, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (bit[i] > 0)
			bit[i] = 1;
		else
			bit[i] = 0;
		i++;
	}
}

int	power_of_two(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result *= 2;
		n--;
	}
	return (result);
}
