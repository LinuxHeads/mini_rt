/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:22:33 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 05:53:12 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
        if (!is_valid_input(rgb[i]))
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

t_rgb    parse_color(const char *color, int *error)
{
    char	**rgb;
    t_rgb    color_rgb;

    if (!color)
    {
        *error = 1;
        return ((t_rgb){0, 0, 0});
    }
    rgb = ft_split(color, ',');
    if (!rgb)
    {
        *error = 1;
        return ((t_rgb){0, 0, 0});
    }
    color_rgb.r = ft_atoi(rgb[0]);
    color_rgb.g = ft_atoi(rgb[1]);
    color_rgb.b = ft_atoi(rgb[2]);
    free_split(rgb);
    return (color_rgb);
}