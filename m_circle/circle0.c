/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

sfFloatRect get_circle_bounds(app_data *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_GET_ID")->format;
        my_printf(format, "bounds", "CIRCLE");
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    return (sfCircleShape_getGlobalBounds(circle->elem));
}

sfVector2f get_circle_origin(app_data *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_GET_ID")->format;
        my_printf(format, "origin", "CIRCLE");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfCircleShape_getOrigin(circle->elem));
}

sfVector2f get_circle_scale(app_data *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_GET_ID")->format;
        my_printf(format, "scale", "CIRCLE");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfCircleShape_getScale(circle->elem));
}

void set_circle_active(app_data *adata, char *id, sfUint8 active)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_ID")->format;
        my_printf(format, "active", "CIRCLE");
        return;
    }

    circle->active = active;
}
