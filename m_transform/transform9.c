/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void c_rot_sprite_next(app_data *adata, s_transform *transform, \
s_sprite *sprite)
{
    sfSprite_setRotation(sprite->elem, transform->angle);
    transform->rot = 2;
    sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
        || !transform->trsl) && (transform->scl == 2 || !transform->scl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}

void c_rot_sprite(app_data *adata, s_transform *transform, s_sprite *sprite)
{
    if (transform->rot == 2 || !sprite->active) return;
    float angle = sfSprite_getRotation(sprite->elem);
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
        sfSprite_setRotation(sprite->elem, angle);
    } else {
        c_rot_sprite_next(adata, transform, sprite);
    }
}

void c_scl_sprite_next(app_data *adata, s_transform *transform, \
s_sprite *sprite)
{
    sfSprite_setScale(sprite->elem, transform->scale);
    transform->scl = 2;
    sfUint8 end = (transform->scl == 2) && (transform->rot == 2
        || !transform->rot) && (transform->trsl == 2 || !transform->trsl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}

void c_scl_sprite(app_data *adata, s_transform *transform, s_sprite *sprite)
{
    if (transform->scl == 2 || !sprite->active) return;
    sfVector2f scale = sfSprite_getScale(sprite->elem);
    sfVector2f dist_vec;
    dist_vec.x = transform->scale.x - scale.x;
    dist_vec.y = transform->scale.y - scale.y;
    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));
    if (dist >= transform->s_speed) {
        float speed = transform->s_speed <= dist ?
            transform->s_speed : transform->s_speed - dist;
        scale.x += (speed / dist) * dist_vec.x;
        scale.y += (speed / dist) * dist_vec.y;
        sfSprite_setScale(sprite->elem, scale);
    } else {
        c_scl_sprite_next(adata, transform, sprite);
    }
}

void c_trsl_sprite(app_data *adata, s_transform *transform, s_sprite *sprite)
{
    if (transform->trsl == 2 || !sprite->active) return;
    sfVector2f pos = sfSprite_getPosition(sprite->elem);
    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - pos.x;
    dist_vec.y = transform->dest.y - pos.y;
    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));
    if (dist >= TRANSFORM_TOLERANCE + transform->t_speed) {
        float speed = transform->t_speed <= dist ?
            transform->t_speed : transform->t_speed - dist;
        pos.x += (speed / dist) * dist_vec.x;
        pos.y += (speed / dist) * dist_vec.y;
        sfSprite_setPosition(sprite->elem, pos);
    } else {
        c_trsl_sprite_next(adata, transform, sprite);
    }
}
