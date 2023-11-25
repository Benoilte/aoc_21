/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:42:40 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/25 10:23:38 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "../printf/ft_printf.h"

/*
Create a new t_list struct with malloc. assign var member content with
params 'content' and assign var member next to NULL
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ((void *)0);
	new->content = content;
	new->next = (void *)0;
	return (new);
}
