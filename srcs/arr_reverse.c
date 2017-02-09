/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:17:22 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/31 15:10:56 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_private.h"

void	arr_swap(t_arr *src, size_t i, size_t j)
{
	uint8_t	tmp;
	uint8_t	*a;
	uint8_t	*b;
	size_t	cpyidx;

	if (src == 0)
		return ;
	if (src->cap == 0 || i > src->len || j > src->len || i == j)
		return ;
	a = ARR_IDX(src, i);
	b = ARR_IDX(src, j);
	cpyidx = 0;
	while (cpyidx < src->elm.sze)
	{
		tmp = a[cpyidx];
		a[cpyidx] = b[cpyidx];
		b[cpyidx] = tmp;
		cpyidx++;
	}
}

void	arr_reverse(t_arr *src)
{
	size_t	i;
	size_t	j;

	if (src == 0)
		return ;
	if (src->cap == 0)
		return ;
	i = 0;
	j = src->len - 1;
	while (j > i)
	{
		arr_swap(src, i, j);
		++i;
		--j;
	}
}
