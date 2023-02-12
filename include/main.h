/*
** EPITECH PROJECT, 2022
** Project name
** File description:
** Main header
*/

#pragma once

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define TYPE_RECT 1
#define TYPE_CIRCLE 2
#define TYPE_TEXT 3
#define TYPE_VERTEX 4
#define TYPE_BUTTON 5

#define TRF_TRANSLATE 1
#define TRF_ROTATE 2
#define TRF_SCALE 3
#define TRF_ALL 4

#define obj_bg_hover 0x01
#define obj_fg_hover 0x02
#define obj_click 0x04
#define obj_out_hover 0x08

#define TRANSFORM_TOLERANCE 1.0f

#include <math.h>
#include <time.h>
#include "my.h"

typedef struct {
    sfRectangleShape *elem;
    char *id;
    char *rtex_id;
    int layer;
    sfUint8 type;
} s_rect;

typedef struct {
    sfCircleShape *elem;
    char *id;
    char *rtex_id;
    int layer;
    sfUint8 type;
} s_circle;

typedef struct {
    sfVertexArray *elem;
    char *id;
    char *rtex_id;
    int layer;
    sfUint8 type;
} s_vertex;

typedef struct {
    sfText *elem;
    char *id;
    char *rtex_id;
    int layer;
    sfUint8 type;
} s_text;

typedef struct {
    s_text *text;
    s_rect *rect;
    char *id;
    char *rtex_id;
    int layer;
    sfUint8 type;
} s_button;

typedef struct {
    int log_left_rel;
    int log_left_press;
    int log_right_rel;
    int log_right_press;
} s_log;

typedef struct {
    float app_rate;
    float update_rate;
    float render_rate;
    int win_w;
    int win_h;
    s_log *log;
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
    linked_node *buttons;
    linked_node *objects;
    linked_node *transforms;
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

typedef struct {
    void *ref;
    sfUint8 type;
    int properties;
    char *id;
    sfColor bg_off;
    sfColor bg_on;
    sfColor fg_off;
    sfColor fg_on;
    sfColor out_off;
    sfColor out_on;
    void (*trigger)(app_data *adata);
    sfVector2f padding;
} s_object;

typedef struct s_transform_s {
    void *ref;
    char *id;
    sfUint8 ref_type;
    sfUint8 trf_type;
    sfVector2f dest;
    float t_speed;
    float s_speed;
    float r_speed;
    float angle;
    sfVector2f scale;
    sfUint8 trsl;
    sfUint8 rot;
    sfUint8 scl;
    void (*callback)(app_data *adata, struct s_transform_s old);
} s_transform;

typedef struct {
    void *ref;
    sfUint8 type;
    sfVector2f dest;
    float t_speed;
    float s_speed;
    float r_speed;
    float angle;
    sfVector2f scale;
    void (*callback)(app_data *adata, struct s_transform_s old);
} s_trfarg;

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
#include "button.h"
#include "object.h"
#include "transform.h"
