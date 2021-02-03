/*
** EPITECH PROJECT, 2020
** free_components.c
** File description:
** header for free_components.c
*/

#include <stdlib.h>
#include "../../my_csfml.h"
#include "../../entity.h"
#include "../../scene.h"
#include "../../base_components.h"
#include "../../struct_shortcuts.h"
#include "../../../include/my.h"

void free_text(texts_t *texts)
{

    for (int i = 0; i < texts->count; i++) {
        if (texts->text[i].string)
            free(texts->text[i].string);
        if (texts->text[i].text)
            sfText_destroy(texts->text[i].text);
        if (texts->text[i].font)
            sfFont_destroy(texts->text[i].font);
    }
    if (texts->text != NULL)
        free(texts->text);
    if (texts != NULL)
        free(texts);
}

void free_rendersprite(render_sprite_t *render)
{
    if (render->sprite)
        sfSprite_destroy(render->sprite);
    if (render->texture)
        sfTexture_destroy(render->texture);
    if (render != NULL)
        free(render);
}

void free_sound_list(sfx_list_t *sounds)
{
    for (int i = 0; i < sounds->sfx_count; i++) {
        if (sounds->sfx[i].name)
            free(sounds->sfx[i].name);
        if (sounds->sfx[i].buff)
            sfSoundBuffer_destroy(sounds->sfx[i].buff);
        if (sounds->sfx[i].sfx)
            sfSound_destroy(sounds->sfx[i].sfx);
    }
    if (sounds->sfx != NULL)
        free(sounds->sfx);
    if (sounds != NULL)
        free(sounds);
}

void free_anim_list(anim_t *animation)
{
    if (animation->next)
        free_anim_list(animation->next);
    if (animation->anim)
        free(animation->anim);
    if (animation != NULL)
        free(animation);
}

void free_animation(animation_t *animation)
{
    if (animation->list)
        free_anim_list(animation->list);
    if (animation != NULL)
        free(animation);
}