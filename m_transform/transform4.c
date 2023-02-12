/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void c_scl_circle(app_data *adata, s_transform *transform, s_circle *circle)
{
    if (transform->scl == 2) return;

    sfVector2f scale = sfCircleShape_getScale(circle->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->scale.x - scale.x;
    dist_vec.y = transform->scale.y - scale.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= transform->s_speed) {
        float speed = transform->s_speed <= dist ?
            transform->s_speed : transform->s_speed - dist;

        scale.x += (speed / dist) * dist_vec.x;
        scale.y += (speed / dist) * dist_vec.y;

        sfCircleShape_setScale(circle->elem, scale);
    } else {
        sfCircleShape_setScale(circle->elem, transform->scale);

        transform->scl = 2;
        sfUint8 end = (transform->scl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->trsl == 2 || !transform->trsl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void c_scl_rect(app_data *adata, s_transform *transform, s_rect *rect)
{
    if (transform->scl == 2) return;

    sfVector2f scale = sfRectangleShape_getScale(rect->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->scale.x - scale.x;
    dist_vec.y = transform->scale.y - scale.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= transform->s_speed) {
        float speed = transform->s_speed <= dist ?
            transform->s_speed : transform->s_speed - dist;

        scale.x += (speed / dist) * dist_vec.x;
        scale.y += (speed / dist) * dist_vec.y;

        sfRectangleShape_setScale(rect->elem, scale);
    } else {
        sfRectangleShape_setScale(rect->elem, transform->scale);

        transform->scl = 2;
        sfUint8 end = (transform->scl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->trsl == 2 || !transform->trsl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void c_scl_text(app_data *adata, s_transform *transform, s_text *text)
{
    if (transform->scl == 2) return;

    sfVector2f scale = sfText_getScale(text->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->scale.x - scale.x;
    dist_vec.y = transform->scale.y - scale.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= transform->s_speed) {
        float speed = transform->s_speed <= dist ?
            transform->s_speed : transform->s_speed - dist;

        scale.x += (speed / dist) * dist_vec.x;
        scale.y += (speed / dist) * dist_vec.y;

        sfText_setScale(text->elem, scale);
    } else {
        sfText_setScale(text->elem, transform->scale);

        transform->scl = 2;
        sfUint8 end = (transform->scl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->trsl == 2 || !transform->trsl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void c_trsl_button(app_data *adata, s_transform *transform, s_button *button)
{
    if (transform->trsl == 2) return;

    sfVector2f pos = sfRectangleShape_getPosition(button->rect->elem);
    sfVector2f scale = sfRectangleShape_getScale(button->rect->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - pos.x;
    dist_vec.y = transform->dest.y - pos.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= (TRANSFORM_TOLERANCE + transform->t_speed) * 5) {
        float speed = transform->t_speed <= dist ?
            transform->t_speed : transform->t_speed - dist;

        pos.x += (speed / dist) * dist_vec.x;
        pos.y += (speed / dist) * dist_vec.y;

        sfRectangleShape_setPosition(button->rect->elem, pos);
        update_button(adata, button);
    } else {
        sfRectangleShape_setPosition(button->rect->elem, transform->dest);
        update_button(adata, button);

        transform->trsl = 2;
        sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void c_trsl_circle(app_data *adata, s_transform *transform, s_circle *circle)
{
    if (transform->trsl == 2) return;

    sfVector2f pos = sfCircleShape_getPosition(circle->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - pos.x;
    dist_vec.y = transform->dest.y - pos.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= TRANSFORM_TOLERANCE + transform->t_speed) {
        float speed = transform->t_speed <= dist ?
            transform->t_speed : transform->t_speed - dist;

        pos.x += (speed / dist) * dist_vec.x;
        pos.y += (speed / dist) * dist_vec.y;

        sfCircleShape_setPosition(circle->elem, pos);
    } else {
        sfCircleShape_setPosition(circle->elem, transform->dest);

        transform->trsl = 2;
        sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}
