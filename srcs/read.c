/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:18:01 by tiskow            #+#    #+#             */
/*   Updated: 2018/03/01 13:47:06 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/qos.h"

t_qos    *ft_readseg(char *alias, char *ipaddr, char *cdebit, t_qos *qos)
{
    char **seg;
    double debit = 0;
    char *newIP;
    
    seg = ft_strsplit(alias, "_");
    ft_strtrim(cdebit);
    if (!strcmp((&cdebit[strlen(cdebit) - 1]), "M"))
        debit = atof(cdebit) * 2;
    if (!strcmp((&cdebit[strlen(cdebit) - 1]), "K"))
        debit = atof(cdebit) * 2 / 1000;
    newIP = ft_strreplace_ip(ipaddr);
    qos = addList(qos, seg[1], newIP, debit);
    free(newIP);
    free(seg);
    return (qos);
}

t_qos    *ft_readline(char *tmp, t_qos *qos)
{
    char **line;
    line = ft_strsplit(tmp, ",");
    qos = ft_readseg(line[0], line[1], line[2], qos);
    free(line);
    return (qos);
}

t_qos    *ft_readfile(char *tmp)
{
    char **split;
    int i = 0;
    t_qos *qos;

    qos = NULL;
    split = ft_strsplit(tmp, "\n");
    while (split[i])
    {
        qos = ft_readline(split[i], qos);
        i++;
    }
    free(split);
    return (qos);
}
