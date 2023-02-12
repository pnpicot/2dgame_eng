/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

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
    new_transform->scale = (sfVector2f) { 0, 0 };
    new_transform->ref = arg.ref;
    new_transform->ref_type = arg.type;
    new_transform->r_speed = arg.r_speed;
    new_transform->t_speed = 0;
    new_transform->s_speed = 0;
    new_transform->angle = arg.angle;
    new_transform->trsl = 0;
    new_transform->scl = 0;
    new_transform->rot = 1;
    new_transform->trf_type = TRF_ROTATE;

    linked_add(adata->lists->transforms, new_transform);
}

void scale(app_data *adata, s_trfarg arg)
{
    char *id = str_add("@PV_SCL-", nbr_to_str(rand() % 150000));
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
    new_transform->scale = arg.scale;
    new_transform->ref = arg.ref;
    new_transform->ref_type = arg.type;
    new_transform->s_speed = arg.s_speed;
    new_transform->t_speed = 0;
    new_transform->r_speed = 0;
    new_transform->angle = 0;
    new_transform->trsl = 0;
    new_transform->scl = 1;
    new_transform->rot = 0;
    new_transform->trf_type = TRF_SCALE;

    linked_add(adata->lists->transforms, new_transform);
}

void transform(app_data *adata, s_trfarg arg, float duration)
{
    sfVector2f pos = get_transform_pos(arg);
    sfVector2f scl = get_transform_scl(arg);
    float rot = get_transform_rot(arg);
    s_config *config = adata->config;

    duration /= 10.0f;
    float delta = (config->update_rate * get_vdist(pos, arg.dest)) * (duration / config->update_rate);

    float ang_diff = arg.angle - rot;

    if (ang_diff < 0) ang_diff *= -1;

    float trsl_delta = get_vdist(pos, arg.dest) / delta;
    float rot_delta = ang_diff / delta;
    float scl_delta = get_vdist(scl, arg.scale) / delta;
    char *id = str_add("@PV_TRS-", nbr_to_str(rand() % 150000));
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
    new_transform->scale = arg.scale;
    new_transform->ref = arg.ref;
    new_transform->ref_type = arg.type;
    new_transform->s_speed = scl_delta;
    new_transform->t_speed = trsl_delta;
    new_transform->r_speed = rot_delta;
    new_transform->angle = arg.angle;
    new_transform->trsl = 1;
    new_transform->scl = 1;
    new_transform->rot = 1;
    new_transform->trf_type = TRF_ALL;

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
    copy.t_speed = old->t_speed;
    copy.r_speed = old->r_speed;
    copy.s_speed = old->s_speed;
    copy.trf_type = old->trf_type;
    copy.angle = old->angle;

    return (copy);
}
