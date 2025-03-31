/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:07:48 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 19:41:47 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_camera(char **elements, t_scene *scene)
{
    printf("Parsing camera...\n");
    t_vector vec;
    int error;
    
    error = 0;
    // printf ("Camera elements: %s, %s, %s\n", elements[1], elements[2], elements[3]);
    vec = parse_vector(elements[1], &error);
    if (error)
    {
        // ft_exit_handler((char **){"Error: Failed to parse camera vector\n", "line:", __LINE__ ,"\nfunction:", __FUNCTION__,"\n",NULL}, scene, 1, NULL);
        printf("Error: Failed to parse camera vector 1\n");
        return (-1);
    }
    scene->camera.pos = vec;
    scene->camera.norm_3d = parse_vector(elements[2], &error);
    if (error)
    {
        printf("Error: Failed to parse camera vector 2\n");
        // ft_exit_handler((char **){"Error: Failed to parse camera vector\n", "line:", __LINE__ ,"\nfunction:", __FUNCTION__,"\n",NULL}, scene, 1, NULL);
        return (-1);
    }
    scene->camera.fov = ft_atod(elements[3]);

    printf("Camera position: (%.2f,  %.2f,  %.2f)\n", scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z);
    printf("Camera vector: (%f, %f, %f)\n", scene->camera.norm_3d.x, scene->camera.norm_3d.y, scene->camera.norm_3d.z);
    printf("Camera fov: %f\n", scene->camera.fov);
    return (0);
}
