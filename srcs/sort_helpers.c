/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:26:54 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/06 21:26:56 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_lstswap(t_elem *left, t_elem *right)
{
	if (left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}
