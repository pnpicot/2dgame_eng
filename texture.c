/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

s_tex *get_texture(app_data *adata, char *id)
{
    linked_node *textures = adata->lists->textures;

    while (textures != NULL && textures->data != NULL) {
        s_tex *cur = (s_tex *) textures->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        textures = textures->next;
    }

    return (NULL);
}

void delete_texture(app_data *adata, char *id)
{
    s_tex *texture = get_texture(adata, id);

    if (texture == NULL) {
        char *format = get_msg(adata, "TEXTURE_ERR_DEL_ID")->format;
        my_printf(format, "TEXTURE", id);
        return;
    }

    linked_node *textures = adata->lists->textures;
    int ite = 0;

    while (textures != NULL && textures->data != NULL) {
        s_tex *cur = (s_tex *) textures->data;

        if (!my_strcmp(cur->id, id)) {
            sfTexture_destroy(cur->tex);
            break;
        }

        ite++;
        textures = textures->next;
    }

    linked_delete(&adata->lists->textures, ite);
}

void load_tex(app_data *adata, char *filename, char *id)
{
    s_tex *texture = get_texture(adata, id);

    if (texture != NULL) {
        char *format = get_msg(adata, "TEXTURE_ERR_ADD_ID")->format;
        my_printf(format, "TEXTURE", id);
        return;
    }

    char *path = str_add("bonus/textures/", filename);
    struct stat buffer;

    if (stat(path, &buffer) == -1) {
        char *format = get_msg(adata, "TEXTURE_ERR_LOAD_FILE")->format;
        my_printf(format, "TEXTURE", filename);
        return;
    }

    s_tex *new_texture = malloc(sizeof(s_tex));
    new_texture->id = id;
    new_texture->tex = sfTexture_createFromFile(path, NULL);

    linked_add(adata->lists->textures, new_texture);
}

void load_textures(app_data *adata)
{
    char *file_content = file_extract("bonus/textures/load.data");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_split(entries[ite], ';');
        char *filename = entry_data[0];
        char *id = entry_data[1];

        load_tex(adata, filename, id);

        ite++;
    }
}
