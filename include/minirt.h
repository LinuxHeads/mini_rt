/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:18:56 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 19:43:06 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct s_rgb
{
    __uint8_t r;
    __uint8_t g;
    __uint8_t b;
} t_rgb;


typedef struct s_amb_light
{
    float ratio;
    t_rgb color;
} t_amb_light;

typedef struct s_vector
{
    double x;
    double y;
    double z;
} t_vector;

typedef struct s_camera
{
    t_vector pos;
    float fov;
    t_vector norm_3d;
    
} t_camera;

typedef struct s_light
{
    t_vector pos;
    double brightness;
    t_rgb color;
} t_light;

typedef struct s_plane
{
    t_vector pos;
    t_vector norm_3d;
    t_rgb color;
} t_plane;

typedef struct s_sphere
{
    t_vector pos;
    double diameter;
    t_rgb color;
} t_sphere;

typedef struct s_cylinder
{
    t_vector pos;
    double diameter;
    double height;
    t_vector norm_3d;
    t_rgb color;
} t_cylinder;


typedef struct s_scene
{
    t_amb_light amb_light;
    t_camera camera;
    t_light light;
    t_plane plane;
    t_sphere sphere;
    t_cylinder cylinder;
    int fd;
} t_scene;


void parser(char *filename, t_scene *scene, char **argv);
int is_valid_input(char *line);
t_rgb    parse_color(const char *color, int *error);
void    ft_exit_handler(char **message, t_scene *scene, int codes, char **strings);
int prase_ambient(char **elements, t_scene *scene);
void  free_split(char **split);
int    is_valid_color(const char *color);
t_vector parse_vector(char *vec_string, int *error);
int parse_camera(char **elements, t_scene *scene);
void    init(t_scene *scene);
#endif /* MINIRT_H */