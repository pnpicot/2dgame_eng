/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void click_objects(app_data *adata)
{
    linked_node *objects = adata->lists->objects;
    sfVector2i mouse_r = sfMouse_getPositionRenderWindow(adata->win);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(adata->win,
        mouse_r, sfRenderWindow_getView(adata->win));

    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;

        click_s_objects(adata, cur, mouse);

        objects = objects->next;
    }
}

void click_object_sprite(app_data *adata, s_object *object, \
s_sprite *sprite, sfVector2f mouse)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite->elem);
    bounds.left -= object->padding.x;
    bounds.width += object->padding.x * 2;
    bounds.top -= object->padding.y;
    bounds.height += object->padding.y * 2;

    sfUint8 click = object->properties & obj_click;

    if (!click) return;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y))
        (*object->trigger)(adata);
}
