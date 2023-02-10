/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

void window_loop(app_data *adata)
{
    sfEvent event;
    s_clock *clocks = adata->clocks;
    s_config *config = adata->config;

    while (sfRenderWindow_pollEvent(adata->win, &event)) {
        register_event(adata, event);
    }

    sfTime elapsed = sfClock_getElapsedTime(clocks->app_clock);
    float seconds = elapsed.microseconds / 1000000.0f;

    if (seconds >= config->app_rate) {
        sfRenderWindow_clear(adata->win, sfBlack);

        update(adata);
        render(adata);

        sfRenderWindow_display(adata->win);
        sfClock_restart(clocks->app_clock);
    }
}

void run_window(app_data *adata)
{
    load_defaults(adata);

    while (sfRenderWindow_isOpen(adata->win)) {
        window_loop(adata);
    }
}

void create_window(app_data *adata)
{
    s_config *config = adata->config;
    init_config(config);
    adata->win_w = config->win_w;
    adata->win_h = config->win_h;

    sfVideoMode mode = { adata->win_w, adata->win_h, 32 };
    sfRenderWindow* window;
    sfContextSettings *settings = malloc(sizeof(sfContextSettings));
    settings->antialiasingLevel = 8;

    char *title = "2D Game Engine";
    window = sfRenderWindow_create(mode, title, sfClose | sfResize, settings);

    if (!window) exit(84);

    adata->win = window;
    sfRenderWindow_setFramerateLimit(adata->win, 360);
    run_window(adata);
    sfRenderWindow_destroy(window);
    exit(0);
}
