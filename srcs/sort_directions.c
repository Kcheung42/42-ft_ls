/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:26:50 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/14 14:33:57 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		norm_name(char *str1, char *str2)
{
	if (ft_strcmp(str1, str2) > 0)
		return (1);
	else
		return (-1);
}

int		rev_name(char *str1, char *str2)
{
	if (ft_strcmp(str1, str2) < 0)
		return (1);
	else
		return (-1);
}

int		norm_time(time_t left, time_t right)
{
	if (left < right)
		return (1);
	else
		return (-1);
}

int		rev_time(time_t left, time_t right)
{
	if (left > right)
		return (1);
	else
		return (-1);
}

void	ls_sort(t_elem **head, t_flags f)
{
	int	dir;

	if (f.ss)
		(f.r) ? ls_sort_size(head, f, rev_size, rev_name) :
			ls_sort_size(head, f, norm_size, norm_name);
	else if (f.t)
		(f.r) ? ls_sort_time(head, f, rev_time) :
			ls_sort_time(head, f, norm_time);
	else
		(f.r) ? ls_sort_name(head, f, rev_name) :
			ls_sort_name(head, f, norm_name);
}
