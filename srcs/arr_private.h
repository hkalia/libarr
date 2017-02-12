/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:35:23 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/11 16:32:56 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_PRIVATE_H
# define ARR_PRIVATE_H

# ifndef GRDS
#  define GRD(a, b) do{if(a){return(b);}}while(0)
#  define GRD1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define GRD2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define GRD3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
#  define GRD4(a, b, c, d, e, f) do{if(a){b;c;d;e;return(f);}}while(0)
#  define GRD5(a, b, c, d, e, f, g) do{if(a){b;c;d;e;f;return(g);}}while(0)
#  define GRD6(a, b, c, d, e, f, g, h) do{if(a){b;c;d;e;f;g;return(h);}}while(0)
# endif

# include <libarr.h>

void	arr_bzero(void *src, size_t len);
void	*arr_memcpy(void *dst, const void *src, size_t len);
void	*arr_memmove(void *dst, const void *src, size_t len);

#endif
