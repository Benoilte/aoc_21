/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   days.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:48:16 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/27 09:35:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAYS_H
# define DAYS_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "printf/ft_printf.h"

void	day_01(void);
void	day_02(void);
void	day_03(void);
void	day_04(void);
void	day_05(void);
void	day_06(void);
void	day_07(void);
void	day_08(void);
void	day_09(void);
void	day_10(void);
void	day_11(void);
void	day_12(void);
void	day_13(void);
void	day_14(void);
void	day_15(void);
void	day_16(void);
void	day_17(void);
void	day_18(void);
void	day_19(void);
void	day_20(void);
void	day_21(void);
void	day_22(void);
void	day_23(void);
void	day_24(void);
void	day_25(void);

typedef struct s_input
{
	char			*str;
	int				*value;
	struct s_input	*next;
}		t_input;

t_list	*from_txt_to_struct_of_int(int fd);
t_list	*from_txt_to_struct_of_str(int fd);
int		*from_txt_to_array_of_int(int fd, int size);
int		count_line(int fd);

void	del(void *content);

int		file_not_exist(void);

#endif
