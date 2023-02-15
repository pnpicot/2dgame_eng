/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

s_tex *get_texture(app_data *adata, char *id);
void delete_texture(app_data *adata, char *id);
void load_tex(app_data *adata, char *filename, char *id);
void load_textures(app_data *adata);
