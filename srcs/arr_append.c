/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:08:42 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:40:32 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_private.h"

int8_t	arr_append(t_arr *dst, const void *src)
{
	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	GRD(arr_reserve(dst, 1) == -1, -1);
	if (dst->elm.dup != 0)
		GRD(dst->elm.dup(ARR_IDX(dst, dst->len), src) == -1, -1);
	else
		arr_memcpy(ARR_IDX(dst, dst->len), src, dst->elm.sze);
	++dst->len;
	return (0);
}

int8_t	arr_appendm(t_arr *dst, const void *src, size_t src_len)
{
	size_t	i;
	uint8_t	*tmp;

	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	GRD(src_len == 0, 0);
	GRD(arr_reserve(dst, src_len) == -1, -1);
	if (dst->elm.dup != 0)
	{
		tmp = (uint8_t *)src;
		i = 0;
		while (i < src_len)
		{
			GRD(dst->elm.dup(ARR_IDX(dst, dst->len + i)
				, &tmp[i * dst->elm.sze]) == -1, -1);
			++i;
		}
	}
	else
		arr_memcpy(ARR_IDX(dst, dst->len), src, src_len * dst->elm.sze);
	dst->len += src_len;
	return (0);
}

int8_t	arr_appendarr(t_arr *dst, t_arr *src)
{
	size_t	i;

	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	GRD(src->len == 0, 0);
	GRD(arr_reserve(dst, src->len) == -1, -1);
	if (dst->elm.dup != 0)
	{
		i = 0;
		while (i < src->len)
		{
			GRD(dst->elm.dup(ARR_IDX(dst, dst->len + i), ARR_IDX(src, i)) == -1
				, -1);
			++i;
		}
	}
	else
		arr_memcpy(ARR_IDX(dst, dst->len), ARR_IDX(src, 0)
					, src->len * dst->elm.sze);
	dst->len += src->len;
	return (0);
}
