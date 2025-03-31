/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:12:19 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 19:41:30 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_vector parse_vector(char *vec_string, int *error)
{
    t_vector vec;
    char **vec_components;

    
    vec_components = ft_split(vec_string, ',');
    if (!vec_components)
    {
        *error = 1;
        return ((t_vector){0, 0, 0});
    }
    // printf ("Vector components: %s, %s, %s\n", vec_components[0], vec_components[1], vec_components[2]);
    if (vec_components[0] && vec_components[1] && vec_components[2])
    {
        vec.x = ft_atod(vec_components[0]);
        vec.y = ft_atod(vec_components[1]);
        vec.z = ft_atod(vec_components[2]);
        // printf ("Parsed vector: (%.2f, %.2f, %.2f)\n", vec.x, vec.y, vec.z);
    }
    else
    {
        *error = 1;
        free_split(vec_components);
        return ((t_vector){0, 0, 0});
    }

    free_split(vec_components);
    return (vec);
}
