/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:27:04 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/06 21:27:05 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_lstswap_dir(t_dirlst *left, t_dirlst *right)
{
	if (left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}

void	ls_sort_dir(t_dirlst **hd, t_flags f, int (*order)(char *, char *))
{
	int			swap;
	t_dirlst	*temp;

	swap = 1;
	temp = *hd;
	while (swap)
	{
		swap = 0;
		while (temp->next != NULL)
		{
			if (order(temp->path, temp->next->path) > 0)
			{
				ls_lstswap_dir(temp, temp->next);
				swap = 1;
				if (temp == *hd)
					*hd = temp->prev;
			}
			else
				temp = temp->next;
		}
		temp = *hd;
	}
}
