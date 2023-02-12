/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_circle *get_circle(app_data *adata, char *id);
void add_circle(app_data *adata, char *id, int layer);
void delete_circle(app_data *adata, char *id);
void set_circle_target(app_data *adata, char *id, char *target_id);
void color_circle(app_data *adata, char *id, sfColor color);
void resize_circle(app_data *adata, char *id, float radius);
void move_circle(app_data *adata, char *id, sfVector2f pos);
sfVector2f get_circle_pos(app_data *adata, char *id);
void translate_circle(app_data *adata, char *id, sfVector2f pos_ch);
void set_circle_origin(app_data *adata, char *id, sfVector2f origin);
void rotate_circle(app_data *adata, char *id, float angle);
void scale_circle(app_data *adata, char *id, sfVector2f factor);
void resize_circle_out(app_data *adata, char *id, int thickness);
void color_circle_out(app_data *adata, char *id, sfColor color);
float get_circle_rot(app_data *adata, char *id);
sfFloatRect get_circle_bounds(app_data *adata, char *id);
sfVector2f get_circle_origin(app_data *adata, char *id);
sfVector2f get_circle_scale(app_data *adata, char *id);
void set_circle_active(app_data *adata, char *id, sfUint8 active);
