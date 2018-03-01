/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:17:32 by tiskow            #+#    #+#             */
/*   Updated: 2018/03/01 14:46:40 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/qos.h"

int	main(int ac, char **av) 
{
    int ret;
    int fd;
    char *tmp;
    t_qos *qos;

    qos = NULL;
    if (ac != 2)
        return (usage());
    fd = open(av[1], O_RDONLY);
    if (fd != -1)
    {
        tmp = (char *)malloc(sizeof(char) * 80000);
        if (!tmp)
            return (error("malloc"));
        ret = read(fd, tmp, 79999);
        close(fd);
        qos = ft_readfile(tmp);
        launch(qos);
        freeList(qos);
        free(tmp);
    }
    return (0);
}
