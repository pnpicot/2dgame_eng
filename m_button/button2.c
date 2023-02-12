/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void color_button_fg(app_data *adata, char *id, sfColor color)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "foreground color", "BUTTON");
        return;
    }

    sfText_setColor(button->text->elem, color);
}

void update_button(app_data *adata, s_button *button)
{
    sfVector2f scale = sfText_getScale(button->text->elem);
    sfFloatRect rect_bounds = get_rect_bounds(adata, button->rect->id);
    float o_angle = sfText_getRotation(button->text->elem);

    sfText_setRotation(button->text->elem, 0);
    sfText_setScale(button->text->elem, (sfVector2f) { 1, 1 });

    sfFloatRect text_bounds = get_text_bounds(adata, button->text->id);

    sfText_setOrigin(button->text->elem,
        (sfVector2f) { text_bounds.width / 2, text_bounds.height / 2 });
    sfText_setRotation(button->text->elem, o_angle);
    sfText_setScale(button->text->elem, scale);

    sfVector2f new_text_pos;
    new_text_pos.x = rect_bounds.left + (rect_bounds.width / 2);
    new_text_pos.y = rect_bounds.top + (rect_bounds.height / 2);

    sfText_setPosition(button->text->elem, new_text_pos);
}

void resize_button_text(app_data *adata, char *id, float font_size)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "text font size", "BUTTON");
        return;
    }

    sfText_setCharacterSize(button->text->elem, font_size);
    update_button(adata, button);
}

void resize_button(app_data *adata, char *id, sfVector2f size)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "size", "BUTTON");
        return;
    }

    sfRectangleShape_setSize(button->rect->elem, size);
    update_button(adata, button);
}

void move_button(app_data *adata, char *id, sfVector2f pos)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "position", "BUTTON");
        return;
    }

    sfRectangleShape_setPosition(button->rect->elem, pos);
    update_button(adata, button);
}
