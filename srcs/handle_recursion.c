/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_recursion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 21:05:48 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/07 21:05:49 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ls_next_dir(char *curdir, char *nextdir)
{
	char	*newdir;

	newdir = ft_strnew(ft_strlen(curdir) + 2 + ft_strlen(nextdir));
	newdir = ft_strcpy(newdir, curdir);
	newdir = ft_strcat(newdir, "/");
	newdir = ft_strcat(newdir, nextdir);
	return (newdir);
}

void	ls_recursion(t_elem *head, char *currentdir, t_flgs fl, t_env *env)
{
	t_elem			*temp;

	temp = head;
	while (temp)
	{
		if (S_ISDIR(temp->buf.st_mode) && strcmp(".", temp->name) &&
			strcmp("..", temp->name))
		{
			ft_printf("\n");
			ft_ls(env, fl, ls_next_dir(currentdir, temp->name));
		}
		free(temp);
		temp = temp->next;
	}
}
