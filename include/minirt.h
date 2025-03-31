/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:18:56 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 05:54:14 by abdsalah         ###   ########.fr       */
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
    double x;
    double y;
    double z;
    float fov;
    t_vector vec;
    
} t_camera;

typedef struct s_light
{
    double x;
    double y;
    double z;
    double brightness;
    t_rgb color;
} t_light;

typedef struct s_plane
{
    double x;
    double y;
    double z;
    t_vector vec;
    t_rgb color;
} t_plane;

typedef struct s_sphere
{
    double x;
    double y;
    double z;
    double diameter;
    t_rgb color;
} t_sphere;

typedef struct s_cylinder
{
    double x;
    double y;
    double z;
    double diameter;
    double height;
    t_vector vec;
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
#endif /* MINIRT_H */