#include "../include/my.h"
#include "../include/colors.h"

sfRenderWindow *create_render_window(void)
{
    sfVideoMode videoMode = {V_MODE};
    sfImage *icon = sfImage_createFromFile(LOGO);
    sfVector2u iconSize = sfImage_getSize(icon);
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);
    sfRenderWindow *window = sfRenderWindow_create(videoMode, TITLE, BSTYLE, 0);

    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, iconSize.x, iconSize.y, pixels);
    sfImage_destroy(icon);
    return window;
}

static void end(gstruct *gstruct, sfRenderWindow *window)
{
    sfSprite_destroy(gstruct->splight);
    sfSprite_destroy(gstruct->spbackground);
    sfTexture_destroy(gstruct->lighttex);
    sfTexture_destroy(gstruct->bgtex);
    sfClock_destroy(gstruct->gameclock);
    sfText_destroy(gstruct->coups);
    sfText_destroy(gstruct->clock);
    sfFont_destroy(gstruct->font);
    sfRenderWindow_destroy(window);
}

void lightout(gstruct *gstruct)
{
    sfRenderWindow *window = create_render_window();
    sfEvent event;

    create_sprites(gstruct);
    gstruct->gameclock = sfClock_create();
    sp_upd_all(gstruct, window);
    while (sfRenderWindow_isOpen(window)){
        sfRenderWindow_clear(window, sfBlack);
        sp_upd_all(gstruct, window);
        analyse_events(window, &event, gstruct);
        sfRenderWindow_display(window);
    }
    end(gstruct, window);
}

int main(int ac, char **av)
{
    gstruct gstruct;

    if (ac > 1 && !strcmp(av[1], "-h")){
        printf("%s\nthis programme is a lightout.\nwhen you clic on a light, "
        "it turn on/off every light around it, and itself.\n\nhave fun\n\n%s"
        , BHYEL, reset);
        return 0;
    }
    lightout(&gstruct);
    return 0;
}
