/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void update_object_text(s_object *object, s_text *text, sfVector2f mouse)
{
    sfFloatRect bounds = sfText_getGlobalBounds(text->elem);
    bounds.left -= object->padding.x;
    bounds.width += object->padding.x * 2;
    bounds.top -= object->padding.y;
    bounds.height += object->padding.y * 2;

    sfUint8 fg_hover = object->properties & obj_fg_hover;

    if (!fg_hover) return;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        sfText_setColor(text->elem, object->fg_on);
    } else {
        sfText_setColor(text->elem, object->fg_off);
    }
}

void update_object_circle(s_object *object, s_circle *circle, sfVector2f mouse)
{
    sfUint8 bg_hover = object->properties & obj_bg_hover;
    sfUint8 out_hover = object->properties & obj_out_hover;
    if (!bg_hover && !out_hover) return;
    float radius = sfCircleShape_getRadius(circle->elem);
    sfVector2f pos = sfCircleShape_getPosition(circle->elem);
    sfVector2f origin = sfCircleShape_getOrigin(circle->elem);
    pos.x += radius - origin.x;
    pos.y += radius - origin.y;
    if (circle_contains(pos, radius + object->padding.x, mouse)) {
        if (bg_hover) sfCircleShape_setFillColor(circle->elem, object->bg_on);
        if (out_hover)
            sfCircleShape_setOutlineColor(circle->elem, object->out_on);
    } else {
        if (bg_hover) sfCircleShape_setFillColor(circle->elem, object->bg_off);
        if (out_hover)
            sfCircleShape_setOutlineColor(circle->elem, object->out_off);
    }
}

void update_s_object(s_object *object, sfVector2f mouse)
{
    switch (object->type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) object->ref;
            update_object_rect(object, rect, mouse);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) object->ref;
            update_object_circle(object, circle, mouse);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) object->ref;
            update_object_text(object, text, mouse);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) object->ref;
            update_object_button(object, button, mouse);
            break;
    }
}

void update_objects(app_data *adata)
{
    linked_node *objects = adata->lists->objects;
    sfVector2i mouse_r = sfMouse_getPositionRenderWindow(adata->win);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(adata->win,
        mouse_r, sfRenderWindow_getView(adata->win));

    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;

        update_s_object(cur, mouse);

        objects = objects->next;
    }
}

void set_object_defn(app_data *adata, s_object *object)
{
    switch (object->type) {
        case TYPE_BUTTON:
            s_button *button = (s_button *) object->ref;
            sfRectangleShape *rect = button->rect->elem;
            object->bg_off = sfRectangleShape_getFillColor(rect);
            object->fg_off = sfText_getColor(button->text->elem);
            object->out_off = sfRectangleShape_getOutlineColor(rect);
            break;
        default:
            char *format = get_msg(adata, "OBJECT_WARN_NO_SUPPORT")->format;
            my_printf(format, object->id);
            break;
    }
}
