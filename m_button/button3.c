/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

sfVector2f get_button_pos(app_data *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_GET_ID")->format;
        my_printf(format, "position", "BUTTON");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfRectangleShape_getPosition(button->rect->elem));
}

void translate_button(app_data *adata, char *id, sfVector2f pos_ch)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "position (translate)", "BUTTON");
        return;
    }

    sfVector2f pos = sfRectangleShape_getPosition(button->rect->elem);
    pos.x += pos_ch.x;
    pos.y += pos_ch.y;

    sfRectangleShape_setPosition(button->rect->elem, pos);
    update_button(adata, button);
}

void set_button_origin(app_data *adata, char *id, sfVector2f origin)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "origin", "BUTTON");
        return;
    }

    sfRectangleShape_setOrigin(button->rect->elem, origin);
    update_button(adata, button);
}

void rotate_button(app_data *adata, char *id, float angle)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "rotation", "BUTTON");
        return;
    }

    sfRectangleShape_setRotation(button->rect->elem, angle);
    sfText_setRotation(button->text->elem, angle);
    update_button(adata, button);
}

void scale_button(app_data *adata, char *id, sfVector2f factor)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "scale", "BUTTON");
        return;
    }

    sfRectangleShape_setScale(button->rect->elem, factor);
    sfText_setScale(button->text->elem, factor);
    update_button(adata, button);
}
