/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

s_transform *get_transform(app_data *adata, char *id)
{
    linked_node *transforms = adata->lists->transforms;

    while (transforms != NULL && transforms->data != NULL) {
        s_transform *cur = (s_transform *) transforms->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        transforms = transforms->next;
    }

    return (NULL);
}

void translate(app_data *adata, s_trfarg arg)
{
    char *id = str_add("@PV_TRF-", nbr_to_str(rand() % 150000));
    s_transform *transform = get_transform(adata, id);

    if (transform != NULL) {
        char *format = get_msg(adata, "TRANSFORM_ERR_ADD_ID")->format;
        my_printf(format, id);
        return;
    }

    s_transform *new_transform = malloc(sizeof(s_transform));
    new_transform->id = id;
    new_transform->callback = arg.callback;
    new_transform->dest = arg.dest;
    new_transform->ref = arg.ref;
    new_transform->ref_type = arg.type;
    new_transform->speed = arg.speed;
    new_transform->angle = 0;
    new_transform->trsl = 1;
    new_transform->scl = 0;
    new_transform->rot = 0;
    new_transform->trf_type = TRF_TRANSLATE;

    linked_add(adata->lists->transforms, new_transform);
}

void rotate(app_data *adata, s_trfarg arg)
{
    char *id = str_add("@PV_ROT-", nbr_to_str(rand() % 150000));
    s_transform *transform = get_transform(adata, id);

    if (transform != NULL) {
        char *format = get_msg(adata, "TRANSFORM_ERR_ADD_ID")->format;
        my_printf(format, id);
        return;
    }

    s_transform *new_transform = malloc(sizeof(s_transform));
    new_transform->id = id;
    new_transform->callback = arg.callback;
    new_transform->dest = (sfVector2f) { 0, 0 };
    new_transform->ref = arg.ref;
    new_transform->ref_type = arg.type;
    new_transform->speed = arg.speed;
    new_transform->angle = arg.angle;
    new_transform->trsl = 0;
    new_transform->scl = 0;
    new_transform->rot = 1;
    new_transform->trf_type = TRF_ROTATE;

    linked_add(adata->lists->transforms, new_transform);
}

void delete_transform(app_data *adata, char *id)
{
    s_transform *transform = get_transform(adata, id);

    if (transform == NULL) {
        char *format = get_msg(adata, "TRANSFORM_ERR_DEL_ID")->format;
        my_printf(format, id);
        return;
    }

    linked_node *transforms = adata->lists->transforms;
    int ite = 0;

    while (transforms != NULL && transforms->data != NULL) {
        s_transform *cur = (s_transform *) transforms->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        transforms = transforms->next;
    }

    linked_delete(&adata->lists->transforms, ite);
}

s_transform copy_transform(s_transform *old)
{
    s_transform copy;
    copy.callback = old->callback;
    copy.dest = old->dest;
    copy.id = old->id;
    copy.ref = old->ref;
    copy.ref_type = old->ref_type;
    copy.speed = old->speed;
    copy.trf_type = old->trf_type;
    copy.angle = old->angle;

    return (copy);
}

void c_rot_button(app_data *adata, s_transform *transform, s_button *button)
{
    float angle = sfRectangleShape_getRotation(button->rect->elem);
    float speed = transform->angle < angle ?
        -1 * transform->speed : transform->speed;

    float diff = transform->angle - angle;

    if (diff >= TRANSFORM_TOLERANCE + transform->speed) {
        speed = speed <= diff ? speed : speed - diff;
        angle += speed;

        sfRectangleShape_setRotation(button->rect->elem, angle);
        sfText_setRotation(button->text->elem, angle);
        update_button(adata, button);
    } else {
        if (transform->callback != NULL)
            (*transform->callback)(adata, copy_transform(transform));

        sfRectangleShape_setRotation(button->rect->elem, transform->angle);
        sfText_setRotation(button->text->elem, transform->angle);
        update_button(adata, button);

        transform->rot = 2;
        sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
            || !transform->trsl) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
    }
}

void c_rot_circle(app_data *adata, s_transform *transform, s_circle *circle)
{
    float angle = sfCircleShape_getRotation(circle->elem);
    float speed = transform->angle < angle ?
        -1 * transform->speed : transform->speed;

    float diff = transform->angle - angle;

    if (diff >= TRANSFORM_TOLERANCE + transform->speed) {
        speed = speed <= diff ? speed : speed - diff;
        angle += speed;

        sfCircleShape_setRotation(circle->elem, angle);
    } else {
        if (transform->callback != NULL)
            (*transform->callback)(adata, copy_transform(transform));

        sfCircleShape_setRotation(circle->elem, transform->angle);

        transform->rot = 2;
        sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
            || !transform->trsl) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
    }
}

void c_rot_rect(app_data *adata, s_transform *transform, s_rect *rect)
{
    float angle = sfRectangleShape_getRotation(rect->elem);
    float speed = transform->angle < angle ?
        -1 * transform->speed : transform->speed;

    float diff = transform->angle - angle;

    if (diff >= TRANSFORM_TOLERANCE + transform->speed) {
        speed = speed <= diff ? speed : speed - diff;
        angle += speed;

        sfRectangleShape_setRotation(rect->elem, angle);
    } else {
        if (transform->callback != NULL)
            (*transform->callback)(adata, copy_transform(transform));

        sfRectangleShape_setRotation(rect->elem, transform->angle);

        transform->rot = 2;
        sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
            || !transform->trsl) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
    }
}

void c_rot_text(app_data *adata, s_transform *transform, s_text *text)
{
    float angle = sfText_getRotation(text->elem);
    float speed = transform->angle < angle ?
        -1 * transform->speed : transform->speed;

    float diff = transform->angle - angle;

    if (diff >= TRANSFORM_TOLERANCE + transform->speed) {
        speed = speed <= diff ? speed : speed - diff;
        angle += speed;

        sfText_setRotation(text->elem, angle);
    } else {
        if (transform->callback != NULL)
            (*transform->callback)(adata, copy_transform(transform));

        sfText_setRotation(text->elem, transform->angle);

        transform->rot = 2;
        sfUint8 end = (transform->rot == 2) && (transform->trsl == 2
            || !transform->trsl) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
    }
}

void c_trsl_button(app_data *adata, s_transform *transform, s_button *button)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->rect->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - pos.x;
    dist_vec.y = transform->dest.y - pos.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= TRANSFORM_TOLERANCE + transform->speed) {
        float speed = my_abs(transform->speed <= dist ?
            transform->speed : transform->speed - dist);

        pos.x += (speed / dist) * dist_vec.x;
        pos.y += (speed / dist) * dist_vec.y;

        sfRectangleShape_setPosition(button->rect->elem, pos);
        update_button(adata, button);
    } else {
        if (transform->callback != NULL)
            (*transform->callback)(adata, copy_transform(transform));

        sfRectangleShape_setPosition(button->rect->elem, transform->dest);
        update_button(adata, button);

        transform->trsl = 2;
        sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
    }
}

void c_trsl_circle(app_data *adata, s_transform *transform, s_circle *circle)
{
    sfVector2f pos = sfCircleShape_getPosition(circle->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - pos.x;
    dist_vec.y = transform->dest.y - pos.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= TRANSFORM_TOLERANCE + transform->speed) {
        float speed = my_abs(transform->speed <= dist ?
            transform->speed : transform->speed - dist);

        pos.x += (speed / dist) * dist_vec.x;
        pos.y += (speed / dist) * dist_vec.y;

        sfCircleShape_setPosition(circle->elem, pos);
    } else {
        if (transform->callback != NULL)
            (*transform->callback)(adata, copy_transform(transform));

        sfCircleShape_setPosition(circle->elem, transform->dest);

        transform->trsl = 2;
        sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
    }
}

void c_trsl_rect(app_data *adata, s_transform *transform, s_rect *rect)
{
    sfVector2f pos = sfRectangleShape_getPosition(rect->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - pos.x;
    dist_vec.y = transform->dest.y - pos.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= TRANSFORM_TOLERANCE + transform->speed) {
        float speed = my_abs(transform->speed <= dist ?
            transform->speed : transform->speed - dist);

        pos.x += (speed / dist) * dist_vec.x;
        pos.y += (speed / dist) * dist_vec.y;

        sfRectangleShape_setPosition(rect->elem, pos);
    } else {
        if (transform->callback != NULL)
            (*transform->callback)(adata, copy_transform(transform));

        sfRectangleShape_setPosition(rect->elem, transform->dest);

        transform->trsl = 2;
        sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
    }
}

void c_trsl_text(app_data *adata, s_transform *transform, s_text *text)
{
    sfVector2f pos = sfText_getPosition(text->elem);

    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - pos.x;
    dist_vec.y = transform->dest.y - pos.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    if (dist >= TRANSFORM_TOLERANCE + transform->speed) {
        float speed = my_abs(transform->speed <= dist ?
            transform->speed : transform->speed - dist);

        pos.x += (speed / dist) * dist_vec.x;
        pos.y += (speed / dist) * dist_vec.y;

        sfText_setPosition(text->elem, pos);
    } else {
        if (transform->callback != NULL)
            (*transform->callback)(adata, copy_transform(transform));

        transform->trsl = 2;
        sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->scl == 2 || !transform->scl);

        sfText_setPosition(text->elem, transform->dest);

        if (end) delete_transform(adata, transform->id);
    }
}

void c_trsl_vertex(app_data *adata, s_transform *transform, s_vertex *vertex)
{
    sfVertex *first_vert = sfVertexArray_getVertex(vertex->elem, 0);

    sfVector2f dist_vec;
    dist_vec.x = transform->dest.x - first_vert->position.x;
    dist_vec.y = transform->dest.y - first_vert->position.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));
    int count = get_vertex_size(adata, vertex->id);
    float speed = my_abs(transform->speed <= dist ?
            transform->speed : transform->speed - dist);

    if (dist >= TRANSFORM_TOLERANCE + transform->speed) {
        for (int i = 0; i < count; i++) {
            sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, i);
            u_vert->position.x += (speed / dist) * dist_vec.x;
            u_vert->position.y += (speed / dist) * dist_vec.y;
        }
    } else {
        if (transform->callback != NULL)
            (*transform->callback)(adata, copy_transform(transform));

        for (int i = 0; i < count; i++) {
            sfVertex *u_vert = sfVertexArray_getVertex(vertex->elem, i);
            u_vert->position.x += (speed / dist) * dist_vec.x;
            u_vert->position.y += (speed / dist) * dist_vec.y;
        }

        transform->trsl = 2;
        sfUint8 end = (transform->trsl == 2) && (transform->rot == 2
            || !transform->rot) && (transform->scl == 2 || !transform->scl);

        if (end) delete_transform(adata, transform->id);
    }
}

void update_translation(app_data *adata, s_transform *transform)
{
    switch (transform->ref_type) {
        case TYPE_BUTTON:
            s_button *button = (s_button *) transform->ref;
            c_trsl_button(adata, transform, button);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) transform->ref;
            c_trsl_circle(adata, transform, circle);
            break;
        case TYPE_RECT:
            s_rect *rect = (s_rect *) transform->ref;
            c_trsl_rect(adata, transform, rect);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) transform->ref;
            c_trsl_text(adata, transform, text);
            break;
        case TYPE_VERTEX:
            s_vertex *vertex = (s_vertex *) transform->ref;
            c_trsl_vertex(adata, transform, vertex);
            break;
    }
}

// TODO: rotation, scaling, tranform() => can make all 3 at the same time and calculate the speed for all of them based on a given transformation time from point A to point B (+ coding-style)

void update_rotation(app_data *adata, s_transform *transform)
{
    switch (transform->ref_type) {
        case TYPE_BUTTON:
            s_button *button = (s_button *) transform->ref;
            c_rot_button(adata, transform, button);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) transform->ref;
            c_rot_circle(adata, transform, circle);
            break;
        case TYPE_RECT:
            s_rect *rect = (s_rect *) transform->ref;
            c_rot_rect(adata, transform, rect);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) transform->ref;
            c_rot_text(adata, transform, text);
            break;
    }
}

void update_scaling(app_data *adata, s_transform *transform)
{
    // ...
}

void update_transforms(app_data *adata)
{
    linked_node *transforms = adata->lists->transforms;

    while (transforms != NULL && transforms->data != NULL) {
        s_transform *cur = (s_transform *) transforms->data;

        switch (cur->trf_type) {
            case TRF_TRANSLATE:
                update_translation(adata, cur);
                break;
            case TRF_ROTATE:
                update_rotation(adata, cur);
                break;
            case TRF_SCALE:
                update_scaling(adata, cur);
                break;
        }

        transforms = transforms->next;
    }
}
