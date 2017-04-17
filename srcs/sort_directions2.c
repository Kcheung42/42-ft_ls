/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:03:25 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/07 15:04:21 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		norm_size(long int left, long int right)
{
	if (left < right)
		return (1);
	else
		return (-1);
}

int		rev_size(long int left, long int right)
{
	if (left > right)
		return (1);
	else
		return (-1);
}
