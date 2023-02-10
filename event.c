/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

void register_keypress(app_data *adata, int keycode)
{
    // ...
}

void register_keyrelease(app_data *adata, int keycode)
{
    if (keycode == sfKeyEscape) sfRenderWindow_close(adata->win);
}

void register_event(app_data *adata, sfEvent event)
{
    if (event.type == sfEvtClosed) sfRenderWindow_close(adata->win);
    if (event.type == sfEvtKeyPressed) register_keypress(adata, event.key.code);

    if (event.type == sfEvtKeyReleased)
        register_keyrelease(adata, event.key.code);
}
