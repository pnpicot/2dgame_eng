/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

s_object *get_object(app_data *adata, char *id)
{
    linked_node *objects = adata->lists->objects;

    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        objects = objects->next;
    }

    return (NULL);
}

void set_object_defaults(app_data *adata, s_object *object)
{
    switch (object->type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) object->ref;
            object->bg_off = sfRectangleShape_getFillColor(rect->elem);
            object->out_off = sfRectangleShape_getOutlineColor(rect->elem);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) object->ref;
            object->bg_off = sfCircleShape_getFillColor(circle->elem);
            object->out_off = sfCircleShape_getOutlineColor(circle->elem);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) object->ref;
            object->fg_off = sfText_getColor(text->elem);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) object->ref;
            object->bg_off = sfRectangleShape_getFillColor(button->rect->elem);
            object->fg_off = sfText_getColor(button->text->elem);
            object->out_off = sfRectangleShape_getOutlineColor(button->rect->elem);
            break;
        default:
            char *format = get_msg(adata, "OBJECT_WARN_NO_SUPPORT")->format;
            my_printf(format, object->id);
            break;
    }
}

void add_object(app_data *adata, char *id, void *ref, sfUint8 type)
{
    s_object *object = get_object(adata, id);

    if (object != NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_ADD_ID")->format;
        my_printf(format, "OBJECT", id);
        return;
    }

    s_object *new_object = malloc(sizeof(s_object));
    new_object->id = id;
    new_object->properties = 0;
    new_object->ref = ref;
    new_object->type = type;
    new_object->bg_on = sfBlack;
    new_object->fg_on = sfBlack;
    new_object->out_on = sfBlack;
    new_object->trigger = NULL;
    new_object->padding = (sfVector2f) { 0, 0 };

    set_object_defaults(adata, new_object);
    linked_add(adata->lists->objects, new_object);
}

void delete_object(app_data *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_DEL_ID")->format;
        my_printf(format, "OBJECT", id);
        return;
    }

    linked_node *objects = adata->lists->objects;
    int ite = 0;

    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        objects = objects->next;
    }

    linked_delete(&adata->lists->objects, ite);
}

void disable_object_click(app_data *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        char *format = get_msg(adata, "OBJECT_ERR_DISABLE_ID")->format;
        my_printf(format, "click function", "OBJECT");
        return;
    }

    object->properties &= ~obj_click;
}
