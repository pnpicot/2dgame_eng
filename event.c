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

void register_leftclick_release(app_data *adata, sfVector2f mouse)
{
    s_log *log = adata->config->log;

    if (log->log_left_rel)
        my_printf("(" YEL "EVENT" RESET ") " CYN "left mouse click" RESET " [ " BLU "%6f" RESET " / " BLU "%6f" RESET " ]\n", mouse.x, mouse.y);

    click_objects(adata);
}

void register_event(app_data *adata, sfEvent event)
{
    if (event.type == sfEvtClosed) sfRenderWindow_close(adata->win);
    if (event.type == sfEvtKeyPressed) register_keypress(adata, event.key.code);

    if (event.type == sfEvtKeyReleased)
        register_keyrelease(adata, event.key.code);

    if (event.type == sfEvtMouseButtonReleased
        && event.mouseButton.button == sfMouseLeft)
        register_leftclick_release(adata,
            (sfVector2f) { event.mouseButton.x, event.mouseButton.y });
}
