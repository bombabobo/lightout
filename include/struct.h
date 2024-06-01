#include "../include/my.h"

#ifndef STRUCT_H_
    #define STRUCT_H_
    #define TX_ sfTexture_createFromFile
    #define SC_ sfSprite_create
    #define SGLB_ sfSprite_getLocalBounds
    #define MGPR_ sfMouse_getPositionRenderWindow
    #define MSPR_ sfMouse_setPositionRenderWindow
    #define SSTR_ sfSprite_setTextureRect
    #define VCFR sfView_createFromRect
    #define SBCFF sfSoundBuffer_createFromFile
    #define DRAW_RECT_SHAPE sfRenderWindow_drawRectangleShape
    #define V2F (sfVector2f)

typedef struct light_cell {
    sfVector2f pos;
    int value;
}light;
typedef struct gamestruct {
    light light_grid[5][5];
    sfSprite *splight;
    sfSprite *spbackground;
    sfTexture *lighttex;
    sfTexture *bgtex;
    sfFont *font;
    sfText *clock;
    sfText *coups;
    sfClock *gameclock;
    int coups_nb;
    int GameOver;
}gstruct;

#endif /* !STRUCT_H_ */
