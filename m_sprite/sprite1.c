/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

s_sprite *get_sprite(app_data *adata, char *id)
{
    linked_node *sprites = adata->lists->sprites;

    while (sprites != NULL && sprites->data != NULL) {
        s_sprite *cur = (s_sprite *) sprites->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        sprites = sprites->next;
    }

    return (NULL);
}

void add_sprite(app_data *adata, char *id, int layer)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite != NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_ADD_ID")->format;
        my_printf(format, "SPRITE", id);
        return;
    }

    s_sprite *new_sprite = malloc(sizeof(s_sprite));
    new_sprite->active = 1;
    new_sprite->elem = sfSprite_create();
    new_sprite->id = id;
    new_sprite->rtex_id = NULL;
    new_sprite->tex = NULL;
    new_sprite->type = TYPE_SPRITE;
    new_sprite->layer = layer;

    if (layer < adata->min_layer) adata->min_layer = layer;
    if (layer > adata->max_layer) adata->max_layer = layer;

    linked_add(adata->lists->sprites, new_sprite);
}

void delete_sprite(app_data *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_DEL_ID")->format;
        my_printf(format, "SPRITE", id);
        return;
    }

    linked_node *sprites = adata->lists->sprites;
    int ite = 0;

    while (sprites != NULL && sprites->data != NULL) {
        s_sprite *cur = (s_sprite *) sprites->data;

        if (!my_strcmp(cur->id, id)) {
            sfSprite_destroy(cur->elem);
            break;
        }

        ite++;
        sprites = sprites->next;
    }

    linked_delete(&adata->lists->sprites, ite);
}

void set_sprite_target(app_data *adata, char *id, char *target_id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_SET_TARGET")->format;
        my_printf(format, "target render texture", "SPRITE");
        return;
    }

    s_rtex *rtex = get_rtex(adata, target_id);

    if (rtex == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_TARGET")->format;
        my_printf(format, target_id, "SPRITE");
        return;
    }

    sprite->rtex_id = target_id;
}

sfFloatRect get_sprite_bounds(app_data *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        char *format = get_msg(adata, "SPRITE_ERR_GET_ID")->format;
        my_printf(format, "bounds", "SPRITE");
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    return (sfSprite_getGlobalBounds(sprite->elem));
}
