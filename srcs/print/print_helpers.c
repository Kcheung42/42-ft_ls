/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:27:43 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/13 17:55:23 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

blkcnt_t	calc_blocks(t_elem *head)
{
	t_elem		*temp;
	blkcnt_t	blocks;

	temp = head;
	blocks = 0;
	while (temp)
	{
		blocks += temp->buf.st_blocks;
		temp = temp->next;
	}
	return (blocks);
}

int			ls_digits(int d)
{
	int	count;

	count = 0;
	while (d)
	{
		count++;
		d /= 10;
	}
	return (count);
}

int			ls_clc_lnk(t_elem *head)
{
	t_elem	*temp;
	int		max;
	int		cur;

	temp = head;
	max = ls_digits(temp->buf.st_nlink);
	cur = 0;
	while (temp)
	{
		if ((cur = ls_digits(temp->buf.st_nlink)) > max)
			max = cur;
		temp = temp->next;
	}
	return (max);
}

int			ls_clc_sze(t_elem *head)
{
	t_elem	*temp;
	int		max;
	int		cur;

	temp = head;
	max = ls_digits(temp->buf.st_size);
	cur = 0;
	while (temp)
	{
		if (!S_ISCHR(temp->buf.st_mode) &&
				(cur = ls_digits(temp->buf.st_size)) > max)
			max = cur;
		temp = temp->next;
	}
	return (max);
}
