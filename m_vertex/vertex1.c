/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

s_vertex *get_vertex(app_data *adata, char *id)
{
    linked_node *vertexes = adata->lists->vertexes;

    while (vertexes != NULL && vertexes->data != NULL) {
        s_vertex *cur = (s_vertex *) vertexes->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        vertexes = vertexes->next;
    }

    return (NULL);
}

void add_vertex(app_data *adata, char *id, int layer)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex != NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_ADD_ID")->format;
        my_printf(format, "VERTEX_ARRAY", id);
        return;
    }

    s_vertex *new_vertex = malloc(sizeof(s_vertex));
    new_vertex->elem = sfVertexArray_create();
    new_vertex->id = id;
    new_vertex->rtex_id = NULL;
    new_vertex->layer = layer;
    new_vertex->type = TYPE_VERTEX;
    new_vertex->active = 1;

    if (layer < adata->min_layer) adata->min_layer = layer;
    if (layer > adata->max_layer) adata->max_layer = layer;

    linked_add(adata->lists->vertexes, new_vertex);
}

void delete_vertex(app_data *adata, char *id)
{
    s_vertex *vertex = get_vertex(adata, id);
    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_DEL_ID")->format;
        my_printf(format, "VERTEX_ARRAY", id);
        return;
    }
    linked_node *vertexes = adata->lists->vertexes;
    int ite = 0;
    while (vertexes != NULL && vertexes->data != NULL) {
        s_vertex *cur = (s_vertex *) vertexes->data;
        if (!my_strcmp(cur->id, id)) {
            sfVertexArray_destroy(cur->elem);
            break;
        }
        ite++;
        vertexes = vertexes->next;
    }
    linked_delete(&adata->lists->vertexes, ite);
}

void set_vertex_target(app_data *adata, char *id, char *target_id)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_TARGET")->format;
        my_printf(format, target_id, "VERTEX_ARRAY");
        return;
    }

    s_rtex *rtex = get_rtex(adata, target_id);

    if (rtex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_SET_TARGET")->format;
        my_printf(format, "target render texture", "VERTEX_ARRAY");
        return;
    }

    vertex->rtex_id = target_id;
}

int get_vertex_size(app_data *adata, char *id)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_GET_ID")->format;
        my_printf(format, "size", "VERTEX_ARRAY");
        return (-1);
    }

    return (sfVertexArray_getVertexCount(vertex->elem));
}
