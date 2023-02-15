/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void c_trsl_sprite_next(app_data *adata, s_transform *transform, s_sprite *sprite)
{
    sfSprite_setPosition(sprite->elem, transform->dest);
    transform->trsl = 2;
    sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
        || !transform->rot) && (transform->scl == 2 || !transform->scl);
    if (end) delete_transform(adata, transform->id);
    if (transform->callback != NULL && end)
        (*transform->callback)(adata, copy_transform(transform));
}
