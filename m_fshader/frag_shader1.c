/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

s_fshader *get_fshader(app_data *adata, char *id)
{
    linked_node *fshaders = adata->lists->fshaders;

    while (fshaders != NULL && fshaders->data != NULL) {
        s_fshader *cur = (s_fshader *) fshaders->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        fshaders = fshaders->next;
    }

    return (NULL);
}

void delete_fshader(app_data *adata, char *id)
{
    s_fshader *shader = get_fshader(adata, id);

    if (shader == NULL) {
        char *format = get_msg(adata, "FSHADER_ERR_DEL_ID")->format;
        my_printf(format, "FRAGMENTATION_SHADER", id);
        return;
    }

    linked_node *fshaders = adata->lists->fshaders;
    int ite = 0;

    while (fshaders != NULL && fshaders->data != NULL) {
        s_fshader *cur = (s_fshader *) fshaders->data;

        if (!my_strcmp(cur->id, id)) {
            sfShader_destroy(cur->shader);
            break;
        }

        ite++;
        fshaders = fshaders->next;
    }

    linked_delete(&adata->lists->fshaders, ite);
}

void add_fshader(app_data *adata, char *id, char *filepath)
{
    s_fshader *shader = get_fshader(adata, id);

    if (shader != NULL) {
        char *format = get_msg(adata, "FSHADER_ERR_ADD_ID")->format;
        my_printf(format, "FRAGMENTATION_SHADER", id);
        return;
    }

    struct stat buffer;

    if (stat(filepath, &buffer) == -1) {
        char *format = get_msg(adata, "FSHADER_ERR_ADD_FILE")->format;
        my_printf(format, "FRAGMENTATION_SHADER", filepath);
        return;
    }

    s_fshader *new_shader = malloc(sizeof(s_fshader));
    new_shader->id = id;
    new_shader->shader = sfShader_createFromFile(NULL, filepath);
    linked_add(adata->lists->fshaders, new_shader);
}

void set_fshader_float(app_data *adata, char *id, char *param, float value)
{
    s_fshader *shader = get_fshader(adata, id);

    if (shader == NULL) {
        char *format = get_msg(adata, "FSHADER_ERR_SET_ID")->format;
        my_printf(format, "FRAGMENTATION_SHADER", id);
        return;
    }

    sfShader_setFloatParameter(shader->shader, param, value);
}

void set_fshader_vec2(app_data *adata, char *id, char *param, sfVector2f value)
{
    s_fshader *shader = get_fshader(adata, id);

    if (shader == NULL) {
        char *format = get_msg(adata, "FSHADER_ERR_SET_ID")->format;
        my_printf(format, "FRAGMENTATION_SHADER", id);
        return;
    }

    sfShader_setVector2Parameter(shader->shader, param, value);
}
