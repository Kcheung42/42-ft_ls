/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:27:34 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/13 17:53:21 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_filetype(struct stat filestat)
{
	if (S_ISDIR(filestat.st_mode))
		ft_printf("d");
	else if (S_ISLNK(filestat.st_mode))
		ft_printf("l");
	else if (S_ISCHR(filestat.st_mode))
		ft_printf("c");
	else if (S_ISBLK(filestat.st_mode))
		ft_printf("b");
	else if (S_ISFIFO(filestat.st_mode))
		ft_printf("p");
	else if (S_ISSOCK(filestat.st_mode))
		ft_printf("s");
	else
		ft_printf("-");
}

void	ls_print_mode(t_elem *node)
{
	struct stat	filestat;

	filestat = node->buf;
	print_filetype(filestat);
	ft_printf((filestat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf(" ");
}

void	ls_print_uid(t_elem *head, t_elem *node, t_flags f)
{
	struct passwd	*uid;

	uid = getpwuid(node->buf.st_uid);
	if (f.n)
		ft_printf("%d ", node->buf.st_uid);
	else
		ft_printf("%-*s ", ls_clc_uid(head), uid->pw_name);
}

void	ls_print_gid(t_elem *head, t_elem *node, t_flags f)
{
	struct group	*gid;

	gid = getgrgid(node->buf.st_gid);
	if (f.n)
		ft_printf("%d ", node->buf.st_gid);
	else
		ft_printf("%-*s ", ls_clc_gid(head), gid->gr_name);
}

void	ls_print_name(t_elem *node, t_flags f)
{
	char	linkname[100];

	ft_printf("%-s ", node->name);
	if (S_ISLNK(node->buf.st_mode) && f.l)
	{
		readlink(node->path, linkname, 100);
		ft_printf("-> %s", linkname);
	}
}
