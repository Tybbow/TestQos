/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_ip.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 08:20:37 by tiskow            #+#    #+#             */
/*   Updated: 2018/03/01 08:38:52 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/qos.h"

char	*ft_strreplace_ip(char *str)
{
	char *tmp;
	char **split;

	if (!str)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * strlen(str) + 3);
	if (!tmp)
		return (NULL);
	split = ft_strsplit(str, ".");
	tmp = strcpy(tmp, "19.");
	tmp = strcat(tmp, split[1]);
	tmp = strcat(tmp, ".");
	tmp = strcat(tmp, split[2]);
	tmp = strcat(tmp, ".");
	tmp = strcat(tmp, "195");
	free(split);
	return (tmp);
}