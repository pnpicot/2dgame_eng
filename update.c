/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

void update(app_data *adata)
{
    s_clock *clocks = adata->clocks;
    s_config *config = adata->config;
    sfTime elapsed = sfClock_getElapsedTime(clocks->update_clock);
    float seconds = elapsed.microseconds / 1000000.0f;

    if (seconds >= config->update_rate) {
        update_objects(adata);

        sfClock_restart(clocks->update_clock);
    }
}
