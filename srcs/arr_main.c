/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:14:18 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/31 15:11:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_private.h"
#include <stdlib.h>

int8_t	arr_init(t_arr *src, size_t cap, t_arr_elm elm)
{
	GRD(src == 0 || cap == 0 || elm.sze == 0, -1);
	arr_bzero(src, sizeof(t_arr));
	GRD((src->ptr = malloc(cap * elm.sze)) == 0, -1);
	src->elm = elm;
	src->cap = cap;
	return (0);
}

int8_t	arr_reserve(t_arr *src, size_t sze)
{
	uint8_t	*tmp;

	GRD(src == 0, -1);
	GRD(src->cap == 0, -1);
	if (src->len + sze > src->cap)
	{
		while (src->len + sze > src->cap)
			src->cap = ARR_GROW_FACTOR * src->cap;
		GRD((tmp = malloc(src->cap * src->elm.sze)) == 0, -1);
		arr_memcpy(tmp, src->ptr, src->len * src->elm.sze);
		free(src->ptr);
		src->ptr = tmp;
	}
	return (0);
}

int8_t	arr_resize(t_arr *src, size_t sze)
{
	size_t	i;

	GRD(src == 0, -1);
	GRD(src->cap == 0, -1);
	if (src->len > sze)
	{
		i = sze;
		if (src->elm.dtr != 0)
			while (i < src->len)
				src->elm.dtr(ARR_IDX(src, i++));
	}
	else if (src->len < sze)
	{
		GRD(arr_reserve(src, sze - src->len) == -1, -1);
		i = src->len;
		if (src->elm.zero != 0)
			while (i < sze)
				GRD1(src->elm.zero(ARR_IDX(src, i++)) == -1, src->len = i
					, -1);
		else
			arr_bzero(ARR_IDX(src, src->len), (sze - src->len) * src->elm.sze);
	}
	src->len = sze;
	return (0);
}

void	arr_dtr(t_arr *src)
{
	size_t	i;

	if (src == 0)
		return ;
	if (src->cap > 0)
	{
		if (src->elm.dtr != 0)
		{
			i = 0;
			while (i < src->len)
				src->elm.dtr(ARR_IDX(src, i++));
		}
		free(src->ptr);
	}
	arr_bzero(src, sizeof(t_arr));
}
