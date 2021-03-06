/*
** EPITECH PROJECT, 2020
** create_pt3.c
** File description:
** header for create_pt3.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_csfml.h"
#include "my_puterr.h"

sfx_list_t *malloc_sfx_list(void)
{
    sfx_list_t *new = malloc(sizeof(sfx_list_t));

    if (new == NULL)
        return my_puterr("Error : malloc sfx_list structure",
        __FILE__, __LINE__).ptr;
    new->toggle = OFF;
    new->sfx_count = 0;
    new->sfx = NULL;
    return new;
}

sound_t *malloc_sfx_array(int size)
{
    sound_t *new = malloc(sizeof(sound_t) * (size + 1));

    if (new == NULL)
        return my_puterr("Error : malloc sfx node", __FILE__, __LINE__).ptr;
    for (int i = 0; i < size; i++) {
        new[i].sfx = NULL;
        new[i].buff = NULL;
        new[i].name = NULL;
        new[i].type = 0;
    }
    return new;
}

texts_t *malloc_text_struct(void)
{
    texts_t *texts = malloc(sizeof(text_t));

    if (texts == NULL)
        return my_puterr("Error : malloc textS structure",
        __FILE__, __LINE__).ptr;
    texts->toggle = OFF;
    texts->count = 0;
    texts->text = NULL;
    return texts;
}

text_t *malloc_text_array(int size)
{
    text_t *new = malloc(sizeof(text_t) * (size + 1));

    if (new == NULL)
        return my_puterr("Error : malloc text array",
        __FILE__, __LINE__).ptr;
    for (int i = 0 ; i < size; i++) {
        new[i].size = 0;
        new[i].text = NULL;
        new[i].toggle = OFF;
        new[i].is_rslinked = OFF;
        new[i].font = NULL;
        new[i].string = NULL;
        new[i].id = NULL;
        new[i].pos = (sfVector2f){0, 0};
        new[i].offset = (sfVector2f){0, 0};
    }
    return new;
}