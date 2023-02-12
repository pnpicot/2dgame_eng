/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

char *rand_id(int size);
int i_rand(int min, int max);
int rect_intersect_circle(sfVector2f pos, float radius, sfFloatRect rect);
int circle_contains(sfVector2f pos, float radius, sfVector2f point);
float get_vdist(sfVector2f from, sfVector2f to);
sfColor get_color(int r, int g, int b, int a);
sfVector2f rand_pos(app_data *adata);
float rand_fl(float min, float max);
