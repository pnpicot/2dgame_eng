/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_rtex *get_rtex(app_data *adata, char *id);
void add_rtex(app_data *adata, char *id, int depth);
void delete_rtex(app_data *adata, char *id);
void set_rtex_blendmode(app_data *adata, char *id, sfBlendMode mode);
void set_rtex_shader(app_data *adata, char *id, sfShader *shader);
sfRenderStates *get_default_rstate(void);
s_rtex *get_rtex_d(app_data *adata, int depth);
void set_rtex_inherit(app_data *adata, char *id, int inherit);
