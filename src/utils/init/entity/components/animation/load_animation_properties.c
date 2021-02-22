/*
** EPITECH PROJECT, 2020
** set_animation_properties.c
** File description:
** set_animation_properties.c
*/

#include <stdlib.h>
#include "my_csfml.h"
#include "utils/init/common_tags.h"
#include "utils/init/load_file.h"
#include "my.h"

void load_animation_toggle(char *content, int *i, animation_t *animation)
{
    animation->toggle = fill_toogle(content, i);
}

void load_animation_actual_anim(char *content, int *i, animation_t *animation)
{
    animation->actual_anim = fill_enum(content, i, anim_enum_tab);
}

void load_animation_anim_type(char *content, int *i, animation_t *anim)
{
    anim->type = fill_enum(content, i, anim_type_enum_tab);
}

void load_animation_actual_frame(char *content, int *i, animation_t *animation)
{
    char *value = extract_value(content, i);
    animation->actual_frame = my_getnbr(value);

    free(value);
}