/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:26:25 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/13 17:40:09 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_env *env, t_flgs fl, char *currentdir)
{
	DIR				*dir;
	struct dirent	*sd;
	struct stat		buf;
	t_elem			*head;

	head = NULL;
	if (!(dir = opendir(currentdir)))
	{
		ft_printf("ls: %s: No such file or directory\n", currentdir);
		return ;
	}
	while ((sd = readdir(dir)) != NULL)
	{
		lstat(ls_next_dir(currentdir, sd->d_name), &buf);
		ls_lstadd(&head, buf, sd->d_name, currentdir);
	}
	if (!fl.f.f)
		ls_sort(&head, fl.f);
	if ((env->count > 1 || fl.f.rr) && !fl.f.d)
		ft_printf("%s:\n", currentdir);
	ls_printblocks(head, fl.f);
	ls_lstprint(head, fl.p, fl.f);
	if (fl.f.rr && !fl.f.d)
		ls_recursion(head, currentdir, fl, env);
	closedir(dir);
}

void	execute_ls(t_env *env, t_flgs fl)
{
	if (env->dirs || env->nondirs || env->files)
	{
		ls_handle_nof(env, fl);
		ls_handle_files(env, fl);
		ls_handle_dirs(env, fl);
	}
}

int		main(int argc, char *argv[])
{
	t_flags			f;
	t_pflags		p;
	t_flgs			flags;
	t_env			*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->count = 0;
	env->dirs = NULL;
	env->nondirs = NULL;
	env->files = NULL;
	ls_parseflags(argc, argv, &flags);
	ls_parse_dir(argc, argv, flags.f, env);
	execute_ls(env, flags);
	return (0);
}
