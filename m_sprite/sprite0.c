/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

float get_sprite_rot(app_data *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_GET_ID")->format;
        my_printf(format, "rotation", "SPRITE");
        return (-1);
    }

    return (sfSprite_getRotation(sprite->elem));
}

sfVector2f get_sprite_origin(app_data *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_GET_ID")->format;
        my_printf(format, "origin", "SPRITE");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfSprite_getOrigin(sprite->elem));
}

sfVector2f get_sprite_scale(app_data *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_GET_ID")->format;
        my_printf(format, "scale", "SPRITE");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfSprite_getScale(sprite->elem));
}
