/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:27:38 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/13 17:54:26 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print_time(t_elem *node)
{
	char		*str;
	time_t		mod_time;
	time_t		now;
	struct tm	*timeinfo;

	mod_time = node->buf.st_mtime;
	time(&now);
	timeinfo = localtime(&mod_time);
	str = ctime(&node->buf.st_mtime);
	if ((now - mod_time) > SIX_MONTH)
	{
		str = ft_strsub(str, 4, 7);
		ft_printf("%s", str);
		ft_printf("%5d ", timeinfo->tm_year + 1900);
	}
	else
	{
		str = ft_strsub(str, 4, 12);
		ft_printf("%s ", str);
	}
	free(str);
}

void	ls_print_size(t_elem *head, t_elem *node)
{
	unsigned int	maj;
	unsigned int	min;
	int				dev_pad;
	int				sze_pad;
	int				pad;

	dev_pad = ls_clc_major(head) + ls_clc_minor(head) + 2;
	sze_pad = ls_clc_sze(head);
	pad = (dev_pad > sze_pad) ? dev_pad : sze_pad;
	if (S_ISCHR(node->buf.st_mode))
	{
		maj = major(node->buf.st_rdev);
		min = minor(node->buf.st_rdev);
		ft_printf("%*lu, %*lu ", ls_clc_major(head), maj,
				ls_clc_minor(head), min);
	}
	else
		ft_printf("%*lld ", pad, node->buf.st_size);
}
