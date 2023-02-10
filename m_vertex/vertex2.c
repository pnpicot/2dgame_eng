/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

sfVertex *get_vertex_one(app_data *adata, char *id, int index)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_GET_ID")->format;
        my_printf(format, "vertex", "VERTEX_ARRAY");
        return (NULL);
    }

    int count = get_vertex_size(adata, id);

    if (index < 0 || index >= count) {
        char *format = get_msg(adata, "VERTEX_ERR_GET_COUNT")->format;
        my_printf(format, "vertex", "VERTEX_ARRAY", index);
        return (NULL);
    }

    return (sfVertexArray_getVertex(vertex->elem, index));
}

void color_vertex(app_data *adata, char *id, int index, sfColor color)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_ID")->format;
        my_printf(format, "vertex color (one)", "VERTEX_ARRAY");
        return;
    }

    int count = get_vertex_size(adata, id);

    if (index < 0 || index >= count) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_COUNT")->format;
        my_printf(format, "vertex color", "VERTEX_ARRAY", index);
        return;
    }

    sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, index);
    u_vert->color = color;
}

void color_vertex_all(app_data *adata, char *id, sfColor color)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_ID")->format;
        my_printf(format, "vertex color (all)", "VERTEX_ARRAY");
        return;
    }

    int count = get_vertex_size(adata, id);

    for (int i = 0; i < count; i++) {
        sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, i);
        u_vert->color = color;
    }
}

void resize_vertex(app_data *adata, char *id, int vertex_count)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_ID")->format;
        my_printf(format, "size", "VERTEX_ARRAY");
        return;
    }

    vertex_count = my_abs(vertex_count);

    sfVertexArray_resize(vertex->elem, vertex_count);
}

sfVector2f get_vertex_pos(app_data *adata, char *id, int index)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_GET_ID")->format;
        my_printf(format, "position", "VERTEX_ARRAY");
        return ((sfVector2f) { -1, -1 });
    }

    int count = get_vertex_size(adata, id);

    if (index < 0 || index >= count) {
        char *format = get_msg(adata, "VERTEX_ERR_GET_COUNT")->format;
        my_printf(format, "vertex position", "VERTEX_ARRAY", index);
        return ((sfVector2f) { -1, -1 });
    }

    sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, index);

    return (u_vert->position);
}
