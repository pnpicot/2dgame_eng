/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void rotate_circle(app_data *adata, char *id, float angle)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_ID")->format;
        my_printf(format, "rotation", "CIRCLE");
        return;
    }

    sfCircleShape_setRotation(circle->elem, angle);
}

void scale_circle(app_data *adata, char *id, sfVector2f factor)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_ID")->format;
        my_printf(format, "scale", "CIRCLE");
        return;
    }

    sfCircleShape_setScale(circle->elem, factor);
}

void resize_circle_out(app_data *adata, char *id, int thickness)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_ID")->format;
        my_printf(format, "outline thickness", "CIRCLE");
        return;
    }

    sfCircleShape_setOutlineThickness(circle->elem, thickness);
}

void color_circle_out(app_data *adata, char *id, sfColor color)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_ID")->format;
        my_printf(format, "outline color", "CIRCLE");
        return;
    }

    sfCircleShape_setOutlineColor(circle->elem, color);
}

float get_circle_rot(app_data *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_GET_ID")->format;
        my_printf(format, "rotation", "CIRCLE");
        return (0);
    }

    return (sfCircleShape_getRotation(circle->elem));
}
