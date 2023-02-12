/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

s_rtex *get_rtex(app_data *adata, char *id)
{
    linked_node *rtexs = adata->lists->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        rtexs = rtexs->next;
    }

    return (NULL);
}

void delete_rtex(app_data *adata, char *id)
{
    s_rtex *rtex = get_rtex(adata, id);
    if (rtex == NULL) {
        char *format = get_msg(adata, "RTEX_ERR_DEL_ID")->format;
        my_printf(format, "RENDER_TEXTURE", id);
        return;
    }
    linked_node *rtexs = adata->lists->rtexs;
    int ite = 0;
    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;
        if (!my_strcmp(cur->id, id)) {
            sfRenderTexture_destroy(cur->tex);
            break;
        }
        ite++;
        rtexs = rtexs->next;
    }
    linked_delete(&adata->lists->rtexs, ite);
}

void set_rtex_shader(app_data *adata, char *id, sfShader *shader)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        char *format = get_msg(adata, "RTEX_ERR_SET_ID")->format;
        my_printf(format, "shader", "RENDER_TEXTURE");
        return;
    }

    sfRenderStates *state = malloc(sizeof(sfRenderStates));
    state->blendMode = rtex->mode;
    state->shader = shader;
    state->texture = NULL;
    state->transform = sfTransform_Identity;

    rtex->shader = shader;
    rtex->state = state;
}

void set_rtex_blendmode(app_data *adata, char *id, sfBlendMode mode)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        char *format = get_msg(adata, "RTEX_ERR_SET_ID")->format;
        my_printf(format, "blend mode", "RENDER_TEXTURE");
        return;
    }

    sfRenderStates *state = malloc(sizeof(sfRenderStates));
    state->blendMode = mode;
    state->shader = rtex->shader;
    state->texture = NULL;
    state->transform = sfTransform_Identity;

    rtex->mode = mode;
    rtex->state = state;
}

sfRenderStates *get_default_rstate(void)
{
    sfRenderStates *state = malloc(sizeof(sfRenderStates));

    state->blendMode = sfBlendNone;
    state->shader = NULL;
    state->texture = NULL;
    state->transform = sfTransform_Identity;

    return (state);
}
