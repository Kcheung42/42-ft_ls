/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:27:30 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/13 17:54:45 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_printblocks(t_elem *head, t_flags f)
{
	if (f.l && !f.d)
		ft_printf("total %lld\n", calc_blocks(head));
}

void	ls_print_inode(t_elem *head, t_elem *node, t_flags f)
{
	ino_t inode;

	ft_printf("%*llu ", ls_clc_inode(head), node->buf.st_ino);
}

void	ls_print_fields(t_elem *head, t_elem *node, t_pflags p, t_flags f)
{
	p.inode ? ls_print_inode(head, node, f) : ft_printf("");
	p.mode ? ls_print_mode(node) : ft_printf("");
	p.link ? ft_printf("%*hu ", ls_clc_lnk(head), node->buf.st_nlink) :
		ft_printf("");
	p.uid ? ls_print_uid(head, node, f) : ft_printf("");
	p.gid ? ls_print_gid(head, node, f) : ft_printf("");
	p.size ? ls_print_size(head, node) : ft_printf("");
	p.mtime ? ls_print_time(node) : ft_printf("");
	p.name ? ls_print_name(node, f) : ft_printf("");
	ft_printf("\n");
}

void	ls_lstprint(t_elem *head, t_pflags p, t_flags f)
{
	t_elem	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (!f.a && temp->name[0] == '.')
			temp = temp->next;
		else
		{
			ls_print_fields(head, temp, p, f);
			temp = temp->next;
		}
	}
}
