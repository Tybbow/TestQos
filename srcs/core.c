/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:45:19 by tiskow            #+#    #+#             */
/*   Updated: 2018/03/01 17:04:02 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/qos.h"

void	launch(t_qos *qos)
{
	t_qos	*tmp;

	tmp = qos;
	while (tmp)
	{
		if (onePing(tmp->IPaddr))
			ft_putendl("Ping OK");
		else
			ft_putendl("Ping NOK");
		tmp = tmp->next;
	}
}