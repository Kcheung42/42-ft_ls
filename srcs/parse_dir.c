/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:26:32 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/14 10:40:00 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_env(t_env *env, t_flags f)
{
	if (env->dirs)
	{
		(f.r) ? ls_sort_dir(&(env->dirs), f, rev_name) :
			ls_sort_dir(&(env->dirs), f, norm_name);
	}
	if (env->nondirs)
	{
		(f.r) ? ls_sort_dir(&(env->nondirs), f, rev_name) :
			ls_sort_dir(&(env->nondirs), f, norm_name);
	}
	if (env->files)
	{
		(f.r) ? ls_sort_dir(&(env->files), f, rev_name) :
			ls_sort_dir(&(env->files), f, norm_name);
	}
}

t_dirlst	*ls_newdir(const char *path)
{
	t_dirlst	*new;
	char		*str;

	str = (char *)malloc(sizeof(char) * ft_strlen(path) + 1);
	ft_bzero(str, ft_strlen(path) + 1);
	if (!(new = (t_dirlst*)malloc(sizeof(t_dirlst))))
		exit(2);
	ft_strcpy(str, path);
	new->path = str;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		ls_lstadd_dir(t_dirlst **head, char *path)
{
	t_dirlst	*node;
	t_dirlst	*temp;

	node = ls_newdir(path);
	if (*head == NULL)
		*head = node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		node->prev = temp;
		temp->next = node;
	}
}

void		fill_env(t_env *e, char *path, t_flags f)
{
	DIR			*dir;
	struct stat	buf;
	int			ret;

	ret = lstat(path, &buf);
	dir = opendir(path);
	if (dir)
	{
		if (f.d)
		{
			ls_lstadd_dir(&(e->files), path);
		}
		else
		{
			ls_lstadd_dir(&(e->dirs), path);
			e->count += 1;
		}
	}
	else if (!ret && S_ISREG(buf.st_mode))
		ls_lstadd_dir(&(e->files), path);
	else
		ls_lstadd_dir(&(e->nondirs), path);
}

void		ls_parse_dir(int argc, char *argv[], t_flags f, t_env *env)
{
	int	i;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
		i++;
	if (!argv[i])
		fill_env(env, ".", f);
	else
	{
		while (i < argc && argv[i])
		{
			fill_env(env, argv[i], f);
			i++;
		}
		if (!f.f)
			sort_env(env, f);
	}
}
