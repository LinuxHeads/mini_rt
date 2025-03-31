/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:56:30 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 19:22:00 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void  free_split(char **split)
{
    int i;

    if (!split)
        return ;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void    print_message(char **message)
{
    int i;

    if (!message)
        return ;
    i = 0;
    while (message[i])
    {
        write(2, message[i], ft_strlen(message[i]));
        i++;
    }
}

void   ft_exit_handler(char **message, t_scene *scene, int codes, char **strings)
{
    if (scene)
    {
        if (scene->fd > 0)
            close(scene->fd);
        free(scene);
    }
    if (strings)
        printf("hi\n");
        // free_split(strings);
    if (message)
        print_message(message);
    exit(codes & 1);
}