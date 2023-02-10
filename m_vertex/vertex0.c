/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

sfFloatRect get_vertex_bounds(app_data *adata, char *id)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        char *format = get_msg(adata, "VERTEX_ERR_GET_ID")->format;
        my_printf(format, "primitive type", "VERTEX_ARRAY");
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    return (sfVertexArray_getBounds(vertex->elem));
}
