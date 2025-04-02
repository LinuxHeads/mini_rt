/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:47:23 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/02 03:42:28 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     parse_line(char *line, t_scene *scene)
{
    char **elements;
    int code = 1;
    
    if (line[0] == '\0')
        return (0);
    elements = ft_split(line, ' ');
    if (!elements)
         code = -1;
    if (ft_strncmp(elements[0], "A", 1) == 0)
         code = parse_ambient(elements, scene);
    else if (ft_strncmp(elements[0], "C", 1) == 0)
         code = parse_camera(elements, scene);
    else if (ft_strncmp(elements[0], "L", 1) == 0)
         code = parse_light(elements, scene);
    else if (ft_strncmp(elements[0], "sp", 2) == 0)
         code = parse_sphere(elements, scene);
    else if (ft_strncmp(elements[0], "pl", 2) == 0)
         code = parse_plane(elements, scene);
    else if (ft_strncmp(elements[0], "cy", 2) == 0)
         code = parse_cylinder(elements, scene);
    else
    {
        free_split(elements);
        return (0);
    }
    free_split(elements);
    return (code);
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
        if (!ret)
        {
            close_file(scene);
            free(scene);
            exit(1);// not good
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
