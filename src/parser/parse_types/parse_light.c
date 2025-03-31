/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:11:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 21:15:57 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_light(char **elements, t_scene *scene)
{
    t_vector pos;
    int error;

    printf("Parsing light...\n");
    error = 0;
    pos = parse_vector(elements[1], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid light position", 2);
        return (0);
    }
    //check for valid brightness (is a float)
    scene->light.brightness = ft_atod(elements[2]);
    if (scene->light.brightness < 0 || scene->light.brightness > 1)
    {
        ft_putendl_fd("Error: Invalid light brightness", 2);
        return (0);
    }
    scene->light.pos = pos;
    scene->light.color = parse_color(elements[3], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid light color", 2);
        return (0);
    }
    printf("Light position: %f %f %f\n", scene->light.pos.x, scene->light.pos.y, scene->light.pos.z);
    printf("Light brightness: %f\n", scene->light.brightness);
    printf("Light color: %d %d %d\n", scene->light.color.r, scene->light.color.g, scene->light.color.b);
    return (1);
}