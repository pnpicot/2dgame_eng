/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void c_trsl_rect(app_data *adata, s_transform *transform, s_rect *rect)
{
    if (transform->trsl == 2) return;

    sfVector2f pos = sfRectangleShape_getPosition(rect->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - pos.x;
    dist_vec.y = transform->dest.y - pos.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= TRANSFORM_TOLERANCE + transform->t_speed) {
        float speed = transform->t_speed <= dist ?
            transform->t_speed : transform->t_speed - dist;

        pos.x += (speed / dist) * dist_vec.x;
        pos.y += (speed / dist) * dist_vec.y;

        sfRectangleShape_setPosition(rect->elem, pos);
    } else {
        sfRectangleShape_setPosition(rect->elem, transform->dest);

        transform->trsl = 2;
        sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void c_trsl_text(app_data *adata, s_transform *transform, s_text *text)
{
    if (transform->trsl == 2) return;

    sfVector2f pos = sfText_getPosition(text->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - pos.x;
    dist_vec.y = transform->dest.y - pos.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= TRANSFORM_TOLERANCE + transform->t_speed) {
        float speed = transform->t_speed <= dist ?
            transform->t_speed : transform->t_speed - dist;

        pos.x += (speed / dist) * dist_vec.x;
        pos.y += (speed / dist) * dist_vec.y;

        sfText_setPosition(text->elem, pos);
    } else {
        transform->trsl = 2;
        sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->scl == 2 || !transform->scl);

        sfText_setPosition(text->elem, transform->dest);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void c_trsl_vertex(app_data *adata, s_transform *transform, s_vertex *vertex)
{
    if (transform->trsl == 2) return;

    sfVertex *first_vert = sfVertexArray_getVertex(vertex->elem, 0);

    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - first_vert->position.x;
    dist_vec.y = transform->dest.y - first_vert->position.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));
    int count = get_vertex_size(adata, vertex->id);
    float speed = transform->t_speed <= dist ?
            transform->t_speed : transform->t_speed - dist;

    if (dist >= TRANSFORM_TOLERANCE + transform->t_speed) {
        for (int i = 0; i < count; i++) {
            sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, i);
            u_vert->position.x += (speed / dist) * dist_vec.x;
            u_vert->position.y += (speed / dist) * dist_vec.y;
        }
    } else {
        for (int i = 0; i < count; i++) {
            sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, i);
            u_vert->position.x += (speed / dist) * dist_vec.x;
            u_vert->position.y += (speed / dist) * dist_vec.y;
        }

        transform->trsl = 2;
        sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void update_translation(app_data *adata, s_transform *transform)
{
    switch (transform->ref_type) {
        case TYPE_BUTTON:
            s_button *button = (s_button *) transform->ref;
            c_trsl_button(adata, transform, button);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) transform->ref;
            c_trsl_circle(adata, transform, circle);
            break;
        case TYPE_RECT:
            s_rect *rect = (s_rect *) transform->ref;
            c_trsl_rect(adata, transform, rect);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) transform->ref;
            c_trsl_text(adata, transform, text);
            break;
    }
    if (transform->ref_type == TYPE_VERTEX)
        c_trsl_vertex(adata, transform, (s_vertex *) transform->ref);
}

void update_rotation(app_data *adata, s_transform *transform)
{
    switch (transform->ref_type) {
        case TYPE_BUTTON:
            s_button *button = (s_button *) transform->ref;
            c_rot_button(adata, transform, button);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) transform->ref;
            c_rot_circle(adata, transform, circle);
            break;
        case TYPE_RECT:
            s_rect *rect = (s_rect *) transform->ref;
            c_rot_rect(adata, transform, rect);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) transform->ref;
            c_rot_text(adata, transform, text);
            break;
    }
}
