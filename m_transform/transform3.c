/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void c_rot_button(app_data *adata, s_transform *transform, s_button *button)
{
    if (transform->rot == 2) return;

    float angle = sfRectangleShape_getRotation(button->rect->elem);
    float speed = transform->r_speed;
    float diff = transform->angle - angle;

    if (diff < 0) diff *= -1;

    if (diff >= TRANSFORM_TOLERANCE + transform->r_speed) {
        speed = speed <= diff ? speed : speed - diff;

        if (angle > transform->angle) {
            angle -= speed;
        } else {
            angle += speed;
        }

        sfRectangleShape_setRotation(button->rect->elem, angle);
        sfText_setRotation(button->text->elem, angle);
        update_button(adata, button);
    } else {
        sfRectangleShape_setRotation(button->rect->elem, transform->angle);
        sfText_setRotation(button->text->elem, transform->angle);
        update_button(adata, button);

        transform->rot = 2;
        sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
            || !transform->trsl) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void c_rot_circle(app_data *adata, s_transform *transform, s_circle *circle)
{
    if (transform->rot == 2) return;

    float angle = sfCircleShape_getRotation(circle->elem);
    float speed = transform->r_speed;
    float diff = transform->angle - angle;

    if (diff < 0) diff *= -1;

    if (diff >= TRANSFORM_TOLERANCE + transform->r_speed) {
        speed = speed <= diff ? speed : speed - diff;

        if (angle > transform->angle) {
            angle -= speed;
        } else {
            angle += speed;
        }

        sfCircleShape_setRotation(circle->elem, angle);
    } else {
        sfCircleShape_setRotation(circle->elem, transform->angle);

        transform->rot = 2;
        sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
            || !transform->trsl) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void c_rot_rect(app_data *adata, s_transform *transform, s_rect *rect)
{
    if (transform->rot == 2) return;

    float angle = sfRectangleShape_getRotation(rect->elem);
    float speed = transform->r_speed;
    float diff = transform->angle - angle;

    if (diff < 0) diff *= -1;

    if (diff >= TRANSFORM_TOLERANCE + transform->r_speed) {
        speed = speed <= diff ? speed : speed - diff;

        if (angle > transform->angle) {
            angle -= speed;
        } else {
            angle += speed;
        }

        sfRectangleShape_setRotation(rect->elem, angle);
    } else {
        sfRectangleShape_setRotation(rect->elem, transform->angle);

        transform->rot = 2;
        sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
            || !transform->trsl) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void c_rot_text(app_data *adata, s_transform *transform, s_text *text)
{
    if (transform->rot == 2) return;

    float angle = sfText_getRotation(text->elem);
    float speed = transform->r_speed;
    float diff = transform->angle - angle;

    if (diff < 0) diff *= -1;

    if (diff >= TRANSFORM_TOLERANCE + transform->r_speed) {
        speed = speed <= diff ? speed : speed - diff;

        if (angle > transform->angle) {
            angle -= speed;
        } else {
            angle += speed;
        }

        sfText_setRotation(text->elem, angle);
    } else {
        sfText_setRotation(text->elem, transform->angle);

        transform->rot = 2;
        sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
            || !transform->trsl) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}

void c_scl_button(app_data *adata, s_transform *transform, s_button *button)
{
    if (transform->scl == 2) return;

    sfVector2f scale = sfRectangleShape_getScale(button->rect->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->scale.x - scale.x;
    dist_vec.y = transform->scale.y - scale.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= transform->s_speed) {
        float speed = transform->s_speed <= dist ?
            transform->s_speed : transform->s_speed - dist;

        scale.x += (speed / dist) * dist_vec.x;
        scale.y += (speed / dist) * dist_vec.y;

        sfRectangleShape_setScale(button->rect->elem, scale);
        sfText_setScale(button->text->elem, scale);
        update_button(adata, button);
    } else {
        sfRectangleShape_setScale(button->rect->elem, transform->scale);
        sfText_setScale(button->text->elem, transform->scale);
        update_button(adata, button);

        transform->scl = 2;
        sfUint8 end = (transform->scl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->trsl == 2 || !transform->trsl);

        if (end) delete_transform(adata, transform->id);
        if (transform->callback != NULL && end)
            (*transform->callback)(adata, copy_transform(transform));
    }
}
