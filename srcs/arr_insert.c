/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:08:42 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:46:03 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_private.h"

int8_t	arr_insert(t_arr *dst, size_t idx, const void *src)
{
	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	if (idx > dst->len)
		GRD(arr_resize(dst, idx) == -1, -1);
	GRD(arr_reserve(dst, 1) == -1, -1);
	if (idx < dst->len)
		arr_memmove(ARR_IDX(dst, idx + 1), ARR_IDX(dst, idx)
					, (dst->len - idx) * dst->elm.sze);
	if (dst->elm.dup != 0)
		GRD(dst->elm.dup(ARR_IDX(dst, idx), src) == -1, -1);
	else
		arr_memcpy(ARR_IDX(dst, idx), src, dst->elm.sze);
	++dst->len;
	return (0);
}

int8_t	arr_insertm(t_arr *dst, size_t idx, const void *src, size_t src_len)
{
	size_t	i;

	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	GRD(src_len == 0, 0);
	if (idx > dst->len)
		GRD(arr_resize(dst, idx) == -1, -1);
	GRD(arr_reserve(dst, src_len) == -1, -1);
	if (idx < dst->len)
		arr_memmove(ARR_IDX(dst, idx + src_len), ARR_IDX(dst, idx)
					, (dst->len - idx) * dst->elm.sze);
	if (dst->elm.dup != 0)
	{
		i = 0;
		while (i < src_len)
		{
			GRD(dst->elm.dup(ARR_IDX(dst, idx + i)
				, &((uint8_t *)src)[i * dst->elm.sze]) == -1, -1);
			++i;
		}
	}
	else
		arr_memcpy(ARR_IDX(dst, idx), src, src_len * dst->elm.sze);
	dst->len += src_len;
	return (0);
}

int8_t	arr_insertarr(t_arr *dst, size_t idx, t_arr *src)
{
	size_t	i;

	GRD(dst == 0, -1);
	GRD(dst->cap == 0, -1);
	GRD(src->len == 0, 0);
	if (idx > dst->len)
		GRD(arr_resize(dst, idx) == -1, -1);
	GRD(arr_reserve(dst, src->len) == -1, -1);
	if (idx < dst->len)
		arr_memmove(ARR_IDX(dst, idx + src->len), ARR_IDX(dst, idx)
					, (dst->len - idx) * dst->elm.sze);
	if (dst->elm.dup != 0)
	{
		i = 0;
		while (i < src->len)
		{
			GRD(dst->elm.dup(ARR_IDX(dst, idx + i), ARR_IDX(src, i)) == -1
				, -1);
			++i;
		}
	}
	else
		arr_memcpy(ARR_IDX(dst, idx), ARR_IDX(src, 0), src->len * dst->elm.sze);
	dst->len += src->len;
	return (0);
}
