/*
** EPITECH PROJECT, 2020
** load_render_component.h
** File description:
** header for load_render_component.c
*/

#ifndef LIB_MYCSFML_LOAD_RENDER_COMPONENT_H
#define LIB_MYCSFML_LOAD_RENDER_COMPONENT_H

#include <stdlib.h>
#include "../../../../../../include/utils/init/conf_tag_action_struct.h"
#include "../../../../../../include/types.h"

void load_render_toggle(char *content, int *i, render_sprite_t *render);
void load_render_sprite(char *content, int *i, render_sprite_t *render);

static struct conf_tag_action_s render_conf_tag_action[] = {
        {"<toggle>", 8, (void *(*)()) &load_render_toggle},
        {"<path>", 6, (void *(*)()) &load_render_sprite},
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_LOAD_RENDER_COMPONENT_H