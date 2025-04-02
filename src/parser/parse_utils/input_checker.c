/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:04:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/02 03:34:51 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int count_tokens(char **tokens)
{
    int count = 0;
    while (tokens && tokens[count])
        count++;
    return count;
}
int is_valid_float(const char *str)
{
    int i = 0;
    int dot_count = 0;

    if (!str || !*str)
        return (0);
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!ft_isdigit(str[i]) && str[i] != '.')
        return (0);
    while (str[i])
    {
        if (str[i] == '.')
        {
            dot_count++;
            if (dot_count > 1)
                return (0);
            if ((i == 0 || (i == 1 && (str[0] == '-' || str[0] == '+'))) || str[i + 1] == '\0')
                return (0);
        }
        else if (!ft_isdigit(str[i]) && str[i] != '\n')// yeah i know....
            return (0);
        i++;
    }
    return (1);
}


int    is_valid_color(const char *color)
{
    int		i;
    char	**rgb;

    if (!color)
        return (0);
    rgb = ft_split(color, ',');
    if (!rgb)
        return (0);
    i = 0;
    while (rgb[i])
    {
        if (!is_valid_float(rgb[i]))
        {
            free_split(rgb);
            return (0);
        }
        i++;
    }
    if (i != 3)
    {
        free_split(rgb);
        return (0);
    }
    free_split(rgb);
    return (1);
}
