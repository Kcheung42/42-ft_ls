/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:26:59 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/14 14:33:36 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_time(t_elem *temp, t_elem **hd, int *swap)
{
	ls_lstswap(temp, temp->next);
	*swap = 1;
	if (temp == *hd)
		*hd = temp->prev;
}

void	ls_sort_time(t_elem **hd, t_flags f, int (*sort_order)(time_t, time_t))
{
	int		swap;
	t_elem	*temp;

	swap = 1;
	temp = *hd;
	while (swap)
	{
		swap = 0;
		while (temp->next != NULL)
		{
			if ((temp->buf.st_mtime == temp->next->buf.st_mtime) &&
					(sort_order(temp->buf.st_mtimespec.tv_nsec,
								temp->next->buf.st_mtimespec.tv_nsec) > 0))
				swap_time(temp, hd, &swap);
			else if (sort_order(temp->buf.st_mtime, temp->next->buf.st_mtime)
					> 0)
				swap_time(temp, hd, &swap);
			else
				temp = temp->next;
		}
		temp = *hd;
	}
}

void	ls_sort_name(t_elem **hd, t_flags f, int (*sort_order)(char *, char *))
{
	int		swap;
	t_elem	*temp;

	swap = 1;
	temp = *hd;
	while (swap)
	{
		swap = 0;
		while (temp->next != NULL)
		{
			if (sort_order(temp->name, temp->next->name) > 0)
			{
				ls_lstswap(temp, temp->next);
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

void	ls_sort_size(t_elem **hd, t_flags f, int (*s)(long int, long int),
		int (*n)(char *, char *))
{
	int		swap;
	t_elem	*temp;

	swap = 1;
	temp = *hd;
	while (swap)
	{
		swap = 0;
		while (temp->next != NULL)
		{
			if ((temp->buf.st_size == temp->next->buf.st_size) &&
					(n(temp->name, temp->next->name) > 0))
				swap_time(temp, hd, &swap);
			else if (s(temp->buf.st_size, temp->next->buf.st_size) > 0)
				swap_time(temp, hd, &swap);
			else
				temp = temp->next;
		}
		temp = *hd;
	}
}
