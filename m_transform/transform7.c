/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void c_rot_text_next(app_data *adata, s_transform *transform, s_text *text)
{
    sfText_setRotation(text->elem, transform->angle);
    transform->rot = 2;
    sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
        || !transform->trsl) && (transform->scl == 2 || !transform->scl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}

void c_scl_button_next(app_data *adata, s_transform *transform, \
s_button *button)
{
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

void c_scl_circle_next(app_data *adata, s_transform *transform, \
s_circle *circle)
{
    sfCircleShape_setScale(circle->elem, transform->scale);
    transform->scl = 2;
    sfUint8 end = (transform->scl == 2) && (transform->rot == 2
        || !transform->rot) && (transform->trsl == 2 || !transform->trsl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}

void c_scl_rect_next(app_data *adata, s_transform *transform, s_rect *rect)
{
    sfRectangleShape_setScale(rect->elem, transform->scale);
    transform->scl = 2;
    sfUint8 end = (transform->scl == 2) && (transform->rot == 2
        || !transform->rot) && (transform->trsl == 2 || !transform->trsl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}

void c_scl_text_next(app_data *adata, s_transform *transform, s_text *text)
{
    sfText_setScale(text->elem, transform->scale);
    transform->scl = 2;
    sfUint8 end = (transform->scl == 2) && (transform->rot == 2
        || !transform->rot) && (transform->trsl == 2 || !transform->trsl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}
