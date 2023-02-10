/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

s_text *get_text(app_data *adata, char *id)
{
    linked_node *texts = adata->lists->texts;

    while (texts != NULL && texts->data != NULL) {
        s_text *cur = (s_text *) texts->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        texts = texts->next;
    }

    return (NULL);
}

void add_text(app_data *adata, char *id, int layer)
{
    s_text *text = get_text(adata, id);

    if (text != NULL) {
        char *format = get_msg(adata, "TEXT_ERR_ADD_ID")->format;
        my_printf(format, "TEXT", id);
        return;
    }

    s_text *new_text = malloc(sizeof(s_text));
    new_text->elem = sfText_create();
    new_text->id = id;
    new_text->rtex_id = NULL;
    new_text->layer = layer;

    if (layer < adata->min_layer) adata->min_layer = layer;
    if (layer > adata->max_layer) adata->max_layer = layer;

    linked_add(adata->lists->texts, new_text);
}

void delete_text(app_data *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_DEL_ID")->format;
        my_printf(format, "TEXT", id);
        return;
    }

    linked_node *texts = adata->lists->texts;
    int ite = 0;

    while (texts != NULL && texts->data != NULL) {
        s_text *cur = (s_text *) texts->data;

        if (!my_strcmp(cur->id, id)) {
            sfText_destroy(cur->elem);
            break;
        }

        ite++;
        texts = texts->next;
    }

    linked_delete(&adata->lists->texts, ite);
}

void set_text_target(app_data *adata, char *id, char *target_id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_TARGET")->format;
        my_printf(format, "target render texture", "TEXT");
        return;
    }

    s_rtex *rtex = get_rtex(adata, target_id);

    if (rtex == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_TARGET")->format;
        my_printf(format, target_id, "TEXT");
        return;
    }

    text->rtex_id = target_id;
}

void color_text(app_data *adata, char *id, sfColor color)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_ID")->format;
        my_printf(format, "foreground color", "TEXT");
        return;
    }

    sfText_setColor(text->elem, color);
}
