/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void resize_rect_out(app_data *adata, char *id, float thickness)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        char *format = get_msg(adata, "RECT_ERR_SET_ID")->format;
        my_printf(format, "outline thickness", "RECT");
        return;
    }

    sfRectangleShape_setOutlineThickness(rect->elem, thickness);
}

void set_rect_origin(app_data *adata, char *id, sfVector2f origin)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_msg(adata, "RECT_ERR_SET_ID")->format, "origin", "RECT");
        return;
    }

    sfRectangleShape_setOrigin(rect->elem, origin);
}

void rotate_rect(app_data *adata, char *id, float angle)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        char *format = get_msg(adata, "RECT_ERR_SET_ID")->format;
        my_printf(format, "rotation", "RECT");
        return;
    }

    sfRectangleShape_setRotation(rect->elem, angle);
}

sfFloatRect get_rect_bounds(app_data *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_msg(adata, "RECT_ERR_GET_ID")->format, "bounds", "RECT");
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    return (sfRectangleShape_getGlobalBounds(rect->elem));
}

void scale_rect(app_data *adata, char *id, sfVector2f factor)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_msg(adata, "RECT_ERR_SET_ID")->format, "scale", "RECT");
        return;
    }

    sfRectangleShape_setScale(rect->elem, factor);
}
