/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

s_button *get_button(app_data *adata, char *id)
{
    linked_node *buttons = adata->lists->buttons;

    while (buttons != NULL && buttons->data != NULL) {
        s_button *cur = (s_button *) buttons->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        buttons = buttons->next;
    }

    return (NULL);
}

void add_button(app_data *adata, char *id, int layer)
{
    s_button *button = get_button(adata, id);

    if (button != NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_ADD_ID")->format;
        my_printf(format, "BUTTON", id);
        return;
    }

    char *rect_id = str_add("@PV_RCT-", id);
    char *text_id = str_add("@PV_TXT-", id);

    add_rect(adata, rect_id, layer);
    add_text(adata, text_id, layer);

    s_button *new_button = malloc(sizeof(s_button));
    new_button->id = id;
    new_button->rect = get_rect(adata, rect_id);
    new_button->text = get_text(adata, text_id);
    new_button->rtex_id = NULL;
    new_button->layer = layer;
    new_button->type = TYPE_BUTTON;

    if (layer < adata->min_layer) adata->min_layer = layer;
    if (layer > adata->max_layer) adata->max_layer = layer;

    linked_add(adata->lists->buttons, new_button);
}

void delete_button(app_data *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_DEL_ID")->format;
        my_printf(format, "BUTTON", id);
        return;
    }

    linked_node *buttons = adata->lists->buttons;
    int ite = 0;

    while (buttons != NULL && buttons->data != NULL) {
        s_button *cur = (s_button *) buttons->data;

        if (!my_strcmp(cur->id, id)) {
            delete_rect(adata, cur->rect->id);
            delete_text(adata, cur->text->id);
            break;
        }

        ite++;
        buttons = buttons->next;
    }

    linked_delete(&adata->lists->buttons, ite);
}

void set_button_target(app_data *adata, char *id, char *target_id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_TARGET")->format;
        my_printf(format, "target render texture", "BUTTON");
        return;
    }

    s_rtex *rtex = get_rtex(adata, target_id);

    if (rtex == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_TARGET")->format;
        my_printf(format, target_id, "BUTTON");
        return;
    }

    button->rect->rtex_id = target_id;
    button->text->rtex_id = target_id;
}

void color_button_bg(app_data *adata, char *id, sfColor color)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "background color", "BUTTON");
        return;
    }

    sfRectangleShape_setFillColor(button->rect->elem, color);
}
