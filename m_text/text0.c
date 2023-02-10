/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

sfFloatRect get_text_bounds(app_data *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_GET_ID")->format;
        my_printf(format, "bounds", "TEXT");
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    sfFloatRect bounds = sfText_getGlobalBounds(text->elem);
    bounds.height += sfText_getCharacterSize(text->elem) / 2;

    return (bounds);
}

sfVector2f get_text_origin(app_data *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_GET_ID")->format;
        my_printf(format, "origin", "TEXT");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfText_getOrigin(text->elem));
}

sfVector2f get_text_scale(app_data *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_GET_ID")->format;
        my_printf(format, "scale", "TEXT");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfText_getScale(text->elem));
}

const sfFont *get_text_font(app_data *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_GET_ID")->format;
        my_printf(format, "font", "TEXT");
        return (NULL);
    }

    return (sfText_getFont(text->elem));
}

const char *get_text_string(app_data *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_GET_ID")->format;
        my_printf(format, "string", "TEXT");
        return (NULL);
    }

    return (sfText_getString(text->elem));
}
