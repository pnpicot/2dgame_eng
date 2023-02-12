/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void c_rot_button(app_data *adata, s_transform *transform, s_button *button)
{
    if (transform->rot == 2 || !button->rect->active) return;
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
        c_rot_button_next(adata, transform, button);
    }
}

void c_rot_circle(app_data *adata, s_transform *transform, s_circle *circle)
{
    if (transform->rot == 2 || !circle->active) return;
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
        c_rot_circle_next(adata, transform, circle);
    }
}

void c_rot_rect(app_data *adata, s_transform *transform, s_rect *rect)
{
    if (transform->rot == 2 || !rect->active) return;
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
        c_rot_rect_next(adata, transform, rect);
    }
}

void c_rot_text(app_data *adata, s_transform *transform, s_text *text)
{
    if (transform->rot == 2 || !text->active) return;
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
        c_rot_text_next(adata, transform, text);
    }
}

void c_scl_button(app_data *adata, s_transform *transform, s_button *button)
{
    if (transform->scl == 2 || !button->rect->active) return;
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
        c_scl_button_next(adata, transform, button);
    }
}
