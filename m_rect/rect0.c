/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

sfVector2f get_rect_scale(app_data *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_msg(adata, "RECT_ERR_GET_ID")->format, "scale", "RECT");
        return ((sfVector2f) { -1, -1 });
    }

    return (sfRectangleShape_getScale(rect->elem));
}

void delete_rect(app_data *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);
    if (rect == NULL) {
        my_printf(get_msg(adata, "RECT_ERR_DEL_ID")->format, "RECT", id);
        return;
    }
    linked_node *rects = adata->lists->rects;
    int ite = 0;
    while (rects != NULL && rects->data != NULL) {
        s_rect *cur = (s_rect *) rects->data;
        if (!my_strcmp(cur->id, id)) {
            sfRectangleShape_destroy(cur->elem);
            break;
        }
        ite++;
        rects = rects->next;
    }
    linked_delete(&adata->lists->rects, ite);
}

void set_rect_target(app_data *adata, char *id, char *target_id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        char *format = get_msg(adata, "RECT_ERR_SET_ID")->format;
        my_printf(format, "target render texture", "RECT");
        return;
    }

    s_rtex *rtex = get_rtex(adata, target_id);

    if (rtex == NULL) {
        char *format = get_msg(adata, "RECT_ERR_SET_TARGET")->format;
        my_printf(format, "target render texture", "RECT");
        return;
    }

    rect->rtex_id = target_id;
}

void set_rect_active(app_data *adata, char *id, sfUint8 active)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        char *format = get_msg(adata, "RECT_ERR_SET_ID")->format;
        my_printf(format, "active", "RECT");
        return;
    }

    rect->active = active;
}
