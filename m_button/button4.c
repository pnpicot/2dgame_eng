/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void resize_button_out(app_data *adata, char *id, int thickness)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "outline thickness", "BUTTON");
        return;
    }

    sfRectangleShape_setOutlineThickness(button->rect->elem, thickness);
}

void color_button_out(app_data *adata, char *id, sfColor color)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "outline color", "BUTTON");
        return;
    }

    sfRectangleShape_setOutlineColor(button->rect->elem, color);
}

void edit_button(app_data *adata, char *id, char *str)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "string", "BUTTON");
        return;
    }

    sfText_setString(button->text->elem, str);
    update_button(adata, button);
}

void set_button_font(app_data *adata, char *id, sfFont *font)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "font", "BUTTON");
        return;
    }

    sfText_setFont(button->text->elem, font);
    update_button(adata, button);
}

const char *get_button_string(app_data *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_GET_ID")->format;
        my_printf(format, "string", "BUTTON");
        return (NULL);
    }

    return (sfText_getString(button->text->elem));
}
