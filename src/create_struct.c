#include "../include/my.h"

void random_tab_create(gstruct *gstruct)
{
    int elapmi = sfTime_asMicroseconds(sfClock_getElapsedTime(gstruct->gameclock));
    char ftab[5][5];
    char tab[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            ftab[i][j] = rand() % elapmi % 2;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (ftab[i][j]){
                tab[i][j] = (tab[i][j]) ? 0 : 1;
                if (j < 4)
                    tab[i][j+1] = (tab[i][j+1]) ? 0 : 1;
                if (j > 0)
                    tab[i][j-1] = (tab[i][j-1]) ? 0 : 1;
                if (i < 4)
                    tab[i+1][j] = (tab[i+1][j]) ? 0 : 1;
                if (i > 0)
                    tab[i-1][j] = (tab[i-1][j]) ? 0 : 1;
            }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            gstruct->light_grid[i][j].value = tab[i][j];
    gstruct->coups_nb = 0;
}

void create_text(gstruct *gstruct)
{
    gstruct->coups = sfText_create();
    sfText_setCharacterSize(gstruct->coups, 100);
    sfText_setFont(gstruct->coups, gstruct->font);
    sfText_setColor(gstruct->coups, sfYellow);
    sfText_setPosition(gstruct->coups, (sfVector2f){20, 20});
    gstruct->clock = sfText_create();
    sfText_setCharacterSize(gstruct->clock, 100);
    sfText_setFont(gstruct->clock, gstruct->font);
    sfText_setColor(gstruct->clock, sfRed);
    sfText_setPosition(gstruct->clock, (sfVector2f){1700, 20});
}

void create_sprites(gstruct *gstruct)
{
    gstruct->lighttex = sfTexture_createFromFile(LIGHT_, 0);
    gstruct->bgtex = sfTexture_createFromFile(BG_, 0);
    gstruct->splight = sfSprite_create();
    gstruct->spbackground = sfSprite_create();
    gstruct->font = sfFont_createFromFile(FONT_);
    sfSprite_setTexture(gstruct->splight, gstruct->lighttex, sfFalse);
    sfSprite_setTexture(gstruct->spbackground, gstruct->bgtex, sfFalse);
    create_text(gstruct);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++){
            gstruct->light_grid[i][j].pos.x = 460 + i * 200;
            gstruct->light_grid[i][j].pos.y = 10 + j * 200;
        }
    random_tab_create(gstruct);
}
