/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libarr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:03:28 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/11 16:31:32 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBARR_H
# define LIBARR_H

# ifndef GRDS
#  define GRD(a, b) do{if(a){return(b);}}while(0)
#  define GRD1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define GRD2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define GRD3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
#  define GRD4(a, b, c, d, e, f) do{if(a){b;c;d;e;return(f);}}while(0)
#  define GRD5(a, b, c, d, e, f, g) do{if(a){b;c;d;e;f;return(g);}}while(0)
#  define GRD6(a, b, c, d, e, f, g, h) do{if(a){b;c;d;e;f;g;return(h);}}while(0)
# endif

# include <stddef.h>
# include <stdint.h>

# define ARR_GROW_FACTOR 2
# define ARR_IDX(a, b) ((a)->ptr + ((a)->elm.sze * (b)))

typedef struct	s_elm
{
	size_t	sze;
	int8_t	(*zero)(void *elm);
	int8_t	(*dup)(void *dst, const void *src);
	void	(*dtr)(void *elm);
}				t_arr_elm;

typedef struct	s_arr
{
	uint8_t		*ptr;
	t_arr_elm	elm;
	size_t		len;
	size_t		cap;
}				t_arr;

int8_t			arr_init(t_arr *src, size_t cap, t_arr_elm elm);
int8_t			arr_reserve(t_arr *src, size_t sze);
int8_t			arr_resize(t_arr *src, size_t sze);
void			arr_dtr(t_arr *src);
int8_t			arr_insert(t_arr *dst, size_t idx, const void *src);
int8_t			arr_insertm(t_arr *dst, size_t idx, const void *src
							, size_t src_len);
int8_t			arr_insertarr(t_arr *dst, size_t idx, t_arr *src);
int8_t			arr_append(t_arr *dst, const void *src);
int8_t			arr_appendm(t_arr *dst, const void *src, size_t src_len);
int8_t			arr_appendarr(t_arr *dst, t_arr *src);
void			arr_swap(t_arr *src, size_t i, size_t j);
void			arr_reverse(t_arr *src);
void			arr_qsort(t_arr *src, int (*cmp)(const void *, const void *
							, size_t));
void			arr_qsort_r(t_arr *src, void *thunk, int (*cmp)(const void *
							, const void *, size_t, void *));
int8_t			arr_remove(t_arr *src, size_t idx);
int8_t			arr_removem(t_arr *src, size_t idx, size_t len);
char			*arr_tostr(t_arr *src);

#endif
