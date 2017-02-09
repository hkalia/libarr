/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:35:23 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/09 12:12:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_PRIVATE_H
# define ARR_PRIVATE_H

# include <arr.h>

void	arr_bzero(void *src, size_t len);
void	*arr_memcpy(void *dst, const void *src, size_t len);
void	*arr_memmove(void *dst, const void *src, size_t len);

#endif
