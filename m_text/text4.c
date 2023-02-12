/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void set_text_active(app_data *adata, char *id, sfUint8 active)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        char *format = get_msg(adata, "TEXT_ERR_SET_ID")->format;
        my_printf(format, "active", "TEXT");
        return;
    }

    text->active = active;
}
