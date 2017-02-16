/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:04:59 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/15 20:28:02 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libarr.h>
#include <stdlib.h>
#include <stdio.h>

// int		main(void)
// {
// 	size_t	capacity;
// 	char	*array;
// 	char	*tmp;
// 	size_t	i;
// 	size_t	j;
// 	int		c;
//
// 	capacity = 50;
// 	array = malloc(sizeof(char) * capacity);
// 	i = 0;
// 	while (1)
// 	{
// 		c = getchar();
// 		if (c == EOF || c == '\n')
// 		{
// 			array[i] = '\0';
// 			break ;
// 		}
// 		else
// 			array[i] = c;
// 		++i;
// 		if (i >= capacity)
// 		{
// 			tmp = malloc(sizeof(char) * (capacity * 2));
// 			if (tmp == 0)
// 			{
// 				perror("malloc");
// 				free(array);
// 				return (-1);
// 			}
// 			j = 0;
// 			while (j < capacity)
// 			{
// 				tmp[j] = array[j];
// 				++j;
// 			}
// 			free(array);
// 			array = tmp;
// 			capacity *= 2;
// 		}
// 	}
// 	printf("%s\n", array);
// 	free(array);
// 	return (0);
// }
