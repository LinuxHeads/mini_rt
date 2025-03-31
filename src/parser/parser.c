/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:47:23 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 21:25:33 by abdsalah         ###   ########.fr       */
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
    // else if (ft_strncmp(elements[0], "cy", 2) == 0)
    //     parse_cylinder(elements, scene);
    else
    {
        free_split(elements);
        return (-1);
    }
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
        ret = parse_line(line, scene);
        free(line);
        if (ret == -1)
        {
            // ft_exit_handler((char **){"Error: Failed to parse line\n", "line:", __LINE__ ,"\nfunction:", __FUNCTION__,"\n",NULL}, scene, 1, NULL);
            free(scene);
        }
    }
    close(scene->fd);
}

void    parser(char *filename, t_scene *scene, char **argv)
{
    
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
    {
        write(2, "Error: Invalid file extension. Use .rt\n", 40);
        free(scene);
    }
    scene->fd = open(filename, O_RDONLY);
    if (scene->fd < 0)
    {
        write(2, "Error: Failed to open file\n", 28);
        free(scene);
    }
    parse_into_scene(scene);

}