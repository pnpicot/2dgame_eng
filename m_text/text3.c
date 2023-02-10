/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void rotate_text(app_data *adata, char *id, float angle)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_ID")->format;
        my_printf(format, "rotation", "TEXT");
        return;
    }

    sfText_setRotation(text->elem, angle);
}

void scale_text(app_data *adata, char *id, sfVector2f factor)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_ID")->format;
        my_printf(format, "scale", "TEXT");
        return;
    }

    sfText_setScale(text->elem, factor);
}

void edit_text(app_data *adata, char *id, char *str)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_ID")->format;
        my_printf(format, "string", "TEXT");
        return;
    }

    sfText_setString(text->elem, str);
}

void set_text_font(app_data *adata, char *id, sfFont *font)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_ID")->format;
        my_printf(format, "font", "TEXT");
        return;
    }

    sfText_setFont(text->elem, font);
}

float get_text_rot(app_data *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_GET_ID")->format;
        my_printf(format, "rotation", "TEXT");
        return (-1);
    }

    return (sfText_getRotation(text->elem));
}
