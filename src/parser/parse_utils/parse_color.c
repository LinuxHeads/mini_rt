/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:22:33 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/02 03:25:06 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    print_color(t_rgb color)
{
    printf("Color: %d %d %d\n", color.r, color.g, color.b);
}

t_rgb parse_color_str(const char *color_str, int *error)
{
    char **components;
    t_rgb color;
    int count;

    components = ft_split(color_str, ',');
    if (!components)
    {
        *error = 1;
        return ((t_rgb){0, 0, 0});
    }
    count = count_tokens(components);
    if (count != 3)
    {
        *error = 1;
        free_split(components);
        ft_putendl_fd("Error: Color must have exactly 3 components", 2);
        return ((t_rgb){0, 0, 0});
    }
    // if (!is_valid_float(components[0]) ||
    //     !is_valid_float(components[1]) ||
    //     !is_valid_float(components[2]))
    // {
    //     *error = 1;
    //     free_split(components);
    //     ft_putendl_fd("Error: Invalid numeric value in color", 2);
    //     return ((t_rgb){0, 0, 0});
    // }
    color.r = ft_atoi(components[0]);
    color.g = ft_atoi(components[1]);
    color.b = ft_atoi(components[2]);
    // if (color.r < 0 || color.r > 255 ||
    //     color.g < 0 || color.g > 255 ||
    //     color.b < 0 || color.b > 255)
    // {
    //     *error = 1;
    //     free_split(components);
    //     ft_putendl_fd("Error: Color components must be in range [0, 255]", 2);
    //     return ((t_rgb){0, 0, 0});
    // }
    free_split(components);
    return (color);
}
