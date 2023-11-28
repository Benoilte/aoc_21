/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:56:37 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/29 00:04:02 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

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

void	from_msb_to_lsb(int *bit, size_t size)
{
	int	i;

	i = size;
	while (--i >= 0)
		bit[i] = bit[i] ^ 1;
}

void	*copy(void *content)
{
	char	*copy;

	copy = ft_strdup((char *)content);
	return (copy);
}
