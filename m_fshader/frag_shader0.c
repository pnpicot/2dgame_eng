/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void set_fshader_vec3(app_data *adata, char *id, char *param, sfVector3f value)
{
    s_fshader *shader = get_fshader(adata, id);

    if (shader == NULL) {
        char *format = get_msg(adata, "FSHADER_ERR_SET_ID")->format;
        my_printf(format, "FRAGMENTATION_SHADER", id);
        return;
    }

    sfShader_setVector3Parameter(shader->shader, param, value);
}

void set_fshader_vec4(app_data *adata, char *id, char *param, sfFloatRect value)
{
    s_fshader *shader = get_fshader(adata, id);

    if (shader == NULL) {
        char *format = get_msg(adata, "FSHADER_ERR_SET_ID")->format;
        my_printf(format, "FRAGMENTATION_SHADER", id);
        return;
    }

    sfShader_setFloat4Parameter(shader->shader, param, value.left,
        value.top, value.width, value.height);
}
