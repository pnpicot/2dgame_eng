/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

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
    sfVector2f top_left = { rect.left, rect.top };
    sfVector2f top_right = { rect.left + rect.width, rect.top };
    sfVector2f bottom_left = { rect.left, rect.top + rect.height };
    sfVector2f bottom_right = {  rect.left + rect.width, rect.top + rect.height };

    return (circle_contains(pos, radius, top_left)
            || circle_contains(pos, radius, top_right)
            || circle_contains(pos, radius, bottom_left)
            || circle_contains(pos, radius, bottom_right));
}
