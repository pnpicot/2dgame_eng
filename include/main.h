/*
** EPITECH PROJECT, 2022
** Project name
** File description:
** Main header
*/

#pragma once

#include <math.h>

#include "my.h"

typedef struct {
    sfRectangleShape *elem;
    char *id;
    char *rtex_id;
    int layer;
} s_rect;

typedef struct {
    sfCircleShape *elem;
    char *id;
    char *rtex_id;
    int layer;
} s_circle;

typedef struct {
    sfVertexArray *elem;
    char *id;
    char *rtex_id;
    int layer;
} s_vertex;

typedef struct {
    sfText *elem;
    char *id;
    char *rtex_id;
    int layer;
} s_text;

typedef struct {
    float app_rate;
    float update_rate;
    float render_rate;
    int win_w;
    int win_h;
} s_config;

typedef struct {
    sfClock *app_clock;
    sfClock *update_clock;
    sfClock *render_clock;
} s_clock;

typedef struct {
    char *format;
    char *id;
} s_msg;

typedef struct {
    sfRenderTexture *tex;
    char *id;
    int depth;
    sfBlendMode mode;
    sfShader *shader;
    sfRenderStates *state;
    sfSprite *sprite;
    int inherit;
} s_rtex;

typedef struct {
    sfShader *shader;
    char *id;
} s_fshader;

typedef struct {
    sfFont *font;
    char *id;
} s_font;

typedef struct {
    linked_node *messages;
    linked_node *fonts;
    linked_node *fshaders;
    linked_node *rtexs;
    linked_node *rects;
    linked_node *circles;
    linked_node *texts;
    linked_node *vertexes;
} s_list;

typedef struct {
    sfRenderWindow *win;
    int win_w;
    int win_h;
    s_config *config;
    s_clock *clocks;
    s_list *lists;
    int min_layer;
    int max_layer;
    int min_rtex_depth;
    int max_rtex_depth;
} app_data;

#include "window.h"
#include "init.h"
#include "update.h"
#include "render.h"
#include "event.h"
#include "default_loader.h"
#include "message.h"
#include "rect.h"
#include "utils.h"
#include "rtex.h"
#include "frag_shader.h"
#include "circle.h"
#include "vertex.h"
#include "font.h"
#include "text.h"
