/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void move_vertex(app_data *adata, char *id, int index, sfVector2f pos)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_ID")->format;
        my_printf(format, "position (one)", "VERTEX_ARRAY");
        return;
    }

    int count = get_vertex_size(adata, id);

    if (index < 0 || index >= count) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_COUNT")->format;
        my_printf(format, "vertex position (one)", "VERTEX_ARRAY", index);
        return;
    }

    sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, index);
    u_vert->position = pos;
}

void move_vertex_all(app_data *adata, char *id, sfVector2f pos)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_ID")->format;
        my_printf(format, "vertex position (all)", "VERTEX_ARRAY");
        return;
    }

    int count = get_vertex_size(adata, id);

    for (int i = 0; i < count; i++) {
        sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, i);
        u_vert->position = pos;
    }
}

void translate_vertex(app_data *adata, char *id, int index, sfVector2f pos_ch)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_ID")->format;
        my_printf(format, "vertex position (one, translate)", "VERTEX_ARRAY");
        return;
    }

    int count = get_vertex_size(adata, id);

    if (index < 0 || index >= count) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_COUNT")->format;
        my_printf(format, "vertex position (one, translate)",
            "VERTEX_ARRAY", index);
        return;
    }

    sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, index);
    u_vert->position.x += pos_ch.x;
    u_vert->position.y += pos_ch.y;
}

void translate_vertex_all(app_data *adata, char *id, sfVector2f pos_ch)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_ID")->format;
        my_printf(format, "vertex position (all, translate)", "VERTEX_ARRAY");
        return;
    }

    int count = get_vertex_size(adata, id);

    for (int i = 0; i < count; i++) {
        sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, i);
        u_vert->position.x += pos_ch.x;
        u_vert->position.y += pos_ch.y;
    }
}

void set_vertex_type(app_data *adata, char *id, sfPrimitiveType type)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_ID")->format;
        my_printf(format, "primitive type", "VERTEX_ARRAY");
        return;
    }

    sfVertexArray_setPrimitiveType(vertex->elem, type);
}
