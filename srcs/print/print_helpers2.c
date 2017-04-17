/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 00:34:33 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/13 17:56:02 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_clc_inode(t_elem *head)
{
	t_elem	*temp;
	int		max;
	int		cur;

	temp = head;
	max = ls_digits(temp->buf.st_ino);
	cur = 0;
	while (temp)
	{
		if ((cur = ls_digits(temp->buf.st_ino)) > max)
			max = cur;
		temp = temp->next;
	}
	return (max);
}

int			ls_clc_uid(t_elem *head)
{
	t_elem			*temp;
	int				max;
	int				cur;
	struct passwd	*uid;

	temp = head;
	uid = getpwuid(temp->buf.st_uid);
	max = ft_strlen(uid->pw_name);
	cur = 0;
	while (temp)
	{
		uid = getpwuid(temp->buf.st_uid);
		if ((cur = ft_strlen(uid->pw_name)) > max)
			max = cur;
		temp = temp->next;
	}
	return (max);
}

int			ls_clc_gid(t_elem *head)
{
	t_elem			*temp;
	int				max;
	int				cur;
	struct group	*gid;

	temp = head;
	gid = getgrgid(temp->buf.st_gid);
	max = ft_strlen(gid->gr_name);
	cur = 0;
	while (temp)
	{
		gid = getgrgid(temp->buf.st_gid);
		if ((cur = ft_strlen(gid->gr_name)) > max)
			max = cur;
		temp = temp->next;
	}
	return (max);
}

int			ls_clc_minor(t_elem *head)
{
	t_elem	*temp;
	int		max;
	int		cur;

	temp = head;
	max = ls_digits(minor(temp->buf.st_rdev));
	cur = 0;
	while (temp)
	{
		if (S_ISCHR(temp->buf.st_mode) &&
				(cur = ls_digits(minor(temp->buf.st_rdev))) > max)
			max = cur;
		temp = temp->next;
	}
	return (max);
}

int			ls_clc_major(t_elem *head)
{
	t_elem	*temp;
	int		max;
	int		cur;

	temp = head;
	max = ls_digits(major(temp->buf.st_rdev));
	cur = 0;
	while (temp)
	{
		if (S_ISCHR(temp->buf.st_mode) &&
				(cur = ls_digits(major(temp->buf.st_rdev))) > max)
			max = cur;
		temp = temp->next;
	}
	return (max);
}
