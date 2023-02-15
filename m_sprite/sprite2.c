/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void resize_sprite(app_data *adata, char *id, sfVector2f size)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_SET_ID")->format;
        my_printf(format, "size", "SPRITE");
        return;
    }

    sfVector2u tx_size = sfTexture_getSize(sprite->tex);
    sfVector2f ratio;

    ratio.x = size.x / tx_size.x;
    ratio.y = size.y / tx_size.y;

    sfSprite_setScale(sprite->elem, ratio);
}

void move_sprite(app_data *adata, char *id, sfVector2f pos)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_SET_ID")->format;
        my_printf(format, "position", "SPRITE");
        return;
    }

    sfSprite_setPosition(sprite->elem, pos);
}

sfVector2f get_sprite_pos(app_data *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_GET_ID")->format;
        my_printf(format, "position", "SPRITE");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfSprite_getPosition(sprite->elem));
}

void translate_sprite(app_data *adata, char *id, sfVector2f pos_ch)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_SET_ID")->format;
        my_printf(format, "position (translate)", "SPRITE");
        return;
    }

    sfVector2f pos = sfSprite_getPosition(sprite->elem);
    pos.x += pos_ch.x;
    pos.y += pos_ch.y;

    sfSprite_setPosition(sprite->elem, pos);
}

void set_sprite_origin(app_data *adata, char *id, sfVector2f origin)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_SET_ID")->format;
        my_printf(format, "origin", "SPRITE");
        return;
    }

    sfSprite_setOrigin(sprite->elem, origin);
}
