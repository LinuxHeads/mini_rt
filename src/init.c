/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:51:20 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/01 02:52:22 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void    init(t_scene *scene)
{
    scene->camera.pos = (t_vector){0, 0, 0};
    scene->camera.norm_3d = (t_vector){0, 0, 0};
    scene->camera.fov = 0;
    scene->amb_light.ratio = 0;
    scene->amb_light.color = (t_rgb){0, 0, 0};
    scene->light.pos = (t_vector){0, 0, 0};
    scene->light.brightness = 0;
    scene->light.color = (t_rgb){0, 0, 0};
    scene->plane.pos = (t_vector){0, 0, 0};
    scene->plane.norm_3d = (t_vector){0, 0, 0};
    scene->plane.color = (t_rgb){0, 0, 0};
    scene->sphere.pos = (t_vector){0, 0, 0};
    scene->sphere.diameter = 0;
    scene->sphere.color = (t_rgb){0, 0, 0};
    scene->cylinder.pos = (t_vector){0, 0, 0};
    scene->cylinder.norm_3d = (t_vector){0, 0, 0};
    scene->cylinder.diameter = 0;
    scene->cylinder.height = 0;
    scene->cylinder.color = (t_rgb){0, 0, 0};
    scene->fd = -1;
}
