#include "../include/my.h"

void sp_upd(sfSprite *sprite, sfVector2f pos, sfRenderWindow *window)
{
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, 0);
}

void sp_upd_light(sfSprite *sprite, light light, sfRenderWindow *window)
{
    sfIntRect rect;
    rect.height = 200;
    rect.width = 200;
    rect.top = 0;
    rect.left = light.value * 200;
    sfSprite_setPosition(sprite, light.pos);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(window, sprite, 0);
}

void sp_upd_all(gstruct *gst, sfRenderWindow *window)
{
    int elapmi = sfTime_asMicroseconds(sfClock_getElapsedTime(gst->gameclock));
    float elapsedsec = elapmi / 1000000.f;
    char clock_buffer[5];
    char coup_buffer[5];

    sp_upd(gst->spbackground, (sfVector2f){0.f, 0.f}, window);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            sp_upd_light(gst->splight, gst->light_grid[i][j], window);
    snprintf(clock_buffer, sizeof(clock_buffer), "%.0f", elapsedsec);
    sfText_setString(gst->clock, clock_buffer);
    sfRenderWindow_drawText(window, gst->clock, NULL);
    snprintf(coup_buffer, sizeof(coup_buffer), "%d", gst->coups_nb);
    sfText_setString(gst->coups, coup_buffer);
    sfRenderWindow_drawText(window, gst->coups, NULL);
}
