/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 22:05:39 by tiskow            #+#    #+#             */
/*   Updated: 2018/03/01 22:06:39 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/qos.h"

void    ft_putnbr(int n)
{
        if (n == -2147483648)
        	return (ft_putstr("-2147483648"));
        if (n < 0)
        {
                n = -n;
                ft_putchar('-');
        }
        if (n > 9)
        {
                ft_putnbr((n / 10));
                ft_putchar((n % 10 + '0'));
        }
        else
                ft_putchar((n + '0'));
}