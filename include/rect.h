/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_rect *get_rect(app_data *adata, char *id);
void add_rect(app_data *adata, char *id, int layer);
void delete_rect(app_data *adata, char *id);
void set_rect_target(app_data *adata, char *id, char *target_id);
void color_rect(app_data *adata, char *id, sfColor color);
void resize_rect(app_data *adata, char *id, sfVector2f size);
void move_rect(app_data *adata, char *id, sfVector2f pos);
sfVector2f get_rect_pos(app_data *adata, char *id);
void translate_rect(app_data *adata, char *id, sfVector2f pos_ch);
void set_rect_origin(app_data *adata, char *id, sfVector2f origin);
void rotate_rect(app_data *adata, char *id, float angle);
void scale_rect(app_data *adata, char *id, sfVector2f factor);
void resize_rect_out(app_data *adata, char *id, float thickness);
void color_rect_out(app_data *adata, char *id, sfColor color);
float get_rect_rot(app_data *adata, char *id);
sfFloatRect get_rect_bounds(app_data *adata, char *id);
sfVector2f get_rect_origin(app_data *adata, char *id);
sfVector2f get_rect_scale(app_data *adata, char *id);
