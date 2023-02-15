/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void rotate_sprite(app_data *adata, char *id, float angle)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_SET_ID")->format;
        my_printf(format, "rotation", "SPRITE");
        return;
    }

    sfSprite_setRotation(sprite->elem, angle);
}

void scale_sprite(app_data *adata, char *id, sfVector2f factor)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_SET_ID")->format;
        my_printf(format, "scale", "SPRITE");
        return;
    }

    sfSprite_setScale(sprite->elem, factor);
}

void set_sprite_active(app_data *adata, char *id, sfUint8 active)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_SET_ID")->format;
        my_printf(format, "active", "SPRITE");
        return;
    }

    sprite->active = active;
}

void set_sprite_texture(app_data *adata, char *id, char *texture_id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_SET_ID")->format;
        my_printf(format, "texture", "SPRITE");
        return;
    }

    s_tex *texture = get_texture(adata, texture_id);

    if (texture == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_TEX_ID")->format;
        my_printf(format, texture_id);
        return;
    }

    sprite->tex = texture->tex;
    sfSprite_setTexture(sprite->elem, texture->tex, sfFalse);
}

sfTexture *get_sprite_tex(app_data *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_GET_ID")->format;
        my_printf(format, "texture", "SPRITE");
        return (NULL);
    }

    return (sprite->tex);
}
