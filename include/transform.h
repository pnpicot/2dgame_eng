/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_transform *get_transform(app_data *adata, char *id);
sfVector2f get_transform_pos(s_trfarg arg);
sfVector2f get_transform_scl(s_trfarg arg);
float get_transform_rot(s_trfarg arg);
void translate(app_data *adata, s_trfarg arg);
void rotate(app_data *adata, s_trfarg arg);
void scale(app_data *adata, s_trfarg arg);
void transform(app_data *adata, s_trfarg arg, float duration);
void delete_transform(app_data *adata, char *id);
s_transform copy_transform(s_transform *old);
void c_rot_button(app_data *adata, s_transform *transform, s_button *button);
void c_rot_circle(app_data *adata, s_transform *transform, s_circle *circle);
void c_rot_rect(app_data *adata, s_transform *transform, s_rect *rect);
void c_rot_text(app_data *adata, s_transform *transform, s_text *text);
void c_scl_button(app_data *adata, s_transform *transform, s_button *button);
void c_scl_circle(app_data *adata, s_transform *transform, s_circle *circle);
void c_scl_rect(app_data *adata, s_transform *transform, s_rect *rect);
void c_scl_text(app_data *adata, s_transform *transform, s_text *text);
void c_trsl_button(app_data *adata, s_transform *transform, s_button *button);
void c_trsl_circle(app_data *adata, s_transform *transform, s_circle *circle);
void c_trsl_rect(app_data *adata, s_transform *transform, s_rect *rect);
void c_trsl_text(app_data *adata, s_transform *transform, s_text *text);
void c_trsl_vertex(app_data *adata, s_transform *transform, s_vertex *vertex);
void update_translation(app_data *adata, s_transform *transform);
void update_rotation(app_data *adata, s_transform *transform);
void update_scaling(app_data *adata, s_transform *transform);
void update_transforms(app_data *adata);
void init_translate(s_transform *new_transform, s_trfarg arg, char *id);
void init_rotate(s_transform *new_transform, s_trfarg arg, char *id);
void init_scale(s_transform *new_transform, s_trfarg arg, char *id);
void init_transform(s_transform *new_transform, s_trfarg arg, char *id);
int transform_idcheck(app_data *adata, char *id);
void c_rot_button_next(app_data *adata, s_transform *transform, \
s_button *button);
void c_rot_circle_next(app_data *adata, s_transform *transform, \
s_circle *circle);
void c_rot_rect_next(app_data *adata, s_transform *transform, \
s_rect *rect);
void c_rot_text_next(app_data *adata, s_transform *transform, s_text *text);
void c_scl_button_next(app_data *adata, s_transform *transform, \
s_button *button);
void c_scl_circle_next(app_data *adata, s_transform *transform, \
s_circle *circle);
void c_scl_rect_next(app_data *adata, s_transform *transform, s_rect *rect);
void c_scl_text_next(app_data *adata, s_transform *transform, s_text *text);
void c_trsl_button_next(app_data *adata, s_transform *transform, \
s_button *button);
void c_trsl_circle_next(app_data *adata, s_transform *transform, \
s_circle *circle);
void c_trsl_rect_next(app_data *adata, s_transform *transform, s_rect *rect);
void c_trsl_text_next(app_data *adata, s_transform *transform, s_text *text);
void c_trsl_vertex_next(app_data *adata, s_transform *transform, \
s_vertex *vertex, float speed);
void c_rot_sprite_next(app_data *adata, s_transform *transform, \
s_sprite *sprite);
void c_rot_sprite(app_data *adata, s_transform *transform, s_sprite *sprite);
void c_scl_sprite_next(app_data *adata, s_transform *transform, \
s_sprite *sprite);
void c_scl_sprite(app_data *adata, s_transform *transform, s_sprite *sprite);
void c_trsl_sprite_next(app_data *adata, s_transform *transform, s_sprite *sprite);
void c_trsl_sprite(app_data *adata, s_transform *transform, s_sprite *sprite);
