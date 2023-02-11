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
    sfVector2f mouse =  sfRenderWindow_mapPixelToCoords(adata->win,
                        mouse_r, sfRenderWindow_getView(adata->win));

    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;

        click_s_objects(adata, cur, mouse);

        objects = objects->next;
    }
}
