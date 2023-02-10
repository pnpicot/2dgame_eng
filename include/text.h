/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_text *get_text(app_data *adata, char *id);
void add_text(app_data *adata, char *id, int layer);
void delete_text(app_data *adata, char *id);
void set_text_target(app_data *adata, char *id, char *target_id);
void color_text(app_data *adata, char *id, sfColor color);
void resize_text(app_data *adata, char *id, float font_size);
void move_text(app_data *adata, char *id, sfVector2f pos);
sfVector2f get_text_pos(app_data *adata, char *id);
void translate_text(app_data *adata, char *id, sfVector2f pos_ch);
void set_text_origin(app_data *adata, char *id, sfVector2f origin);
void rotate_text(app_data *adata, char *id, float angle);
void scale_text(app_data *adata, char *id, sfVector2f factor);
void edit_text(app_data *adata, char *id, char *str);
void set_text_font(app_data *adata, char *id, sfFont *font);
float get_text_rot(app_data *adata, char *id);
sfFloatRect get_text_bounds(app_data *adata, char *id);
sfVector2f get_text_origin(app_data *adata, char *id);
sfVector2f get_text_scale(app_data *adata, char *id);
const sfFont *get_text_font(app_data *adata, char *id);
const char *get_text_string(app_data *adata, char *id);
