/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void update_scaling(app_data *adata, s_transform *transform)
{
    switch (transform->ref_type) {
        case TYPE_BUTTON:
            s_button *button = (s_button *) transform->ref;
            c_scl_button(adata, transform, button);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) transform->ref;
            c_scl_circle(adata, transform, circle);
            break;
        case TYPE_RECT:
            s_rect *rect = (s_rect *) transform->ref;
            c_scl_rect(adata, transform, rect);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) transform->ref;
            c_scl_text(adata, transform, text);
            break;
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) transform->ref;
            c_scl_sprite(adata, transform, sprite);
            break;
    }
}

void update_transforms(app_data *adata)
{
    linked_node *transforms = adata->lists->transforms;
    while (transforms != NULL && transforms->data != NULL) {
        s_transform *cur = (s_transform *) transforms->data;
        switch (cur->trf_type) {
            case TRF_TRANSLATE:
                update_translation(adata, cur);
                break;
            case TRF_ROTATE:
                update_rotation(adata, cur);
                break;
            case TRF_SCALE:
                update_scaling(adata, cur);
                break;
            case TRF_ALL:
                update_translation(adata, cur);
                update_rotation(adata, cur);
                update_scaling(adata, cur);
        }
        transforms = transforms->next;
    }
}

void init_translate(s_transform *new_transform, s_trfarg arg, char *id)
{
    new_transform->id = id;
    new_transform->callback = arg.callback;
    new_transform->dest = arg.dest;
    new_transform->scale = (sfVector2f) { 0, 0 };
    new_transform->ref = arg.ref;
    new_transform->ref_type = arg.type;
    new_transform->t_speed = arg.t_speed;
    new_transform->s_speed = 0;
    new_transform->r_speed = 0;
    new_transform->angle = 0;
    new_transform->trsl = 1;
    new_transform->scl = 0;
    new_transform->rot = 0;
    new_transform->trf_type = TRF_TRANSLATE;
}

void init_rotate(s_transform *new_transform, s_trfarg arg, char *id)
{
    new_transform->id = id;
    new_transform->callback = arg.callback;
    new_transform->dest = (sfVector2f) { 0, 0 };
    new_transform->scale = (sfVector2f) { 0, 0 };
    new_transform->ref = arg.ref;
    new_transform->ref_type = arg.type;
    new_transform->r_speed = arg.r_speed;
    new_transform->t_speed = 0;
    new_transform->s_speed = 0;
    new_transform->angle = arg.angle;
    new_transform->trsl = 0;
    new_transform->scl = 0;
    new_transform->rot = 1;
    new_transform->trf_type = TRF_ROTATE;
}

void init_scale(s_transform *new_transform, s_trfarg arg, char *id)
{
    new_transform->id = id;
    new_transform->callback = arg.callback;
    new_transform->dest = (sfVector2f) { 0, 0 };
    new_transform->scale = arg.scale;
    new_transform->ref = arg.ref;
    new_transform->ref_type = arg.type;
    new_transform->s_speed = arg.s_speed;
    new_transform->t_speed = 0;
    new_transform->r_speed = 0;
    new_transform->angle = 0;
    new_transform->trsl = 0;
    new_transform->scl = 1;
    new_transform->rot = 0;
    new_transform->trf_type = TRF_SCALE;
}
