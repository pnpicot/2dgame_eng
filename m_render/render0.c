/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "../include/main.h"

void render_rtexs(app_data *adata, int depth)
{
    linked_node *rtexs = adata->lists->rtexs;
    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;
        if (cur->depth != depth) {
            rtexs = rtexs->next;
            continue;
        }
        render_elements(adata, cur, depth);
        s_rtex *g_next = get_rtex_d(adata, depth + 1);
        sfRenderTexture *next = depth == adata->max_rtex_depth ?
                                NULL : g_next->tex;
        const sfTexture *cur_tex = sfRenderTexture_getTexture(cur->tex);
        sfSprite_setTexture(cur->sprite, cur_tex, sfFalse);
        if (next == NULL || !g_next->inherit) {
            sfRenderWindow_drawSprite(adata->win, cur->sprite, cur->state);
        } else {
            sfRenderTexture_drawSprite(next, cur->sprite, cur->state);
        }
        rtexs = rtexs->next;
    }
}

void render_sprites(app_data *adata, int layer, int depth)
{
    linked_node *sprites = adata->lists->sprites;
    s_rtex *cur_rtex = get_rtex_d(adata, depth);

    while (sprites != NULL && sprites->data != NULL) {
        s_sprite *cur = (s_sprite *) sprites->data;

        if (!cur->active || cur->layer != layer || cur->rtex_id == NULL
            || cur_rtex == NULL || my_strcmp(cur_rtex->id, cur->rtex_id)) {
            sprites = sprites->next;
            continue;
        }

        sfRenderTexture_drawSprite(cur_rtex->tex, cur->elem, NULL);

        sprites = sprites->next;
    }
}

void display_rtexs(app_data *adata)
{
    linked_node *rtexs = adata->lists->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;

        sfRenderTexture_display(cur->tex);

        rtexs = rtexs->next;
    }
}

void clear_rtexs(app_data *adata)
{
    linked_node *rtexs = adata->lists->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;

        sfRenderTexture_clear(cur->tex, sfTransparent);

        rtexs = rtexs->next;
    }
}

void render(app_data *adata)
{
    s_clock *clocks = adata->clocks;
    s_config *config = adata->config;
    sfTime elapsed = sfClock_getElapsedTime(clocks->render_clock);
    float seconds = elapsed.microseconds / 1000000.0f;

    if (seconds >= config->render_rate) {
        sfRenderWindow_clear(adata->win, sfBlack);
        clear_rtexs(adata);

        for (int i = adata->min_rtex_depth; i <= adata->max_rtex_depth; i++) {
            render_rtexs(adata, i);
        }

        display_rtexs(adata);
        sfClock_restart(clocks->render_clock);
    }
}
