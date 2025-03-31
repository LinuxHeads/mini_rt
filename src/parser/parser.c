/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:47:23 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/01 02:47:12 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     parse_line(char *line, t_scene *scene)
{
    char **elements;
    
    if (line[0] == '\0')
        return (0);
    elements = ft_split(line, ' ');
    if (!elements)
        return (-1);
    if (ft_strncmp(elements[0], "A", 1) == 0)
        prase_ambient(elements, scene);
    else if (ft_strncmp(elements[0], "C", 1) == 0)
        parse_camera(elements, scene);
    else if (ft_strncmp(elements[0], "L", 1) == 0)
        parse_light(elements, scene);
    else if (ft_strncmp(elements[0], "sp", 2) == 0)
        parse_sphere(elements, scene);
    else if (ft_strncmp(elements[0], "pl", 2) == 0)
        parse_plane(elements, scene);
    else if (ft_strncmp(elements[0], "cy", 2) == 0)
        parse_cylinder(elements, scene);
    else
    {
        free_split(elements);
        return (-1);
    }
    free_split(elements);
    return (1);
}

void    parse_into_scene(t_scene *scene)
{
    char    *line;
    int     ret;

    while (1)
    {
        line = get_next_line(scene->fd);
        if (!line)
            break ;
        if (*line == '\n' || *line == '\0')
        {
            free(line);
            continue;
        }
        ret = parse_line(line, scene);
        free(line);
        if (ret == -1)
        {
            free(scene);
            exit(1);
        }
    }
    close(scene->fd);
}

void    parser(char *filename, t_scene *scene)
{
    check_file_extension(filename, scene);
    open_file(filename, scene);
    parse_into_scene(scene);
}
