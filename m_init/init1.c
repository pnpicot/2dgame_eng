/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void init_clocks(s_clock *clocks)
{
    clocks->app_clock = sfClock_create();
    clocks->render_clock = sfClock_create();
    clocks->update_clock = sfClock_create();
}
