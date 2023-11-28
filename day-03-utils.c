/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-03-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:05:16 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/29 00:14:41 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

int	compute_power_consumption(int *bit, size_t size)
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
	free(bit);
	return (gamma_rate * (gamma_rate ^ (power_of_two(size) - 1)));
}

int	get_oxygen(t_list *input, size_t size)
{
	int		msb;
	int		i;
	int		oxygen;
	t_list	**root;

	root = &input;
	i = 0;
	while (ft_lstsize(*root) > 1)
	{
		msb = get_msb_or_lsb(*root, i, 1);
		filter_bit_criteria(root, msb, i);
		i++;
	}
	oxygen = bit_str_to_int((*root)->content, size);
	ft_lstclear(root, &del);
	return (oxygen);
}

int	get_co2(t_list *input, size_t size)
{
	int		lsb;
	int		i;
	int		co2;
	t_list	**root;

	root = &input;
	i = 0;
	while (ft_lstsize(*root) > 1)
	{
		lsb = get_msb_or_lsb(*root, i, 0);
		filter_bit_criteria(root, lsb, i);
		i++;
	}
	co2 = bit_str_to_int((*root)->content, size);
	ft_lstclear(root, &del);
	return (co2);
}

int	bit_str_to_int(char *number, size_t size)
{
	int	i;
	int	rating;

	i = size;
	rating = 0;
	while (--i >= 0)
	{
		if (number[i] == '1')
			rating += power_of_two((size - 1) - i);
	}
	return (rating);
}

int	get_msb_or_lsb(t_list *input, int index, int msb)
{
	int		zero;
	int		one;
	t_list	*tmp;

	zero = 0;
	one = 0;
	tmp = input;
	while (tmp)
	{
		if (((char *)(tmp->content))[index] == '0')
			zero++;
		else
			one++;
		tmp = tmp->next;
	}
	if (msb)
	{
		if (one >= zero)
			return (1);
		return (0);
	}
	if (zero <= one)
		return (0);
	return (1);
}

void	filter_bit_criteria(t_list **root, int msb, int i)
{
	t_list	*prev;
	t_list	*to_del;
	t_list	*lst;

	lst = *root;
	while (lst)
	{
		if (((char *)(lst->content))[i] != (msb + 48))
		{
			to_del = lst;
			if (lst == *root)
				*root = lst->next;
			else
				prev->next = lst->next;
			lst = lst->next;
			ft_lstdelone(to_del, &del);
		}
		else
		{
			prev = lst;
			lst = lst->next;
		}
	}
}

int	*get_msb(t_list *input, size_t size)
{
	int		i;
	int		*bit;
	t_list	*tmp;

	i = 0;
	tmp = input;
	bit = ft_calloc(size, sizeof(int));
	if (!bit)
		return (0);
	while ((size_t)i < size)
		bit[i++] = 0;
	while (tmp)
	{
		i = size;
		while (--i >= 0)
		{
			if (((char *)(tmp->content))[i] == '0')
				bit[i]--;
			else
				bit[i]++;
		}
		tmp = tmp->next;
	}
	filter_msb(bit, size);
	return (bit);
}

void	filter_msb(int *bit, size_t size)
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
