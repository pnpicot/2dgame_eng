/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

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

void ex_callback(app_data *adata, s_transform old)
{
    s_trfarg arg;
    arg.angle = rand() % 360;
    arg.dest = rand_pos(adata);

    float sc = rand_fl(0.3f, 1.9f);

    arg.scale = (sfVector2f) { sc, sc };
    arg.callback = old.callback;
    arg.r_speed = 0;
    arg.s_speed = 0;
    arg.t_speed = 0;
    arg.type = old.ref_type;
    arg.ref = old.ref;

    transform(adata, arg, (rand() % 8) + 2);
}

void load_defaults(app_data *adata)
{
    add_rtex(adata, "main", 1);

    int count = 90;

    for (int i = 0; i < count; i++) {
        char *id = str_add("rect-", nbr_to_str(i));

        add_rect(adata, id, 1);
        resize_rect(adata, id, (sfVector2f) { 30, 30 });
        move_rect(adata, id, rand_pos(adata));
        color_rect(adata, id, get_color(rand() % 255, rand() % 255, rand() % 255, 190));
        set_rect_origin(adata, id, (sfVector2f) { 15, 15 });
        set_rect_target(adata, id, "main");

        s_trfarg arg;
        arg.angle = rand() % 360;
        arg.dest = rand_pos(adata);

        float sc = rand_fl(0.6f, 1.5f);

        arg.scale = (sfVector2f) { sc, sc };
        arg.callback = &ex_callback;
        arg.r_speed = 0;
        arg.s_speed = 0;
        arg.t_speed = 0;
        arg.type = TYPE_RECT;
        arg.ref = get_rect(adata, id);

        transform(adata, arg, (rand() % 8) + 2);
    }
}
