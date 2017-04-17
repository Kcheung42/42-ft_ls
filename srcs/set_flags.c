/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 23:12:21 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/12 11:34:52 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_set_l(t_flgs *flags)
{
	flags->p.mode = 1;
	flags->p.link = 1;
	flags->p.uid = 1;
	flags->p.gid = 1;
	flags->p.size = 1;
	flags->p.mtime = 1;
	flags->p.name = 1;
	return (1);
}

int		ls_set_g(t_flgs *flags)
{
	ls_set_l(flags);
	flags->p.uid = 0;
	return (1);
}

int		ls_set_i(t_flgs *flags)
{
	flags->p.inode = 1;
	flags->p.name = 1;
	return (1);
}

int		ls_set_d(t_flgs *flags)
{
	flags->f.a = 1;
	return (1);
}
