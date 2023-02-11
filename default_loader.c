/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

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

    add_button(adata, "btn", 3);
    set_button_target(adata, "btn", "rtex_over");
    move_button(adata, "btn", (sfVector2f) { 789, 121 });
    resize_button(adata, "btn", (sfVector2f) { 350, 60});
    edit_button(adata, "btn", "test button");
    set_button_font(adata, "btn", get_font(adata, "oxy"));
    resize_button_text(adata, "btn", 24);
    color_button_bg(adata, "btn", get_color(50, 50, 50, 255));
    color_button_fg(adata, "btn", sfWhite);
    color_button_out(adata, "btn", get_color(150, 150, 150, 255));
    resize_button_out(adata, "btn", 1);
}
