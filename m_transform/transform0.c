/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void update_scaling(app_data *adata, s_transform *transform)
{
    switch (transform->ref_type) {
        case TYPE_BUTTON:
            s_button *button = (s_button *) transform->ref;
            c_scl_button(adata, transform, button);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) transform->ref;
            c_scl_circle(adata, transform, circle);
            break;
        case TYPE_RECT:
            s_rect *rect = (s_rect *) transform->ref;
            c_scl_rect(adata, transform, rect);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) transform->ref;
            c_scl_text(adata, transform, text);
            break;
    }
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
            case TRF_ALL:
                update_translation(adata, cur);
                update_rotation(adata, cur);
                update_scaling(adata, cur);
                break;
        }

        transforms = transforms->next;
    }
}
