#include "../include/my.h"

void key_events(sfRenderWindow *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
}

void clic_event(sfRenderWindow *window, gstruct *gstruct)
{
    sfVector2f mouse_pos = V2F {MGPR_(window).x, MGPR_(window).y};
    mouse_pos.x *= 1920.f / sfRenderWindow_getSize(window).x;
    mouse_pos.y *= 1080.f / sfRenderWindow_getSize(window).y;
    int i = (mouse_pos.x - 460) / 200;
    int j = (mouse_pos.y - 10) / 200;

    if ((mouse_pos.x < 460 || mouse_pos.x > 1460) || (mouse_pos.y < 20 || mouse_pos.y > 1020))
        return;
    gstruct->light_grid[i][j].value = (gstruct->light_grid[i][j].value) ? 0 : 1;
    if (j < 4)
        gstruct->light_grid[i][j+1].value = (gstruct->light_grid[i][j+1].value) ? 0 : 1;
    if (j > 0)
        gstruct->light_grid[i][j-1].value = (gstruct->light_grid[i][j-1].value) ? 0 : 1;
    if (i < 4)
        gstruct->light_grid[i+1][j].value = (gstruct->light_grid[i+1][j].value) ? 0 : 1;
    if (i > 0)
        gstruct->light_grid[i-1][j].value = (gstruct->light_grid[i-1][j].value) ? 0 : 1;
    gstruct->coups_nb++;
}

void test_table(gstruct *gstruct)
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (gstruct->light_grid[i][j].value == 1)
                return;
    random_tab_create(gstruct);
}

void analyse_events(sfRenderWindow *window, sfEvent *event, gstruct *gstruct)
{
    while (sfRenderWindow_pollEvent(window, event)){
        if (event->type == sfEvtKeyPressed)
            key_events(window);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event->type == sfEvtMouseButtonPressed)
            clic_event(window, gstruct);
    }
    test_table(gstruct);
}
