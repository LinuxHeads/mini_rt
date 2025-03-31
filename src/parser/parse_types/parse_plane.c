/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:25:41 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 21:27:26 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_plane(char **elements, t_scene *scene)
{
    int error;
    t_vector pos;
    t_vector normal;

    printf("Parsing plane...\n");
    error = 0;
    pos = parse_vector(elements[1], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid plane position", 2);
        return (0);
    }
    normal = parse_vector(elements[2], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid plane normal", 2);
        return (0);
    }
    scene->plane.pos = pos;
    scene->plane.norm_3d = normal;
    scene->plane.color = parse_color(elements[3], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid plane color", 2);
        return (0);
    }
    printf("Plane position: %f %f %f\n", scene->plane.pos.x, scene->plane.pos.y, scene->plane.pos.z);
    printf("Plane normal: %f %f %f\n", scene->plane.norm_3d.x, scene->plane.norm_3d.y, scene->plane.norm_3d.z);
    printf("Plane color: %d %d %d\n", scene->plane.color.r, scene->plane.color.g, scene->plane.color.b);
    return (1);
}