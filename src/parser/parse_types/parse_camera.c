/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:07:48 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/02 03:34:26 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    print_camera(t_camera camera)
{
    printf("Camera position: %f %f %f\n", camera.pos.x, camera.pos.y, camera.pos.z);
    printf("Camera normal: %f %f %f\n", camera.norm_3d.x, camera.norm_3d.y, camera.norm_3d.z);
    printf("Camera fov: %f\n", camera.fov);
}

int parse_camera(char **elements, t_scene *scene)
{
    t_vector vec;

    if (count_tokens(elements) != 4)
    {
        ft_putendl_fd("Error: Camera expects exactly 4 elements", 2);
        return (0);
    }
    if (!parse_vector_components(elements[1], &vec))
    {
        ft_putendl_fd("Error: Failed to parse camera position vector", 2);
        return (0);
    }
    scene->camera.pos = vec;
    if (!parse_vector_components(elements[2], &vec))
    {
        ft_putendl_fd("Error: Failed to parse camera orientation vector", 2);
        return (0);
    }
    scene->camera.norm_3d = vec;
    if (!is_valid_float(elements[3]))
    {
        ft_putendl_fd("Error: Invalid camera FOV", 2);
        return (0);
    }
    scene->camera.fov = ft_atod(elements[3]);
    if (scene->camera.fov <= 0 || scene->camera.fov >= 180)
    {
        ft_putendl_fd("Error: Camera FOV must be between 0 and 180 degrees", 2);
        return (0);
    }
    print_camera(scene->camera);    
    return (1);
}
