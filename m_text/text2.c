/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void resize_text(app_data *adata, char *id, float font_size)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_ID")->format;
        my_printf(format, "font size", "TEXT");
        return;
    }

    sfText_setCharacterSize(text->elem, font_size);
}

void move_text(app_data *adata, char *id, sfVector2f pos)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_ID")->format;
        my_printf(format, "position", "TEXT");
        return;
    }

    sfText_setPosition(text->elem, pos);
}

sfVector2f get_text_pos(app_data *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_GET_ID")->format;
        my_printf(format, "position", "TEXT");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfText_getPosition(text->elem));
}

void translate_text(app_data *adata, char *id, sfVector2f pos_ch)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_ID")->format;
        my_printf(format, "position (translate)", "TEXT");
        return;
    }

    sfVector2f pos = get_text_pos(adata, id);
    pos.x += pos_ch.x;
    pos.y += pos_ch.y;

    sfText_setPosition(text->elem, pos);
}

void set_text_origin(app_data *adata, char *id, sfVector2f origin)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_ID")->format;
        my_printf(format, "origin", "TEXT");
        return;
    }

    sfText_setOrigin(text->elem, origin);
}
