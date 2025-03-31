/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:30:41 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 23:05:27 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    print_cylinder(t_cylinder cylinder)
{
    printf("Cylinder position: %f %f %f\n", cylinder.pos.x, cylinder.pos.y, cylinder.pos.z);
    printf("Cylinder normal: %f %f %f\n", cylinder.norm_3d.x, cylinder.norm_3d.y, cylinder.norm_3d.z);
    printf("Cylinder diameter: %f\n", cylinder.diameter);
    printf("Cylinder height: %f\n", cylinder.height);
    printf("Cylinder color: %d %d %d\n", cylinder.color.r, cylinder.color.g, cylinder.color.b);
}

static int parse_decimals(char **elements, t_scene *scene)
{
    if (!is_valid_float(elements[4]) || elements[4][0] == '\0' ||
        !is_valid_float(elements[3]) || elements[3][0] == '\0')
    {
        ft_putendl_fd("Error: Invalid cylinder diameter or height", 2);
        return (0);
    }
    scene->cylinder.diameter = ft_atod(elements[3]);
    if (scene->cylinder.diameter <= 0)
    {
        ft_putendl_fd("Error: Cylinder diameter must be positive", 2);
        return (0);
    }
    scene->cylinder.height = ft_atod(elements[4]);
    if (scene->cylinder.height <= 0)
    {
        ft_putendl_fd("Error: Cylinder height must be positive", 2);
        return (0);
    }
    return (1);
}

int parse_cylinder(char **elements,t_scene *scene)
{
    int error;
    
    printf("Parsing cylinder...\n");
    error = 0;
    scene->cylinder.pos = parse_vector(elements[1], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid cylinder position", 2);
        return (0);
    }
    if (!is_valid_color(elements[5]))
    {
        ft_putendl_fd("Error: Invalid cylinder color", 2);
        return (0);
    }
    scene->cylinder.color = parse_color(elements[5], &error);
    scene->cylinder.norm_3d = parse_vector(elements[2], &error);
    if (error)
    {
        ft_putendl_fd("Error: Invalid cylinder normal", 2);
        return (0);
    }
    parse_decimals(elements, scene);// check errer
    print_cylinder(scene->cylinder);
    return (1);    
}
