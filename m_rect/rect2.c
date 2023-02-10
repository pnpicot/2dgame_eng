/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

sfVector2f get_rect_pos(app_data *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        char *format = get_msg(adata, "RECT_ERR_GET_ID")->format;
        my_printf(format, "position", "RECT");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfRectangleShape_getPosition(rect->elem));
}

float get_rect_rot(app_data *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        char *format = get_msg(adata, "RECT_ERR_GET_ID")->format;
        my_printf(format, "rotation", "RECT");
        return (0);
    }

    return (sfRectangleShape_getRotation(rect->elem));
}

sfVector2f get_rect_origin(app_data *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_msg(adata, "RECT_ERR_GET_ID")->format, "origin", "RECT");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfRectangleShape_getOrigin(rect->elem));
}

void translate_rect(app_data *adata, char *id, sfVector2f pos_ch)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        char *format = get_msg(adata, "RECT_ERR_SET_ID")->format;
        my_printf(format, "position (translate)", "RECT");
        return;
    }

    sfVector2f pos = get_rect_pos(adata, id);
    pos.x += pos_ch.x;
    pos.y += pos_ch.y;

    sfRectangleShape_setPosition(rect->elem, pos);
}

void color_rect_out(app_data *adata, char *id, sfColor color)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        char *format = get_msg(adata, "RECT_ERR_SET_ID")->format;
        my_printf(format, "outline color", "RECT");
        return;
    }

    sfRectangleShape_setOutlineColor(rect->elem, color);
}
