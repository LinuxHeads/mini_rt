/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:30:41 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 21:36:56 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_cylinder(char **elements,t_scene *scene)
{
    int error;
    t_vector pos;
    t_vector normal;
    
    printf("Parsing cylinder...\n");
    error = 0;
    pos = parse_vector(elements[1], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid cylinder position", 2);
        return (0);
    }
    normal = parse_vector(elements[2], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid cylinder normal", 2);
        return (0);
    }
    scene->cylinder.pos = pos;
    scene->cylinder.norm_3d = normal;
    
    scene->cylinder.diameter = ft_atod(elements[3]);
    if (error)
    {
        ft_putendl_fd("Error: Invalid cylinder diameter", 2);
        return (0);
    }
    scene->cylinder.height = ft_atod(elements[4]);
    if (error)
    {
        ft_putendl_fd("Error: Invalid cylinder height", 2);
        return (0);
    }
    scene->cylinder.color = parse_color(elements[5], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid cylinder color", 2);
        return (0);
    }
    printf("Cylinder position: %f %f %f\n", scene->cylinder.pos.x, scene->cylinder.pos.y, scene->cylinder.pos.z);
    printf("Cylinder normal: %f %f %f\n", scene->cylinder.norm_3d.x, scene->cylinder.norm_3d.y, scene->cylinder.norm_3d.z);
    printf("Cylinder diameter: %f\n", scene->cylinder.diameter);
    printf("Cylinder height: %f\n", scene->cylinder.height);
    printf("Cylinder color: %d %d %d\n", scene->cylinder.color.r, scene->cylinder.color.g, scene->cylinder.color.b);
    return (1);    
}
