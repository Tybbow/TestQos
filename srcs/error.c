/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:32:43 by tiskow            #+#    #+#             */
/*   Updated: 2018/03/01 16:32:45 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/qos.h"

int    usage()
{
    printf("./qos filename\n");
    return (0);
}

int     error(char *str)
{
    printf("Failure for: %s\n", str);
    return (0);
}
