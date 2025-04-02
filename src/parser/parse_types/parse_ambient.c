/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:02:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/02 03:36:28 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void print_ambient(t_scene *scene)
{
    printf("Ambient light ratio: %f\n", scene->amb_light.ratio);
    printf("Ambient light color: %d %d %d\n", scene->amb_light.color.r,
           scene->amb_light.color.g, scene->amb_light.color.b);
}

int parse_ambient(char **elements, t_scene *scene)
{
    int error;

    error = 0;
    if (count_tokens(elements) != 3)
    {
        ft_putendl_fd("Error: Ambient light expects exactly 3 elements", 2);
        return (0);
    }
    if (!is_valid_float(elements[1]))
    {
        ft_putendl_fd("Error: Invalid ambient light ratio.", 2);
        return (0);
    }
    scene->amb_light.ratio = ft_atod(elements[1]);
    if (scene->amb_light.ratio < 0 || scene->amb_light.ratio > 1)
    {
        ft_putendl_fd("Error: Ambient light ratio out of range (00).", 2);
        return (0);
    }
    // Validate color before parsing
    if (!is_valid_color(elements[2]))
    {
        ft_putendl_fd("Error: Invalid ambient light color format.", 2);
        return (0);
    }
    scene->amb_light.color = parse_color_str(elements[2], &error);
    if (error)
    {
        ft_putendl_fd("Error: Failed to parse ambient light color.", 2);
        return (0);
    }
    print_ambient(scene);
    return (1);
}
