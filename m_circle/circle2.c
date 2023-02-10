/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void resize_circle(app_data *adata, char *id, float radius)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_ID")->format;
        my_printf(format, "radius", "CIRCLE");
        return;
    }

    sfCircleShape_setRadius(circle->elem, radius);
}

void move_circle(app_data *adata, char *id, sfVector2f pos)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_ID")->format;
        my_printf(format, "position", "CIRCLE");
        return;
    }

    sfCircleShape_setPosition(circle->elem, pos);
}

sfVector2f get_circle_pos(app_data *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_GET_ID")->format;
        my_printf("format", "position", "CIRCLE");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfCircleShape_getPosition(circle->elem));
}

void translate_circle(app_data *adata, char *id, sfVector2f pos_ch)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_ID")->format;
        my_printf(format, "position (translate)", "CIRCLE");
        return;
    }

    sfVector2f pos = get_circle_pos(adata, id);
    pos.x += pos_ch.x;
    pos.y += pos_ch.y;

    sfCircleShape_setPosition(circle->elem, pos);
}

void set_circle_origin(app_data *adata, char *id, sfVector2f origin)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_ID")->format;
        my_printf(format, "origin", "CIRCLE");
        return;
    }

    sfCircleShape_setOrigin(circle->elem, origin);
}
