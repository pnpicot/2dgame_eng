/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

s_circle *get_circle(app_data *adata, char *id)
{
    linked_node *circles = adata->lists->circles;

    while (circles != NULL && circles->data != NULL) {
        s_circle *cur = (s_circle *) circles->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        circles = circles->next;
    }

    return (NULL);
}

void add_circle(app_data *adata, char *id, int layer)
{
    s_circle *circle = get_circle(adata, id);

    if (circle != NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_ADD_ID")->format;
        my_printf(format, "CIRCLE", id);
        return;
    }

    s_circle *new_circle = malloc(sizeof(s_circle));
    new_circle->elem = sfCircleShape_create();
    new_circle->id = id;
    new_circle->rtex_id = NULL;
    new_circle->layer = layer;
    new_circle->type = TYPE_CIRCLE;

    if (layer < adata->min_layer) adata->min_layer = layer;
    if (layer > adata->max_layer) adata->max_layer = layer;

    linked_add(adata->lists->circles, new_circle);
}

void delete_circle(app_data *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_DEL_ID")->format;
        my_printf(format, "CIRCLE", id);
        return;
    }

    linked_node *circles = adata->lists->circles;
    int ite = 0;

    while (circles != NULL && circles->data != NULL) {
        s_circle *cur = (s_circle *) circles->data;

        if (!my_strcmp(cur->id, id)) {
            sfCircleShape_destroy(cur->elem);
            break;
        }

        ite++;
        circles = circles->next;
    }

    linked_delete(&adata->lists->circles, ite);
}

void set_circle_target(app_data *adata, char *id, char *target_id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_TARGET")->format;
        my_printf(format, target_id, "CIRCLE");
        return;
    }

    s_rtex *rtex = get_rtex(adata, target_id);

    if (rtex == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_TARGET")->format;
        my_printf(format, "render texture target", "CIRCLE");
        return;
    }

    circle->rtex_id = target_id;
}

void color_circle(app_data *adata, char *id, sfColor color)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        char *format = get_msg(adata, "CIRCLE_ERR_SET_ID")->format;
        my_printf(format, "fill color", "CIRCLE");
        return;
    }

    sfCircleShape_setFillColor(circle->elem, color);
}
