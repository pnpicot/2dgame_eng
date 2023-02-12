/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

sfFont *get_font(app_data *adata, char *id)
{
    linked_node *fonts = adata->lists->fonts;

    while (fonts != NULL && fonts->data != NULL) {
        s_font *cur = (s_font *) fonts->data;

        if (!my_strcmp(cur->id, id)) return (cur->font);

        fonts = fonts->next;
    }

    return (NULL);
}

void load_font(app_data *adata, char *filename, char *id)
{
    sfFont *font = get_font(adata, id);

    if (font != NULL) {
        char *format = get_msg(adata, "FONT_ERR_ID_CONFLICT")->format;
        my_printf(format, filename, id);
        return;
    }

    struct stat buffer;

    if (stat(filename, &buffer) == -1) {
        char *format = get_msg(adata, "FONT_ERR_LOAD_FILE")->format;
        my_printf(format, filename);
        return;
    }

    s_font *new_font = malloc(sizeof(s_font));
    new_font->font = sfFont_createFromFile(filename);
    new_font->id = id;
    linked_add(adata->lists->fonts, new_font);
}

void init_fonts(app_data *adata)
{
    char *file_content = file_extract("bonus/fonts.data");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_m_split(entries[ite], 2, '=', ' ');
        char *filename = str_add("bonus/fonts/", entry_data[0]);
        char *id = entry_data[1];

        load_font(adata, filename, id);

        ite++;
    }
}
