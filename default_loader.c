/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

void ex_fn(app_data *adata)
{
    my_printf("Clicked button !\n");
}

void tr_fn(app_data *adata, s_transform old)
{
    s_trfarg trsa;
    trsa.callback = &tr_fn;
    trsa.dest = (sfVector2f) { rand() % adata->win_w, rand() % adata->win_h };
    trsa.angle = 0;
    trsa.scale = (sfVector2f) { 0, 0 };
    trsa.ref = get_button(adata, "btn");
    trsa.type = TYPE_BUTTON;
    trsa.t_speed = 1.0f;
    trsa.r_speed = 0;
    trsa.s_speed = 0;

    translate(adata, trsa);
}

void sc_fn(app_data *adata, s_transform old)
{
    float sc = ((float) rand()) / RAND_MAX;
    sc += 0.3;

    s_trfarg trsa;
    trsa.callback = &sc_fn;
    trsa.dest = (sfVector2f) { 0, 0 };
    trsa.angle = 0;
    trsa.scale = (sfVector2f) { sc, sc };
    trsa.ref = get_button(adata, "btn");
    trsa.type = TYPE_BUTTON;
    trsa.s_speed = 0.001f;
    trsa.r_speed = 0;
    trsa.t_speed = 0;

    scale(adata, trsa);
}

void rt_fn(app_data *adata, s_transform old)
{
    s_trfarg trsa;
    trsa.callback = &rt_fn;
    trsa.dest = (sfVector2f) { 0, 0 };
    trsa.angle = rand() % 360;
    trsa.scale = (sfVector2f) { 0, 0 };
    trsa.ref = get_button(adata, "btn");
    trsa.type = TYPE_BUTTON;
    trsa.r_speed = 0.1f;
    trsa.s_speed = 0;
    trsa.t_speed = 0;

    my_printf("[ " CYN "%6f" RESET " -> " YEL "%6f" RESET " ]\n", old.angle, trsa.angle);

    rotate(adata, trsa);
}

void rtf(app_data *adata, s_transform old)
{
    float sc = ((float) rand()) / RAND_MAX;
    sc += 0.3f;

    s_trfarg trsa;
    trsa.dest = (sfVector2f) { rand() % 1920, rand() % 1080 };
    trsa.angle = rand() % 360;
    trsa.scale = (sfVector2f) { sc, sc };
    trsa.callback = old.callback;
    trsa.r_speed = 0;
    trsa.s_speed = 0;
    trsa.t_speed = 0;
    trsa.type = old.ref_type;
    trsa.ref = old.ref;

    transform(adata, trsa, (rand() % 12) + 2);
}

void load_defaults(app_data *adata)
{
    add_rtex(adata, "rtex_game", 1);
    set_rtex_blendmode(adata, "rtex_game", sfBlendNone);

    add_rect(adata, "ts_rect", 1);
    move_rect(adata, "ts_rect", (sfVector2f) { 150, 150 });
    resize_rect(adata, "ts_rect", (sfVector2f) { 100, 100 });
    color_rect(adata, "ts_rect", sfGreen);
    set_rect_target(adata, "ts_rect", "rtex_game");

    add_rtex(adata, "rtex_over", 2);
    set_rtex_blendmode(adata, "rtex_over", sfBlendAdd);
    set_rtex_inherit(adata, "rtex_over", 0);

    add_rect(adata, "ov_rect", 2);
    move_rect(adata, "ov_rect", (sfVector2f) { 200, 200 });
    resize_rect(adata, "ov_rect", (sfVector2f) { 100, 100 });
    color_rect(adata, "ov_rect", sfRed);
    set_rect_target(adata, "ov_rect", "rtex_over");

    add_rect(adata, "uv_rect", 2);
    move_rect(adata, "uv_rect", (sfVector2f) { 100, 100 });
    resize_rect(adata, "uv_rect", (sfVector2f) { 100, 100 });
    color_rect(adata, "uv_rect", get_color(255, 0, 255, 255));
    set_rect_target(adata, "uv_rect", "rtex_over");

    add_circle(adata, "ov_circ", 3);
    move_circle(adata, "ov_circ", (sfVector2f) { 650, 350 });
    resize_circle(adata, "ov_circ", 80.0f);
    color_circle(adata, "ov_circ", sfBlue);
    set_circle_target(adata, "ov_circ", "rtex_over");

    add_vertex(adata, "ov_vert", 4);
    resize_vertex(adata, "ov_vert", 5);
    set_vertex_target(adata, "ov_vert", "rtex_over");
    set_vertex_type(adata, "ov_vert", sfLinesStrip);
    move_vertex(adata, "ov_vert", 0, (sfVector2f) { 20, 20 });
    move_vertex(adata, "ov_vert", 1, (sfVector2f) { adata->win_w - 20, 20 });
    move_vertex(adata, "ov_vert", 2, (sfVector2f) { adata->win_w - 20, adata->win_h - 20 });
    move_vertex(adata, "ov_vert", 3, (sfVector2f) { 20, adata->win_h - 20 });
    move_vertex(adata, "ov_vert", 4, (sfVector2f) { 20, 20 });
    color_vertex_all(adata, "ov_vert", sfWhite);

    add_text(adata, "ov_text", 3);
    edit_text(adata, "ov_text", "Hello World !");
    resize_text(adata, "ov_text", 35);
    set_text_font(adata, "ov_text", get_font(adata, "oxy"));
    color_text(adata, "ov_text", sfWhite);
    set_text_target(adata, "ov_text", "rtex_over");

    sfFloatRect ovtext_bounds = get_text_bounds(adata, "ov_text");

    move_text(adata, "ov_text", (sfVector2f) { (adata->win_w / 2) - (ovtext_bounds.width / 2), 40 });

    add_rtex(adata, "color_overlay", 3);
    set_rtex_blendmode(adata, "color_overlay", sfBlendAlpha);
    set_rtex_inherit(adata, "color_overlay", 0);

    add_rect(adata, "color_rect", 1);
    move_rect(adata, "color_rect", (sfVector2f) { 0, 0 });
    resize_rect(adata, "color_rect", (sfVector2f) { adata->win_w, adata->win_h });
    color_rect(adata, "color_rect", get_color(150, 90, 224, 70));
    set_rect_target(adata, "color_rect", "color_overlay");

    add_button(adata, "btn", 5);
    set_button_target(adata, "btn", "rtex_over");
    move_button(adata, "btn", (sfVector2f) { 1421, 692 });
    resize_button(adata, "btn", (sfVector2f) { 350, 60});
    edit_button(adata, "btn", "test button");
    set_button_font(adata, "btn", get_font(adata, "oxy"));
    resize_button_text(adata, "btn", 24);
    color_button_bg(adata, "btn", get_color(50, 50, 50, 255));
    color_button_fg(adata, "btn", sfWhite);
    color_button_out(adata, "btn", get_color(150, 150, 150, 255));
    resize_button_out(adata, "btn", 1);

    add_object(adata, "btn_o", get_button(adata, "btn"), TYPE_BUTTON);
    set_object_bg(adata, "btn_o", get_color(20, 20, 20, 255));
    set_object_out(adata, "btn_o", get_color(255, 120, 0, 255));
    set_object_fg(adata, "btn_o", get_color(255, 120, 0, 255));
    set_object_click(adata, "btn_o", &ex_fn);

    add_object(adata, "ov_rect_o", get_rect(adata, "ov_rect"), TYPE_RECT);
    set_object_bg(adata, "ov_rect_o", get_color(125, 56, 215, 255));

    add_object(adata, "uv_rect_o", get_rect(adata, "uv_rect"), TYPE_RECT);
    set_object_bg(adata, "uv_rect_o", get_color(225, 30, 132, 255));

    add_object(adata, "ov_circ_o", get_circle(adata, "ov_circ"), TYPE_CIRCLE);
    set_object_bg(adata, "ov_circ_o", get_color(120, 120, 255, 150));

    s_trfarg trsa;
    trsa.callback = &tr_fn;
    trsa.dest = (sfVector2f) { 50, 50 };
    trsa.ref = get_button(adata, "btn");
    trsa.type = TYPE_BUTTON;
    trsa.t_speed = 1.0f;
    trsa.s_speed = 0;
    trsa.r_speed = 0;
    trsa.angle = 0;
    trsa.scale = (sfVector2f) { 0, 0 };

    translate(adata, trsa);

    set_button_origin(adata, "btn", (sfVector2f) { 175, 30 });

    s_trfarg scla;
    scla.callback = &sc_fn;
    scla.dest = (sfVector2f) { 0, 0 };
    scla.ref = get_button(adata, "btn");
    scla.type = TYPE_BUTTON;
    scla.s_speed = 0.001f;
    scla.r_speed = 0;
    scla.t_speed = 0;
    scla.angle = 0;
    scla.scale = (sfVector2f) { 0.7, 1.2 };

    scale(adata, scla);

    s_trfarg rota;
    rota.callback = &rt_fn;
    rota.dest = (sfVector2f) { 0, 0 };
    rota.ref = get_button(adata, "btn");
    rota.type = TYPE_BUTTON;
    rota.r_speed = 0.1f;
    rota.s_speed = 0;
    rota.t_speed = 0;
    rota.angle = 360;
    rota.scale = (sfVector2f) { 0, 0 };

    rotate(adata, rota);

    set_rect_origin(adata, "uv_rect", (sfVector2f) { 50, 50 });

    s_trfarg uvr;
    uvr.callback = &rtf;
    uvr.angle = 90.0f;
    uvr.dest = (sfVector2f) { 1578, 781 };
    uvr.ref = get_rect(adata, "uv_rect");
    uvr.scale = (sfVector2f) { 0.5, 0.5 };
    uvr.t_speed = 0;
    uvr.s_speed = 0;
    uvr.r_speed = 0;
    uvr.type = TYPE_RECT;

    transform(adata, uvr, 5.0f);
}
