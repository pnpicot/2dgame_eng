/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/rtex.h"

void add_rtex(app_data *adata, char *id, int depth)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex != NULL) {
        char *format = get_msg(adata, "RTEX_ERR_ADD_ID")->format;
        my_printf(format, "RENDER_TEXTURE", id);
        return;
    }

    s_rtex *new_rtex = malloc(sizeof(s_rtex));
    new_rtex->depth = depth;
    if (depth < adata->min_rtex_depth) adata->min_rtex_depth = depth;
    if (depth > adata->min_rtex_depth) adata->max_rtex_depth = depth;
    new_rtex->id = id;
    new_rtex->tex = sfRenderTexture_create(adata->win_w, adata->win_h, sfFalse);
    new_rtex->mode = sfBlendNone;
    new_rtex->shader = NULL;
    new_rtex->state = get_default_rstate();
    new_rtex->sprite = sfSprite_create();
    new_rtex->inherit = 0;
    linked_add(adata->lists->rtexs, new_rtex);
}

s_rtex *get_rtex_d(app_data *adata, int depth)
{
    linked_node *rtexs = adata->lists->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex * cur = (s_rtex *) rtexs->data;

        if (cur->depth == depth) return (cur);

        rtexs = rtexs->next;
    }

    return (NULL);
}

void set_rtex_inherit(app_data *adata, char *id, int inherit)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        char *format = get_msg(adata, "RTEX_ERR_SET_ID")->format;
        my_printf(format, "RENDER_TEXTURE", id);
        return;
    }

    rtex->inherit = inherit;
}
