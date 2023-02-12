/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void set_button_active(app_data *adata, char *id, sfUint8 active)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        char *format = get_msg(adata, "BUTTON_ERR_SET_ID")->format;
        my_printf(format, "active", "BUTTON");
        return;
    }

    button->rect->active = active;
    button->text->active = active;
}
