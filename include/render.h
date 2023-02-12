/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

void render_rects(app_data *adata, int layer, int depth);
void render_circles(app_data *adata, int layer, int depth);
void render_vertexes(app_data *adata, int layer, int depth);
void render_texts(app_data *adata, int layer, int depth);
void render_elements(app_data *adata, s_rtex *cur, int depth);
void render_rtexs(app_data *adata, int depth);
void display_rtexs(app_data *adata);
void clear_rtexs(app_data *adata);
void render(app_data *adata);
