/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:41:27 by tiskow            #+#    #+#             */
/*   Updated: 2018/02/28 11:18:36 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/qos.h"

char	**ft_strsplit(char *str, char *c)
{
	char **split = NULL;
	char *cs = NULL;
	size_t i = 0;
	size_t size = 1;

	if (!str || !c)
		return (NULL);
	for (i = 0; (cs = strtok(str, c)); i++)
	{
		if (size <= i + 1)
		{
			void *tmp = NULL;
			size <<= 1;
			tmp = realloc(split, sizeof(split) * size);
			if (tmp)
				split = tmp;
			else
			{
				free(split);
				split = NULL;
				return (split);
			}
		}
		split[i] = cs;
		str = NULL;
	}
	split[i] = NULL;
	return (split);
}
