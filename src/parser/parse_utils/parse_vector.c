/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:12:19 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/02 02:43:42 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_vector_components(const char *vec_string, t_vector *vec)
{
    char **components;
    int count;

    components = ft_split(vec_string, ',');
    if (!components)
    {
        ft_putendl_fd("Error: Memory allocation failed for vector", 2);
        return (0);
    }
    count = count_tokens(components);
    if (count != 3)
    {
        free_split(components);
        ft_putendl_fd("Error: Vector must have exactly 3 components", 2);
        return (0);
    }
    if (!is_valid_float(components[0]) ||
        !is_valid_float(components[1]) ||
        !is_valid_float(components[2]))
    {
        free_split(components);
        ft_putendl_fd("Error: Invalid numeric value in vector", 2);
        return (0);
    }
    vec->x = ft_atod(components[0]);
    vec->y = ft_atod(components[1]);
    vec->z = ft_atod(components[2]);
    free_split(components);
    return (1);
}
