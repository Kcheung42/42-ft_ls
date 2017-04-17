/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:12:53 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/13 17:42:16 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_handle_files(t_env *env, t_flgs fl)
{
	t_dirlst		*temp;
	struct stat		buf;
	t_elem			*head;

	head = NULL;
	if (env->files)
	{
		temp = env->files;
		while (temp)
		{
			lstat(temp->path, &buf);
			ls_lstadd(&head, buf, temp->path, temp->path);
			temp = temp->next;
		}
		if (!fl.f.f)
			ls_sort(&head, fl.f);
		ls_lstprint(head, fl.p, fl.f);
	}
}

void	ls_handle_dirs(t_env *env, t_flgs fl)
{
	t_dirlst		*temp;

	if (env->dirs)
	{
		if (env->files)
			ft_printf("\n");
		temp = env->dirs;
		while (temp)
		{
			ft_ls(env, fl, temp->path);
			if (temp->next != NULL)
				ft_printf("\n");
			temp = temp->next;
		}
	}
}

void	ls_handle_nof(t_env *env, t_flgs fl)
{
	t_dirlst		*temp;

	if (env->nondirs)
	{
		temp = env->nondirs;
		while (temp)
		{
			ft_ls(env, fl, temp->path);
			temp = temp->next;
		}
	}
}
