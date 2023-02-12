/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void render_rects(app_data *adata, int layer, int depth)
{
    linked_node *rects = adata->lists->rects;
    s_rtex *cur_rtex = get_rtex_d(adata, depth);

    while (rects != NULL && rects->data != NULL) {
        s_rect *cur = (s_rect *) rects->data;

        if (!cur->active || cur->layer != layer || cur->rtex_id == NULL
            || cur_rtex == NULL || my_strcmp(cur_rtex->id, cur->rtex_id)) {
            rects = rects->next;
            continue;
        }

        sfRenderTexture_drawRectangleShape(cur_rtex->tex, cur->elem, NULL);

        rects = rects->next;
    }
}

void render_circles(app_data *adata, int layer, int depth)
{
    linked_node *circles = adata->lists->circles;
    s_rtex *cur_rtex = get_rtex_d(adata, depth);

    while (circles != NULL && circles->data != NULL) {
        s_circle *cur = (s_circle *) circles->data;

        if (!cur->active || cur->layer != layer || cur->rtex_id == NULL
            || cur_rtex == NULL || my_strcmp(cur_rtex->id, cur->rtex_id)) {
            circles = circles->next;
            continue;
        }

        sfRenderTexture_drawCircleShape(cur_rtex->tex, cur->elem, NULL);

        circles = circles->next;
    }
}

void render_vertexes(app_data *adata, int layer, int depth)
{
    linked_node *vertexes = adata->lists->vertexes;
    s_rtex *cur_rtex = get_rtex_d(adata, depth);

    while (vertexes != NULL && vertexes->data != NULL) {
        s_vertex *cur = (s_vertex *) vertexes->data;

        if (!cur->active || cur->layer != layer || cur->rtex_id == NULL
            || cur_rtex == NULL || my_strcmp(cur_rtex->id, cur->rtex_id)) {
            vertexes = vertexes->next;
            continue;
        }

        sfRenderTexture_drawVertexArray(cur_rtex->tex, cur->elem, NULL);

        vertexes = vertexes->next;
    }
}

void render_texts(app_data *adata, int layer, int depth)
{
    linked_node *texts = adata->lists->texts;
    s_rtex *cur_rtex = get_rtex_d(adata, depth);

    while (texts != NULL && texts->data != NULL) {
        s_text *cur = (s_text *) texts->data;

        if (!cur->active || cur->layer != layer || cur->rtex_id == NULL
            || cur_rtex == NULL || my_strcmp(cur_rtex->id, cur->rtex_id)) {
            texts = texts->next;
            continue;
        }

        sfRenderTexture_drawText(cur_rtex->tex, cur->elem, NULL);

        texts = texts->next;
    }
}

void render_elements(app_data *adata, s_rtex *cur, int depth)
{
    for (int i = adata->min_layer - 1; i <= adata->max_layer; i++) {
        render_rects(adata, i, depth);
        render_circles(adata, i, depth);
        render_vertexes(adata, i, depth);
        render_texts(adata, i, depth);
    }
}
