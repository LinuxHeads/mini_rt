/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:18:56 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/01 03:06:09 by abdsalah         ###   ########.fr       */
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
# include <MLX42.h>

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
    mlx_t *mlx;
    mlx_image_t *image;
    int fd;
} t_scene;


// parsing functions
void        parser(char *filename, t_scene *scene);
t_rgb       parse_color(const char *color, int *error);
int         prase_ambient(char **elements, t_scene *scene);
t_vector    parse_vector(char *vec_string, int *error);
int         parse_camera(char **elements, t_scene *scene);
int         parse_light(char **elements, t_scene *scene);
int         parse_sphere(char **elements, t_scene *scene);
int         parse_plane(char **elements, t_scene *scene);
int         parse_cylinder(char **elements,t_scene *scene);

// input checkers
int         is_valid_float(char *line);
int         is_valid_color(const char *color);


void    init(t_scene *scene);
void    ft_exit_handler(char **message, t_scene *scene, int codes, char **strings);
void    free_split(char **split);
void    check_file_extension(char *filename, t_scene *scene);
void    open_file(char *filename, t_scene *scene);

#endif /* MINIRT_H */