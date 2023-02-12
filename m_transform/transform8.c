/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void c_trsl_button_next(app_data *adata, s_transform *transform, \
s_button *button)
{
    sfRectangleShape_setPosition(button->rect->elem, transform->dest);
    update_button(adata, button);
    transform->trsl = 2;
    sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
        || !transform->rot) && (transform->scl == 2 || !transform->scl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}

void c_trsl_circle_next(app_data *adata, s_transform *transform, \
s_circle *circle)
{
    sfCircleShape_setPosition(circle->elem, transform->dest);
    transform->trsl = 2;
    sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
        || !transform->rot) && (transform->scl == 2 || !transform->scl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}

void c_trsl_rect_next(app_data *adata, s_transform *transform, s_rect *rect)
{
    sfRectangleShape_setPosition(rect->elem, transform->dest);
    transform->trsl = 2;
    sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
        || !transform->rot) && (transform->scl == 2 || !transform->scl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}

void c_trsl_text_next(app_data *adata, s_transform *transform, s_text *text)
{
    transform->trsl = 2;
    sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
        || !transform->rot) && (transform->scl == 2 || !transform->scl);
    sfText_setPosition(text->elem, transform->dest);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}

void c_trsl_vertex_next(app_data *adata, s_transform *transform, \
s_vertex *vertex, float speed)
{
    sfVertex *first_vert = sfVertexArray_getVertex(vertex->elem, 0);
    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - first_vert->position.x;
    dist_vec.y = transform->dest.y - first_vert->position.y;
    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));
    int count = get_vertex_size(adata, vertex->id);
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
