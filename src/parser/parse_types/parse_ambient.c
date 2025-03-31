/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:02:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 19:40:59 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int prase_ambient(char **elements, t_scene *scene)
{
    printf("Parsing ambient light...\n");
    int error;
    
    error = 0;
    if (!elements || !scene)
        return (-1);
    if (!is_valid_input(elements[1]))
    {
        // free_split(elements);
        // ft_exit_handler((char *[]){"Error: Invalid ambient light ratio.\n", "line:",(char *) __LINE__ ,"\nfunction:", (char *)__FUNCTION__,"\n",NULL}, scene, 1, elements);
    }
    scene->amb_light.ratio = ft_atod(elements[1]);
    if (scene->amb_light.ratio < 0 || scene->amb_light.ratio > 1)
    {
        // free_split(elements);
        // ft_exit_handler((char *[]){"Error: Ambient light ratio out of range\n", "line:", (char *) __LINE__ ,"\nfunction:", (char *) __FUNCTION__,"\n",NULL}, scene, 1, elements);
    }
    if (!is_valid_color(elements[2]))
    {
        // free_split(elements);
        // ft_exit_handler((char *[]){"Error: Invalid ambient light color\n", "line:", (char *) __LINE__ ,"\nfunction:", (char *)__FUNCTION__,"\n",NULL}, scene, 1, elements);
    }
    scene->amb_light.color = parse_color(elements[2], &error);
    if (error)
    {
        // free_split(elements);
        // ft_exit_handler((char *[]){"Error: Failed to parse ambient light color\n", "line:", (char *) __LINE__ ,"\nfunction:", (char *)__FUNCTION__,"\n",NULL}, scene, 1, elements);
    }
    printf("Ambient light ratio: %f\n", scene->amb_light.ratio);
    printf("Ambient light color: %d %d %d\n", scene->amb_light.color.r, scene->amb_light.color.g, scene->amb_light.color.b);
    return (1);
}