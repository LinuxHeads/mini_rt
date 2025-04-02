/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:11:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/02 02:58:31 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    print_light(t_light light)
{
    printf("Light position: %f %f %f\n", light.pos.x, light.pos.y, light.pos.z);
    printf("Light brightness: %f\n", light.brightness);
    printf("Light color: %d %d %d\n", light.color.r, light.color.g, light.color.b);
}

int parse_light(char **elements, t_scene *scene)
{
    t_vector pos;
    int error;

    if (count_tokens(elements) != 4)
    {
        ft_putendl_fd("Error: Light expects exactly 4 elements", 2);
        return (0);
    }
    error = 0;
    if (!parse_vector_components(elements[1], &pos))
    {
        ft_putendl_fd("Error: Failed to parse light position", 2);
        return (0);
    }
    scene->light.pos = pos;
    if (!is_valid_float(elements[2]))
    {
        ft_putendl_fd("Error: Invalid light brightness value", 2);
        return (0);
    }
    scene->light.brightness = ft_atod(elements[2]);
    if (scene->light.brightness < 0 || scene->light.brightness > 1)
    {
        ft_putendl_fd("Error: Light brightness out of range (0-1)", 2);
        return (0);
    }
    scene->light.color = parse_color_str(elements[3], &error);
    if (error)
    {
        ft_putendl_fd("Error: Failed to parse light color", 2);
        return (0);
    }
    print_light(scene->light);
    return (1);
}
