/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:04:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 22:55:35 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int is_valid_float(char *line)
{
    int i;

    i = 0;
    if (ft_strchr(line, '.') != ft_strrchr(line, '.'))
        return (0);
    if (ft_strchr(line, '-') != ft_strrchr(line, '-'))
        return (0);
    while (line[i])
    {
        if (!ft_isdigit(line[i]) && line[i] != '-' && line[i] != '.' && line[i] != '+')
            return (0);
        if (line[i] == '.' && (i == 0 || line[i + 1] == '\0'))
            return (0);
        i++;
    }
    return (1);
}

int    is_valid_color(const char *color)
{
    int		i;
    char	**rgb;

    if (!color)
        return (0);
    rgb = ft_split(color, ',');
    if (!rgb)
        return (0);
    i = 0;
    while (rgb[i])
    {
        if (!is_valid_float(rgb[i]))
        {
            free_split(rgb);
            return (0);
        }
        i++;
    }
    if (i != 3)
    {
        free_split(rgb);
        return (0);
    }
    free_split(rgb);
    return (1);
}
