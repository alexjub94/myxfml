/*
** EPITECH PROJECT, 2020
** free_entity.c
** File description:
** header for free_entity.c
*/

#include <stdlib.h>
#include "../../../include/my_csfml.h"
#include "../../../include/types_and_base/entity.h"
#include "../../../include/types_and_base/scene.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/types_and_base/struct_shortcuts.h"
#include "../../../include/my.h"

static void free_independant_components(entity_t *entity)
{
    if (entity->name)
        free(entity->name);
    if (entity->path)
        free(entity->path);
    if (E_TRANSFORM)
        free(E_TRANSFORM);
    if (E_COLLIDER)
        free(E_COLLIDER);
    if (E_INTERACT)
        free(E_INTERACT);
}


void free_entity(entity_t *entity)
{
    if (entity != NULL && entity->components != NULL) {
        free_independant_components(entity);
        if (E_TEXT)
            free_text(E_TEXT);
        if (E_SOUND)
            free_sound_list(E_SOUND);
        if (E_RSPRITE)
            free_rendersprite(E_RSPRITE);
        if (E_SCRIPT)
            free_script_list(E_SCRIPT);
        if (E_ANIMATION)
            free_animation(E_ANIMATION);
        free(entity->components);
        free(entity);
    }
    entity = NULL;
}

void free_entity_list(entity_t *entity)
{
    if (entity->children)
        free_entity_list(entity->children);
    if (entity->next)
        free_entity_list(entity->next);
    free_entity(entity);
}


void free_entites_list(entity_list_t *entity)
{
    if(entity == NULL)
        return;
    if (entity->next)
        free_entites_list(entity->next);
    if (entity->entity)
        free_entity(entity->entity);
    if (entity != NULL)
        free(entity);
    entity = NULL;
}