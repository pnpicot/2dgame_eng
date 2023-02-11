/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_object *get_object(app_data *adata, char *id);
void set_object_defaults(app_data *adata, s_object *object);
void add_object(app_data *adata, char *id, void *ref, sfUint8 type);
void delete_object(app_data *adata, char *id);
void disable_object_click(app_data *adata, char *id);
void set_object_click(app_data *adata, char *id, void (*trigger)(app_data *adata));
void disable_object_bg(app_data *adata, char *id);
void set_object_bg(app_data *adata, char *id, sfColor color);
void disable_object_fg(app_data *adata, char *id);
void set_object_fg(app_data *adata, char *id, sfColor color);
void disable_object_out(app_data *adata, char *id);
void set_object_out(app_data *adata, char *id, sfColor color);
void resize_object(app_data *adata, char *id, sfVector2f padding);
void update_object_rect(s_object *object, s_rect *rect, sfVector2f mouse);
void update_object_button(s_object *object, s_button *button, sfVector2f mouse);
void update_object_text(s_object *object, s_text *text, sfVector2f mouse);
void update_object_circle(s_object *object, s_circle *circle, sfVector2f mouse);
void update_s_object(s_object *object, sfVector2f mouse);
void update_objects(app_data *adata);
void click_s_objects(app_data *adata, s_object *object, sfVector2f mouse);
void click_objects(app_data *adata);
void click_object_button(app_data *adata, s_object *object, s_button *button, sfVector2f mouse);
void click_object_text(app_data *adata, s_object *object, s_text *text, sfVector2f mouse);
void click_object_rect(app_data *adata, s_object *object, s_rect *rect, sfVector2f mouse);
void click_object_circle(app_data *adata, s_object *object, s_circle *circle, sfVector2f mouse);

