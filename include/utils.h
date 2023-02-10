/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#pragma once

#include "main.h"

sfColor get_color(int r, int g, int b, int a);
float get_vdist(sfVector2f from, sfVector2f to);
int circle_contains(sfVector2f pos, float radius, sfVector2f point);
int rect_intersect_circle(sfVector2f pos, float radius, sfFloatRect rect);
