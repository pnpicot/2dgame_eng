/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_button *get_button(app_data *adata, char *id);
void add_button(app_data *adata, char *id, int layer);
void delete_button(app_data *adata, char *id);
void set_button_target(app_data *adata, char *id, char *target_id);
void color_button_bg(app_data *adata, char *id, sfColor color);
void color_button_fg(app_data *adata, char *id, sfColor color);
void update_button(app_data *adata, s_button *button);
void resize_button_text(app_data *adata, char *id, float font_size);
void resize_button(app_data *adata, char *id, sfVector2f size);
void move_button(app_data *adata, char *id, sfVector2f pos);
sfVector2f get_button_pos(app_data *adata, char *id);
void translate_button(app_data *adata, char *id, sfVector2f pos_ch);
void set_button_origin(app_data *adata, char *id, sfVector2f origin);
void rotate_button(app_data *adata, char *id, float angle);
void scale_button(app_data *adata, char *id, sfVector2f factor);
void resize_button_out(app_data *adata, char *id, int thickness);
void color_button_out(app_data *adata, char *id, sfColor color);
void edit_button(app_data *adata, char *id, char *str);
void set_button_font(app_data *adata, char *id, sfFont *font);
const char *get_button_string(app_data *adata, char *id);
const sfFont *get_button_font(app_data *adata, char *id);
float get_button_rot(app_data *adata, char *id);
sfFloatRect get_button_bounds(app_data *adata, char *id);
sfVector2f get_button_origin(app_data *adata, char *id);
sfVector2f get_button_scale(app_data *adata, char *id);
