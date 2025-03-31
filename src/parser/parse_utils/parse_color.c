/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:22:33 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 19:11:48 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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