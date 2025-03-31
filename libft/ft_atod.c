/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:16:17 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 05:50:45 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double ft_atod(const char *s)
{
    double result;
    int sign;
    int i;

    sign = 1;
    i = 0;
    if (!s || *s == '\0')
        return 0.0;
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
        i++;
    while (s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10.0 + (s[i] - '0');
        i++;
    }
    if (s[i] == '.')
    {
        i++;
        double factor = 0.1;
        while (s[i] >= '0' && s[i] <= '9')
        {
            result += (s[i] - '0') * factor;
            factor /= 10.0;
            i++;
        }
    }
    return sign * result;
}
