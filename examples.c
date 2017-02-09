/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examples.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:39:29 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/09 14:36:01 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		main(void)
{
	t_arr	str;

	arr_init(&str, 1, (t_arr_elm){sizeof(char), 0, 0, 0});
	arr_appendm(&str, "Hello World!", 13);
	printf("%s\n", str.ptr);
	arr_dtr(&str);
	return (0);
}

// int		main(void)
// {
// 	t_arr	array;
// 	int		c;
//
// 	GRD(arr_init(&array, 2, (t_arr_elm){sizeof(char), 0, 0, 0}) == -1, -1);
// 	while (1)
// 	{
// 		c = getchar();
// 		if (c == EOF || c == '\n')
// 			break ;
// 		GRD2(arr_append(&array, &c) == -1, perror("append"), arr_dtr(&array), -1);
// 	}
// 	printf("%s\n", arr_tostr(&array));
// 	arr_dtr(&array);
// 	return (0);
// }

// int		main(void)
// {
// 	t_arr	nums;
// 	int		i;
// 	int		*tmp;
//
// 	arr_init(&nums, 10, (t_arr_elm){sizeof(int), 0, 0, 0});
// 	i = 0;
// 	while (i < 10)
// 	{
// 		arr_insert(&nums, nums.len, &i);
// 		++i;
// 	}
// 	tmp = (int *)nums.ptr;
// 	i = 0;
// 	while (i < 10)
// 		printf("%d\n", tmp[i++]);
// 	arr_dtr(&nums);
// 	return (0);
// }

// typedef struct	s_ab
// {
// 	int			a;
// 	int			b;
// }				t_ab;
//
// int		main(void)
// {
// 	t_arr	pairs;
// 	t_ab	test;
// 	t_ab	*tmp;
// 	size_t	i;
//
// 	arr_init(&pairs, 1, (t_arr_elm){sizeof(t_ab), 0, 0, 0});
// 	test.a = 1;
// 	test.b = 2;
// 	arr_insert(&pairs, pairs.len, &test);
// 	test.a = 10;
// 	test.b = 20;
// 	arr_insert(&pairs, pairs.len, &test);
// 	tmp = (t_ab *)pairs.ptr;
// 	i = 0;
// 	while (i < pairs.len)
// 	{
// 		printf("%d %d\n", tmp[i].a, tmp[i].b);
// 		++i;
// 	}
// 	arr_dtr(&pairs);
// 	return 0;
// }
//
// typedef struct	s_intstr
// {
// 	int			i;
// 	char		*s;
// }				t_intstr;
//
// size_t	ft_strlen(const char *src)
// {
// 	const char	*src_cpy;
//
// 	src_cpy = src;
// 	while (*src_cpy)
// 		++src_cpy;
// 	return (src_cpy - src);
// }
//
// char	*ft_strdup(const char *src)
// {
// 	size_t	i;
// 	size_t	src_len;
// 	char	*dst;
//
// 	i = 0;
// 	src_len = ft_strlen(src);
// 	if (!(dst = (char *)malloc(sizeof(char) * (src_len + 1))))
// 		return (NULL);
// 	while (i < src_len)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (dst);
// }
//
// int8_t	intstr_dup(void *dst, const void *src)
// {
// 	t_intstr	*dst_cpy;
// 	t_intstr	*src_cpy;
//
// 	dst_cpy = (t_intstr *)dst;
// 	src_cpy = (t_intstr *)src;
// 	dst_cpy->i = src_cpy->i;
// 	GRD((dst_cpy->s = ft_strdup(src_cpy->s)) == 0, -1);
// 	return (0);
// }
//
// void	intstr_dtr(void *elm)
// {
// 	t_intstr	*src;
//
// 	src = (t_intstr *)elm;
// 	if (src->s)
// 		free(src->s);
// }
//
// t_arr_elm	intstr_elm = {sizeof(t_intstr), NULL, intstr_dup, intstr_dtr};
//
// int		main(void)
// {
// 	t_arr		intstrs;
// 	t_intstr	test;
// 	t_intstr	*tmp;
// 	size_t		i;
//
// 	arr_init(&intstrs, 1, intstr_elm);
// 	test.i = 1;
// 	test.s = "hello";
// 	arr_insert(&intstrs, intstrs.len, &test);
// 	test.i = 2;
// 	test.s = "world";
// 	arr_insert(&intstrs, intstrs.len, &test);
// 	tmp = (t_intstr *)intstrs.ptr;
// 	i = 0;
// 	while (i < intstrs.len)
// 	{
// 		printf("%d %s\n", tmp[i].i, tmp[i].s);
// 		++i;
// 	}
// 	arr_dtr(&intstrs);
// 	return 0;
// }
