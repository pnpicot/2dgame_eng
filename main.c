/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

int main(int argc, char **argv)
{
    app_data *adata = malloc(sizeof(app_data));

    init_appdata(adata);
    create_window(adata);

    return (0);
}
