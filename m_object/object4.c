/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void click_object_button(app_data *adata, s_object *object, s_button *button, sfVector2f mouse)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->rect->elem);
    bounds.left -= object->padding.x;
    bounds.width += object->padding.x * 2;
    bounds.top -= object->padding.y;
    bounds.height += object->padding.y * 2;

    sfUint8 click = object->properties & obj_click;

    if (!click) return;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y))
        (*object->trigger)(adata);
}

void click_object_text(app_data *adata, s_object *object, s_text *text, sfVector2f mouse)
{
    sfFloatRect bounds = sfText_getGlobalBounds(text->elem);
    bounds.left -= object->padding.x;
    bounds.width += object->padding.x * 2;
    bounds.top -= object->padding.y;
    bounds.height += object->padding.y * 2;

    sfUint8 click = object->properties & obj_click;

    if (!click) return;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y))
        (*object->trigger)(adata);
}

void click_object_rect(app_data *adata, s_object *object, s_rect *rect, sfVector2f mouse)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(rect->elem);
    bounds.left -= object->padding.x;
    bounds.width += object->padding.x * 2;
    bounds.top -= object->padding.y;
    bounds.height += object->padding.y * 2;

    sfUint8 click = object->properties & obj_click;

    if (!click) return;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y))
        (*object->trigger)(adata);
}

void click_object_circle(app_data *adata, s_object *object, s_circle *circle, sfVector2f mouse)
{
    sfUint8 click = object->properties & obj_click;

    if (!click) return;

    float radius = sfCircleShape_getRadius(circle->elem);
    sfVector2f pos = sfCircleShape_getPosition(circle->elem);
    sfVector2f origin = sfCircleShape_getOrigin(circle->elem);

    pos.x += radius - origin.x;
    pos.y += radius - origin.y;

    if (circle_contains(pos, radius + object->padding.x, mouse))
        (*object->trigger)(adata);
}

void click_s_objects(app_data *adata, s_object *object, sfVector2f mouse)
{
    switch (object->type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) object->ref;
            click_object_rect(adata, object, rect, mouse);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) object->ref;
            click_object_circle(adata, object, circle, mouse);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) object->ref;
            click_object_text(adata, object, text, mouse);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) object->ref;
            click_object_button(adata, object, button, mouse);
            break;
    }
}
