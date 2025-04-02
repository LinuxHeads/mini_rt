/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:17:52 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/02 02:55:52 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void print_shpere(t_sphere sphere)
{
    printf("Sphere position: %f %f %f\n", sphere.pos.x, sphere.pos.y, sphere.pos.z);
    printf("Sphere diameter: %f\n", sphere.diameter);
    printf("Sphere color: %d %d %d\n", sphere.color.r, sphere.color.g, sphere.color.b);
}

int parse_sphere(char **elements, t_scene *scene)
{
    t_vector pos;
    int error;

    if (count_tokens(elements) != 4)
    {
        ft_putendl_fd("Error: Sphere expects exactly 4 elements", 2);
        return (0);
    }
    error = 0;
    if (!parse_vector_components(elements[1], &pos))
    {
        ft_putendl_fd("Error: Failed to parse sphere position", 2);
        return (0);
    }
    scene->sphere.pos = pos;
    if (!is_valid_float(elements[2]))
    {
        ft_putendl_fd("Error: Invalid sphere diameter", 2);
        return (0);
    }
    scene->sphere.diameter = ft_atod(elements[2]);
    if (scene->sphere.diameter <= 0)
    {
        ft_putendl_fd("Error: Sphere diameter must be positive", 2);
        return (0);
    }
    scene->sphere.color = parse_color_str(elements[3], &error);
    if (error)
    {
        ft_putendl_fd("Error: Failed to parse sphere color", 2);
        return (0);
    }
    print_shpere(scene->sphere);
    return (1);
}
