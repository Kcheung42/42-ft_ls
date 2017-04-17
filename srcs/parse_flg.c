/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:26:39 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/14 10:40:24 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_inval_option(char c)
{
	char	*str;

	str = "lRartnfgdiS";
	while (*str)
	{
		if (c == *str)
			return (0);
		str++;
	}
	ft_printf("ls: illegal option -- %c\n", c);
	exit(2);
	return (0);
}

void	ls_setflags(char c, t_flgs *fl)
{
	fl->f.l = (c == 'l') ? ls_set_l(fl) : fl->f.l;
	fl->f.rr = (c == 'R') ? 1 : fl->f.rr;
	fl->f.a = (c == 'a') ? 1 : fl->f.a;
	fl->f.r = (c == 'r') ? 1 : fl->f.r;
	fl->f.t = (c == 't') ? 1 : fl->f.t;
	fl->f.n = (c == 'n') ? 1 : fl->f.n;
	fl->f.f = (c == 'f') ? 1 : fl->f.f;
	fl->f.g = (c == 'g') ? ls_set_g(fl) : fl->f.g;
	fl->f.d = (c == 'd') ? ls_set_d(fl) : fl->f.d;
	fl->f.i = (c == 'i') ? ls_set_i(fl) : fl->f.i;
	fl->f.ss = (c == 'S') ? 1 : fl->f.ss;
	ls_inval_option(c);
}

void	ls_parseflags(int argc, char *argv[], t_flgs *flags)
{
	int	i;
	int	j;

	i = 1;
	ft_bzero(flags, sizeof(flags));
	flags->p.name = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			j += (argv[i][j + 1] == '-') ? 1 : 1;
			while (argv[i][j])
			{
				ls_setflags(argv[i][j], flags);
				j++;
			}
			i++;
		}
		else
			return ;
	}
}
