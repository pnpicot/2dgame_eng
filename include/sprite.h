/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_sprite *get_sprite(app_data *adata, char *id);
void add_sprite(app_data *adata, char *id, int layer);
void delete_sprite(app_data *adata, char *id);
void set_sprite_target(app_data *adata, char *id, char *target_id);
sfFloatRect get_sprite_bounds(app_data *adata, char *id);
void resize_sprite(app_data *adata, char *id, sfVector2f size);
void move_sprite(app_data *adata, char *id, sfVector2f pos);
sfVector2f get_sprite_pos(app_data *adata, char *id);
void translate_sprite(app_data *adata, char *id, sfVector2f pos_ch);
void set_sprite_origin(app_data *adata, char *id, sfVector2f origin);
void rotate_sprite(app_data *adata, char *id, float angle);
void scale_sprite(app_data *adata, char *id, sfVector2f factor);
void set_sprite_active(app_data *adata, char *id, sfUint8 active);
void set_sprite_texture(app_data *adata, char *id, char *texture_id);
sfTexture *get_sprite_tex(app_data *adata, char *id);
float get_sprite_rot(app_data *adata, char *id);
sfVector2f get_sprite_origin(app_data *adata, char *id);
sfVector2f get_sprite_scale(app_data *adata, char *id);
