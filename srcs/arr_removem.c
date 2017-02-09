/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_removem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:21:18 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/02 11:41:17 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_private.h"

int8_t	arr_remove(t_arr *src, size_t idx)
{
	GRD(src == 0, -1);
	GRD(src->cap == 0 || idx > src->len, -1);
	if (src->elm.dtr != 0)
		src->elm.dtr(ARR_IDX(src, idx));
	arr_memmove(ARR_IDX(src, idx), ARR_IDX(src, idx + 1), src->elm.sze);
	--src->len;
	return (0);
}

int8_t	arr_removem(t_arr *src, size_t idx, size_t len)
{
	size_t	i;

	GRD(src == 0, -1);
	GRD(src->cap == 0 || idx + len > src->len, -1);
	if (src->elm.dtr != 0)
	{
		i = 0;
		while (i < len)
			src->elm.dtr(ARR_IDX(src, idx + i++));
	}
	arr_memmove(ARR_IDX(src, idx), ARR_IDX(src, idx + len)
				, (src->len - (idx + len)) * src->elm.sze);
	src->len -= len;
	return (0);
}
