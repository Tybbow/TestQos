/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listqos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 09:47:16 by tiskow            #+#    #+#             */
/*   Updated: 2018/03/01 17:03:32 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/qos.h"

t_qos	*createElem(char *name, char *IP, double debit)
{
	t_qos	*newElem;

	newElem = malloc(sizeof(t_qos));
	if (!newElem)
		return (NULL);
	newElem->name = strdup(name);
	newElem->IPaddr = strdup(IP);
	newElem->debit = debit;
	newElem->next = NULL;
	return (newElem);
}

t_qos	*addList(t_qos *qos, char *name, char *IP, double debit)
{
	t_qos	*newE;
	t_qos	*tmp;

	newE = createElem(name, IP, debit);
	if (!newE)
		return (NULL);
	if (!qos)
		return (newE);
	tmp = qos;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newE;
	return (qos);
}

void	disList(t_qos *qos)
{
	t_qos	*tmp;

	tmp = qos;
	while (tmp)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

void	freeList(t_qos *qos)
{
	t_qos	*tmp;

	while (qos)
	{
		tmp = qos;
		qos = qos->next;
		free(tmp->name);
		free(tmp->IPaddr);
		free(tmp);
	}
}