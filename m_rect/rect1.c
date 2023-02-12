/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

s_rect *get_rect(app_data *adata, char *id)
{
    linked_node *rects = adata->lists->rects;

    while (rects != NULL && rects->data != NULL) {
        s_rect *cur = (s_rect *) rects->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        rects = rects->next;
    }

    return (NULL);
}

void add_rect(app_data *adata, char *id, int layer)
{
    s_rect *rect = get_rect(adata, id);

    if (rect != NULL) {
        my_printf(get_msg(adata, "RECT_ERR_ADD_ID")->format, "RECT", id);
        return;
    }

    s_rect *new_rect = malloc(sizeof(s_rect));
    new_rect->elem = sfRectangleShape_create();
    new_rect->id = id;
    new_rect->layer = layer;
    new_rect->rtex_id = NULL;
    new_rect->type = TYPE_RECT;
    new_rect->active = 1;

    if (layer < adata->min_layer) adata->min_layer = layer;
    if (layer > adata->max_layer) adata->max_layer = layer;

    linked_add(adata->lists->rects, new_rect);
}

void color_rect(app_data *adata, char *id, sfColor color)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        char *format = get_msg(adata, "RECT_ERR_SET_ID")->format;
        my_printf(format, "fill color", "RECT");
        return;
    }

    sfRectangleShape_setFillColor(rect->elem, color);
}

void resize_rect(app_data *adata, char *id, sfVector2f size)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_msg(adata, "RECT_ERR_SET_ID")->format, "size", "RECT");
        return;
    }

    sfRectangleShape_setSize(rect->elem, size);
}

void move_rect(app_data *adata, char *id, sfVector2f pos)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        char *format = get_msg(adata, "RECT_ERR_SET_ID")->format;
        my_printf(format, "position (move)", "RECT");
        return;
    }

    sfRectangleShape_setPosition(rect->elem, pos);
}
