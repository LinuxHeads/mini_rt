/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:17:33 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/01 03:12:00 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void close_window(void *param)
{
    (void)param;
    printf("Window closed!\n");
}

void init_mlx42(t_scene *scene)
{
    scene->mlx = mlx_init(800, 600, "MLX42 Window", true);
    if (!scene->mlx)
    {
        fprintf(stderr, "MLX42 window creation failed\n");
        free(scene);
        exit(EXIT_FAILURE);
    }
    scene->image = mlx_new_image(scene->mlx, 800, 600);
    if (!scene->image)
    {
        fprintf(stderr, "MLX42 image creation failed\n");
        mlx_terminate(scene->mlx);
        free(scene);
        exit(EXIT_FAILURE);
    }
    // mlx_loop_hook(scene->mlx, close_window, NULL);
    mlx_loop(scene->mlx);
}

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
    init_mlx42(scene);
    mlx_terminate(scene->mlx);
    free(scene);
    return (0);
}