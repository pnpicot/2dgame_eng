/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void set_object_click(app_data *adata, char *id, \
void (*trigger)(app_data *adata))
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_SET_ID")->format;
        my_printf(format, "click function", "OBJECT");
        return;
    }

    object->properties |= obj_click;
    object->trigger = trigger;
}

void disable_object_bg(app_data *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_DISABLE_ID")->format;
        my_printf(format, "background hover color", "OBJECT");
        return;
    }

    object->properties &= ~obj_bg_hover;
}

void set_object_bg(app_data *adata, char *id, sfColor color)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_SET_ID")->format;
        my_printf(format, "background hover color", "OBJECT");
        return;
    }

    object->properties |= obj_bg_hover;
    object->bg_on = color;
}

void disable_object_fg(app_data *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_DISABLE_ID")->format;
        my_printf(format, "foreground hover color", "OBJECT");
        return;
    }

    object->properties &= ~obj_fg_hover;
}

void set_object_fg(app_data *adata, char *id, sfColor color)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_SET_ID")->format;
        my_printf(format, "foreground hover color", "OBJECT");
        return;
    }

    object->properties |= obj_fg_hover;
    object->fg_on = color;
}
