/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:17:52 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 21:23:39 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_sphere(char **elements, t_scene *scene)
{
    t_vector pos;
    int error;

    printf("Parsing sphere...\n");
    error = 0;
    pos = parse_vector(elements[1], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid sphere position", 2);
        return (0);
    }
    //check for valid diameter (is a float)
    scene->sphere.diameter = ft_atod(elements[2]);
    if (scene->sphere.diameter <= 0)
    {
        ft_putendl_fd("Error: Invalid sphere diameter", 2);
        return (0);
    }
    scene->sphere.pos = pos;
    scene->sphere.color = parse_color(elements[3], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid sphere color", 2);
        return (0);
    }
    printf("Sphere position: %f %f %f\n", scene->sphere.pos.x, scene->sphere.pos.y, scene->sphere.pos.z);
    printf("Sphere diameter: %f\n", scene->sphere.diameter);
    printf("Sphere color: %d %d %d\n", scene->sphere.color.r, scene->sphere.color.g, scene->sphere.color.b);
    
    return (1);
}