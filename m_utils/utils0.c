/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

char *rand_id(int size)
{
    char *id = malloc(sizeof(char) * (size + 1));
    id[size] = '\0';

    for (int i = 0; i < size; i++) {
        id[i] = i_rand(33, 126);
    }

    return (id);
}

float rand_fl(float min, float max)
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;

    return (min + r);
}

sfVector2f rand_pos(app_data *adata)
{
    return ((sfVector2f) { rand() % adata->win_w, rand() % adata->win_h });
}
