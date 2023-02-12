/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

sfColor get_color(int r, int g, int b, int a)
{
    return ((sfColor) { r, g, b, a });
}

float get_vdist(sfVector2f from, sfVector2f to)
{
    sfVector2f dist_vec;
    dist_vec.x = to.x - from.x;
    dist_vec.y = to.y - from.y;

    return (sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2)));
}

int circle_contains(sfVector2f pos, float radius, sfVector2f point)
{
    return (get_vdist(pos, point) <= radius);
}

int rect_intersect_circle(sfVector2f pos, float radius, sfFloatRect rect)
{
    sfVector2f tl = { rect.left, rect.top };
    sfVector2f tr = { rect.left + rect.width, rect.top };
    sfVector2f bl = { rect.left, rect.top + rect.height };
    sfVector2f br = { rect.left + rect.width, rect.top + rect.height };

    return (circle_contains(pos, radius, tl)
            || circle_contains(pos, radius, tr)
            || circle_contains(pos, radius, bl)
            || circle_contains(pos, radius, br));
}

int i_rand(int min, int max)
{
    return ((rand() % (max - min + 1)) + min);
}
