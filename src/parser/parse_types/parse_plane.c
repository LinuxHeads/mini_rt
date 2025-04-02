/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:25:41 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/02 02:56:54 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    print_plane(t_plane plane)
{
    printf("Plane position: %f %f %f\n", plane.pos.x, plane.pos.y, plane.pos.z);
    printf("Plane normal: %f %f %f\n", plane.norm_3d.x, plane.norm_3d.y, plane.norm_3d.z);
    printf("Plane color: %d %d %d\n", plane.color.r, plane.color.g, plane.color.b);
}

int parse_plane(char **elements, t_scene *scene)
{
    t_vector pos, normal;
    int error;

    if (count_tokens(elements) != 4)
    {
        ft_putendl_fd("Error: Plane expects exactly 4 elements", 2);
        return (0);
    }
    error = 0;
    if (!parse_vector_components(elements[1], &pos))
    {
        ft_putendl_fd("Error: Failed to parse plane position", 2);
        return (0);
    }
    if (!parse_vector_components(elements[2], &normal))
    {
        ft_putendl_fd("Error: Failed to parse plane normal", 2);
        return (0);
    }
    scene->plane.pos = pos;
    scene->plane.norm_3d = normal;
    scene->plane.color = parse_color_str(elements[3], &error);
    if (error)
    {
        ft_putendl_fd("Error: Failed to parse plane color", 2);
        return (0);
    }
    // if (scene->plane.norm_3d.x == 0 && scene->plane.norm_3d.y == 0 && scene->plane.norm_3d.z == 0)
    // {
    //     ft_putendl_fd("Error: Plane normal cannot be zero vector", 2);
    //     return (0);
    // }
    print_plane(scene->plane);
    return (1);
}
