/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

const sfFont *get_button_font(app_data *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_GET_ID")->format;
        my_printf(format, "font", "BUTTON");
        return (NULL);
    }

    return (sfText_getFont(button->text->elem));
}

float get_button_rot(app_data *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_GET_ID")->format;
        my_printf(format, "rotation", "BUTTON");
        return (-1);
    }

    return (sfRectangleShape_getRotation(button->rect->elem));
}

sfFloatRect get_button_bounds(app_data *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_GET_ID")->format;
        my_printf(format, "bounds", "BUTTON");
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    return (sfRectangleShape_getGlobalBounds(button->rect->elem));
}

sfVector2f get_button_origin(app_data *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_GET_ID")->format;
        my_printf(format, "origin", "BUTTON");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfRectangleShape_getOrigin(button->rect->elem));
}

sfVector2f get_button_scale(app_data *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_GET_ID")->format;
        my_printf(format, "scale", "BUTTON");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfRectangleShape_getScale(button->rect->elem));
}
