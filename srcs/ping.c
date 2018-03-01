/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:51:56 by tiskow            #+#    #+#             */
/*   Updated: 2018/03/01 22:11:41 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/qos.h"

char	*createOnePing(char **ping, char *IP, char *class)
{
	class = NULL;
	strcpy(*ping, "/sbin/ping ");
	strcat(*ping, IP);
	// strcat(*ping, " -Q ");
	// strcat(*ping, class);
	strcat(*ping, " -c 2 -q");
	ft_putendl(*ping);
	return (*ping);
}

int		checkPingInt(char *str)
{
	char 	**response = ft_strsplit(str, ",");
	int 	loss = 0;

	loss = atoi(response[2]);
	ft_putnbr(loss);
	ft_putendl("");
	free(response);
	if (loss <= 1)
		return (1);
	return (0);
}

int		checkPing(char *buff)
{
	char 	**split = ft_strsplit(buff, "\n");
	char	*dup = NULL;
	int 	i = 0;
	int		result = 0;

	while (split[i])
	{
		if (strnstr(split[i], "transmitted", strlen(split[i])))
		{
			dup = strdup(split[i]);
			result = checkPingInt(dup);
			return (result);
		}
		i++;
	}
	free(split);
	free(dup);
	return (0);
}

int		onePing(char *IP)
{
	char 	*ping;
	char	buff[2000];
	char	buf[1000];
	FILE	*fp;
	
	ping = (char *)malloc(sizeof(char) * 50 + 1);
	if (!ping)
		return (0);
	createOnePing(&ping, IP, D1);
	fp = popen(ping, "r");
	if (!fp)
		return (0);
	strcpy(buff, "Parti !!\n");
	while (fgets(buf, sizeof(buf), fp))
		strcat(buff, buf);
	pclose(fp);
	free(ping);
	return (checkPing(buff));
}