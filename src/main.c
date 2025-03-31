/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:17:33 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 22:39:38 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
    t_scene *scene;
    
    if (argc != 2)
    {
        write(2, "Usage: ./mini_rt scene.rt\n", 27);
        return (1);
    }
    scene = malloc(sizeof(t_scene));
    if (!scene)
    {
        write(2, "Error: Memory allocation failed\n", 33);
        return (1);
    }
    init(scene);
    parser(argv[1], scene);
    
}