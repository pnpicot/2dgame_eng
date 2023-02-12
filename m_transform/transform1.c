/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

s_transform *get_transform(app_data *adata, char *id)
{
    linked_node *transforms = adata->lists->transforms;

    while (transforms != NULL && transforms->data != NULL) {
        s_transform *cur = (s_transform *) transforms->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        transforms = transforms->next;
    }

    return (NULL);
}

sfVector2f get_transform_pos(s_trfarg arg)
{
    switch (arg.type) {
        case TYPE_BUTTON:
            s_button *button = (s_button *) arg.ref;
            return (sfRectangleShape_getPosition(button->rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) arg.ref;
            return (sfCircleShape_getPosition(circle->elem));
        case TYPE_RECT:
            s_rect *rect = (s_rect *) arg.ref;
            return (sfRectangleShape_getPosition(rect->elem));
        case TYPE_TEXT:
            s_text *text = (s_text *) arg.ref;
            return (sfText_getPosition(text->elem));
        case TYPE_VERTEX:
            s_vertex *vertex = (s_vertex *) arg.ref;
            sfVertex *first_vert = sfVertexArray_getVertex(vertex->elem, 0);
            return (first_vert->position);
    }

    return ((sfVector2f) { 0, 0 });
}

sfVector2f get_transform_scl(s_trfarg arg)
{
    switch (arg.type) {
        case TYPE_BUTTON:
            s_button *button = (s_button *) arg.ref;
            return (sfRectangleShape_getScale(button->rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) arg.ref;
            return (sfCircleShape_getScale(circle->elem));
        case TYPE_RECT:
            s_rect *rect = (s_rect *) arg.ref;
            return (sfRectangleShape_getScale(rect->elem));
        case TYPE_TEXT:
            s_text *text = (s_text *) arg.ref;
            return (sfText_getScale(text->elem));
    }

    return ((sfVector2f) { 1, 1 });
}

float get_transform_rot(s_trfarg arg)
{
    switch (arg.type) {
        case TYPE_BUTTON:
            s_button *button = (s_button *) arg.ref;
            return (sfRectangleShape_getRotation(button->rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) arg.ref;
            return (sfCircleShape_getRotation(circle->elem));
        case TYPE_RECT:
            s_rect *rect = (s_rect *) arg.ref;
            return (sfRectangleShape_getRotation(rect->elem));
        case TYPE_TEXT:
            s_text *text = (s_text *) arg.ref;
            return (sfText_getRotation(text->elem));
    }

    return (0);
}

void translate(app_data *adata, s_trfarg arg)
{
    char *id = str_add("@PV_TRF-", rand_id(16));
    s_transform *transform = get_transform(adata, id);
    if (transform != NULL) {
        char *format = get_msg(adata, "TRANSFORM_ERR_ADD_ID")->format;
        my_printf(format, id);
        return;
    }
    s_transform *new_transform = malloc(sizeof(s_transform));
    init_translate(new_transform, arg, id);
    linked_add(adata->lists->transforms, new_transform);
}
