/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:04:59 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/09 14:05:21 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <stdlib.h>
#include <stdio.h>

// char *lsh_read_line(void)
// {
//   int bufsize = LSH_RL_BUFSIZE;
//   int position = 0;
//   char *buffer = malloc(sizeof(char) * bufsize);
//   int c;
//
//   if (!buffer) {
//     fprintf(stderr, "lsh: allocation error\n");
//     exit(EXIT_FAILURE);
//   }
//
//   while (1) {
//     // Read a character
//     c = getchar();
//
//     // If we hit EOF, replace it with a null character and return.
//     if (c == EOF || c == '\n') {
//       buffer[position] = '\0';
//       return buffer;
//     } else {
//       buffer[position] = c;
//     }
//     position++;
//
//     // If we have exceeded the buffer, reallocate.
//     if (position >= bufsize) {
//       bufsize += LSH_RL_BUFSIZE;
//       buffer = realloc(buffer, bufsize);
//       if (!buffer) {
//         fprintf(stderr, "lsh: allocation error\n");
//         exit(EXIT_FAILURE);
//       }
//     }
//   }
// }

int		main(void)
{
	char	*array;
	size_t	i;
	int		c;

	array = malloc(sizeof(char) * 50);
	i = 0;
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			array[i] = '\0';
			break ;
		}
		else
			array[i] = c;
		++i;
	}
	printf("%s\n", array);
	free(array);
	return (0);
}
