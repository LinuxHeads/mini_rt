/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:51:14 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/02 03:41:08 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    check_file_extension(char *filename, t_scene *scene)
{
    int len;

    len = ft_strlen(filename);
    if (len < 3 || ft_strncmp(filename + len - 3, ".rt", 3) != 0)
    {
        write(2, "Error: Invalid file extension. Use .rt\n", 40);
        free(scene);
        exit(1);
    }
}

void    open_file(char *filename, t_scene *scene)
{
    scene->fd = open(filename, O_RDONLY);
    if (scene->fd < 0)
    {
        write(2, "Error: Failed to open file\n", 28);
        free(scene);
        exit(1);
    }
}

void    close_file(t_scene *scene)
{
    if (scene->fd >= 0)
    {
        close(scene->fd);
        scene->fd = -1;
    }
}
