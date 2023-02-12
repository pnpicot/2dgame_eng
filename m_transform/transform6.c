/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void init_transform(s_transform *new_transform, s_trfarg arg, char *id)
{
    new_transform->id = id;
    new_transform->callback = arg.callback;
    new_transform->dest = arg.dest;
    new_transform->scale = arg.scale;
    new_transform->ref = arg.ref;
    new_transform->ref_type = arg.type;
    new_transform->angle = arg.angle;
    new_transform->trsl = 1;
    new_transform->scl = 1;
    new_transform->rot = 1;
    new_transform->trf_type = TRF_ALL;
}

int transform_idcheck(app_data *adata, char *id)
{
    s_transform *transform = get_transform(adata, id);

    if (transform != NULL) {
        char *format = get_msg(adata, "TRANSFORM_ERR_ADD_ID")->format;
        my_printf(format, id);
        return (1);
    }

    return (0);
}

void c_rot_button_next(app_data *adata, s_transform *transform, \
s_button *button)
{
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

void c_rot_circle_next(app_data *adata, s_transform *transform, \
s_circle *circle)
{
    sfCircleShape_setRotation(circle->elem, transform->angle);
    transform->rot = 2;
    sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
        || !transform->trsl) && (transform->scl == 2 || !transform->scl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}

void c_rot_rect_next(app_data *adata, s_transform *transform, \
s_rect *rect)
{
    sfRectangleShape_setRotation(rect->elem, transform->angle);
    transform->rot = 2;
    sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
        || !transform->trsl) && (transform->scl == 2 || !transform->scl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}
