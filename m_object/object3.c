/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void disable_object_out(app_data *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_DISABLE_ID")->format;
        my_printf(format, "outline hover color", "OBJECT");
        return;
    }

    object->properties &= ~obj_out_hover;
}

void set_object_out(app_data *adata, char *id, sfColor color)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_SET_ID")->format;
        my_printf(format, "outline hover color", "OBJECT");
        return;
    }

    object->properties |= obj_out_hover;
    object->out_on = color;
}

void resize_object(app_data *adata, char *id, sfVector2f padding)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_SET_ID")->format;
        my_printf(format, "event area padding", "OBJECT");
        return;
    }

    object->padding = padding;
}

void update_object_rect(s_object *object, s_rect *rect, sfVector2f mouse)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(rect->elem);
    bounds.left -= object->padding.x;
    bounds.width += object->padding.x * 2;
    bounds.top -= object->padding.y;
    bounds.height += object->padding.y * 2;

    sfUint8 bg_hover = object->properties & obj_bg_hover;
    sfUint8 out_hover = object->properties & obj_out_hover;

    if (!bg_hover && !out_hover) return;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (bg_hover) sfRectangleShape_setFillColor(rect->elem, object->bg_on);
        if (out_hover) sfRectangleShape_setOutlineColor(rect->elem, object->out_on);
    } else {
        if (bg_hover) sfRectangleShape_setFillColor(rect->elem, object->bg_off);
        if (out_hover) sfRectangleShape_setOutlineColor(rect->elem, object->out_off);
    }
}

void update_object_button(s_object *object, s_button *button, sfVector2f mouse)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->rect->elem);
    bounds.left -= object->padding.x;
    bounds.width += object->padding.x * 2;
    bounds.top -= object->padding.y;
    bounds.height += object->padding.y * 2;

    sfUint8 bg_hover = object->properties & obj_bg_hover;
    sfUint8 fg_hover = object->properties & obj_fg_hover;
    sfUint8 out_hover = object->properties & obj_out_hover;

    if (!bg_hover && !fg_hover && !out_hover) return;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (bg_hover) sfRectangleShape_setFillColor(button->rect->elem, object->bg_on);
        if (fg_hover) sfText_setColor(button->text->elem, object->fg_on);
        if (out_hover) sfRectangleShape_setOutlineColor(button->rect->elem, object->out_on);
    } else {
        if (bg_hover) sfRectangleShape_setFillColor(button->rect->elem, object->bg_off);
        if (fg_hover) sfText_setColor(button->text->elem, object->fg_off);
        if (out_hover) sfRectangleShape_setOutlineColor(button->rect->elem, object->out_off);
    }
}
