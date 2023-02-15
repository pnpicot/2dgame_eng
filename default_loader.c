/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

void ex_callback(app_data *adata, s_transform old)
{
    s_trfarg arg;
    arg.angle = rand() % 360;
    arg.dest = rand_pos(adata);

    float sc = rand_fl(0.3f, 6.5f);

    arg.scale = (sfVector2f) { sc, sc };
    arg.callback = old.callback;
    arg.r_speed = 0;
    arg.s_speed = 0;
    arg.t_speed = 0;
    arg.type = old.ref_type;
    arg.ref = old.ref;

    transform(adata, arg, (rand() % 10) + 2);
}

// TODO: fix -360 angle bug

void ex2_callback(app_data *adata, s_transform old)
{
    s_trfarg arg;

    if (old.dest.x == adata->win_w - 64) {
        arg.angle = 360;
        arg.dest = (sfVector2f) { 128, 128 };
        arg.scale = (sfVector2f) { 1.0, 1.0 };
    } else {
        arg.angle = 360;
        arg.dest = (sfVector2f) { adata->win_w - 64, adata->win_h - 64 };
        arg.scale = (sfVector2f) { 0.5, 0.5 };
    }

    arg.callback = old.callback;
    arg.r_speed = 0;
    arg.s_speed = 0;
    arg.t_speed = 0;
    arg.ref = old.ref;
    arg.type = TYPE_SPRITE;

    transform(adata, arg, 7.0f);
}

void load_defaults(app_data *adata)
{
    add_rtex(adata, "main", 1);
    /* for (int i = 0; i < 100; i++) {
        char *id = str_add("rect-", nbr_to_str(i));
        add_rect(adata, id, 1);
        resize_rect(adata, id, (sfVector2f) { 30, 30 });
        move_rect(adata, id, rand_pos(adata));
        color_rect(adata, id,
            get_color(rand() % 255, rand() % 255, rand() % 255, 190));
        set_rect_origin(adata, id, (sfVector2f) { 15, 15 });
        set_rect_target(adata, id, "main");
        s_trfarg arg;
        arg.angle = rand() % 360;
        arg.dest = rand_pos(adata);
        float sc = rand_fl(0.6f, 6.5f);
        arg.scale = (sfVector2f) { sc, sc };
        arg.callback = &ex_callback;
        arg.type = TYPE_RECT;
        arg.ref = get_rect(adata, id);
        transform(adata, arg, (rand() % 10) + 2);
    } */

    add_sprite(adata, "test", 1);
    move_sprite(adata, "test", (sfVector2f) { 128, 128 });
    set_sprite_target(adata, "test", "main");
    set_sprite_origin(adata, "test", (sfVector2f) { 128, 128 });
    set_sprite_texture(adata, "test", "default");

    s_trfarg arg;
    arg.angle = 360;
    arg.dest = (sfVector2f) { adata->win_w - 64, adata->win_h - 64 };
    arg.scale = (sfVector2f) { 0.5, 0.5 };
    arg.callback = &ex2_callback;
    arg.r_speed = 0;
    arg.s_speed = 0;
    arg.t_speed = 0;
    arg.ref = get_sprite(adata, "test");
    arg.type = TYPE_SPRITE;

    transform(adata, arg, 7.0f);
}
