/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:02:45 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/14 10:40:51 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem	*ls_lstnew(struct stat buf, char *name, char *path)
{
	t_elem			*new;
	struct stat		stat_data;
	struct dirent	sd_data;
	char			*cp_name;
	char			*cp_path;

	if (!(new = (t_elem *)malloc(sizeof(t_elem))))
		exit(2);
	cp_name = ft_strnew(ft_strlen(name));
	ft_strcpy(cp_name, name);
	stat_data = buf;
	new->buf = stat_data;
	new->name = cp_name;
	new->path = path;
	new->buf = stat_data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ls_lstadd(t_elem **head, struct stat buf, char *name, char *dir)
{
	t_elem	*node;
	t_elem	*temp;
	char	*path;

	path = ft_strnew(ft_strlen(name) + 2 + ft_strlen(dir));
	path = ft_strcpy(path, dir);
	path = ft_strcat(path, "/");
	path = ft_strcat(path, name);
	node = ls_lstnew(buf, name, path);
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
