/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:12:52 by hkalia            #+#    #+#             */
/*   Updated: 2017/01/31 15:10:56 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_private.h"

char	*arr_tostr(t_arr *src)
{
	GRD(src == 0, 0);
	GRD(src->cap == 0, 0);
	if (src->len != src->cap)
		if (((char *)src->ptr)[src->len] == 0)
			return ((char *)src->ptr);
	GRD(arr_insert(src, src->len, 0) == -1, 0);
	--src->len;
	return ((char *)src->ptr);
}

void	arr_bzero(void *src, size_t len)
{
	unsigned char	*src_cpy;

	src_cpy = (unsigned char *)src;
	while (len--)
		*src_cpy++ = 0;
}

void	*arr_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	while (len-- > 0)
		*dst_cpy++ = *src_cpy++;
	return (dst);
}

void	*arr_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_cpy;
	unsigned char	*dst_cpy;

	src_cpy = (unsigned char *)src;
	dst_cpy = (unsigned char *)dst;
	if (src_cpy < dst_cpy)
	{
		src_cpy = src_cpy + len - 1;
		dst_cpy = dst_cpy + len - 1;
		while (len-- > 0)
			*dst_cpy-- = *src_cpy--;
	}
	else
	{
		while (len-- > 0)
			*dst_cpy++ = *src_cpy++;
	}
	return (dst);
}
