/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

void init_clocks(s_clock *clocks)
{
    clocks->app_clock = sfClock_create();
    clocks->render_clock = sfClock_create();
    clocks->update_clock = sfClock_create();
}

void init_lists(s_list *lists)
{
    lists->messages = linked_new();
    lists->fonts = linked_new();
    lists->rtexs = linked_new();
    lists->fshaders = linked_new();
    lists->rects = linked_new();
    lists->circles = linked_new();
    lists->vertexes = linked_new();
    lists->texts = linked_new();
    lists->buttons = linked_new();
    lists->objects = linked_new();
}

void init_appdata(app_data *adata)
{
    adata->config = malloc(sizeof(s_config));
    adata->clocks = malloc(sizeof(s_clock));
    adata->lists = malloc(sizeof(s_list));
    adata->min_layer = 0;
    adata->max_layer = 0;

    init_clocks(adata->clocks);
    init_lists(adata->lists);
    init_messages(adata);
    init_fonts(adata);
}

void apply_config(s_config *config, char *key, char *val)
{
    if (!my_strcmp(key, "APP_RATE"))
        config->app_rate = str_to_float(val);
    if (!my_strcmp(key, "UPDATE_RATE"))
        config->update_rate = str_to_float(val);
    if (!my_strcmp(key, "RENDER_RATE"))
        config->render_rate = str_to_float(val);
    if (!my_strcmp(key, "DEF_WIN_X"))
        config->win_w = my_getnbr(val);
    if (!my_strcmp(key, "DEF_WIN_Y"))
        config->win_h = my_getnbr(val);
    if (!my_strcmp(key, "LOG_LEFT_REL"))
        config->log->log_left_rel = my_getnbr(val);
    if (!my_strcmp(key, "LOG_LEFT_PRESS"))
        config->log->log_left_press = my_getnbr(val);
    if (!my_strcmp(key, "LOG_RIGHT_REL"))
        config->log->log_right_rel = my_getnbr(val);
    if (!my_strcmp(key, "LOG_RIGHT_PRESS"))
        config->log->log_right_press = my_getnbr(val);
}

void init_log(s_log *log)
{
    log->log_left_press = 0;
    log->log_left_rel = 0;
    log->log_right_press = 0;
    log->log_right_rel = 0;
}

void init_config(s_config *config)
{
    char *file_content = file_extract("bonus/config.data");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    config->log = malloc(sizeof(s_log));

    init_log(config->log);

    while (entries[ite] != NULL) {
        char **data = str_m_split(entries[ite], 2, '=', ' ');
        char *key = data[0];
        char *val = data[1];

        apply_config(config, key, val);

        ite++;
    }
}
