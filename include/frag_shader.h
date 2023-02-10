/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_fshader *get_fshader(app_data *adata, char *id);
void add_fshader(app_data *adata, char *id, char *filepath);
void delete_fshader(app_data *adata, char *id);
void set_fshader_vec4(app_data *adata, char *id, char *param, sfFloatRect value);
void set_fshader_vec3(app_data *adata, char *id, char *param, sfVector3f value);
void set_fshader_vec2(app_data *adata, char *id, char *param, sfVector2f value);
void set_fshader_float(app_data *adata, char *id, char *param, float value);
