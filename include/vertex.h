/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_vertex *get_vertex(app_data *adata, char *id);
void add_vertex(app_data *adata, char *id, int layer);
void delete_vertex(app_data *adata, char *id);
void set_vertex_target(app_data *adata, char *id, char *target_id);
int get_vertex_size(app_data *adata, char *id);
sfVertex *get_vertex_one(app_data *adata, char *id, int index);
void color_vertex(app_data *adata, char *id, int index, sfColor color);
void color_vertex_all(app_data *adata, char *id, sfColor color);
void resize_vertex(app_data *adata, char *id, int vertex_count);
sfVector2f get_vertex_pos(app_data *adata, char *id, int index);
void move_vertex(app_data *adata, char *id, int index, sfVector2f pos);
void move_vertex_all(app_data *adata, char *id, sfVector2f pos);
void translate_vertex(app_data *adata, char *id, int index, sfVector2f pos_ch);
void translate_vertex_all(app_data *adata, char *id, sfVector2f pos_ch);
void set_vertex_type(app_data *adata, char *id, sfPrimitiveType type);
sfFloatRect get_vertex_bounds(app_data *adata, char *id);
