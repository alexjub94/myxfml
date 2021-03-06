/*
** EPITECH PROJECT, 2020
** remove.c
** File description:
** header for remove.c
*/

#include <stdlib.h>
#include "my_csfml.h"

void swap_actual_tolist(entity_list_t **from, entity_list_t **to)
{
    entity_t *e = pop_actual_fromlist(from);

    add_entity_to_list(e, to);
}

void remove_actual_fromlist(entity_list_t **entity)
{
    entity_t *e = pop_actual_fromlist(entity);

    remove_entity(e);
}

entity_t *pop_entity_fromlist(entity_t *entity, entity_list_t **list)
{
    entity_list_t *entity_list = *list;
    int i = 0;

    while (entity_list && entity_list->entity != entity) {
        (entity_list) = (entity_list)->next;
        i++;
    }
    if ((entity_list) != NULL)
        return pop_actual_fromlist(&entity_list);
    return NULL;
}

entity_t *pop_actual_fromlist(entity_list_t **list)
{
    entity_t *to_pop = (*list)->entity;
    entity_list_t *to_delete = (*list);
    
    if((*list)->back && (*list)->next) {
        (*list)->back->next = (*list)->next;
        (*list)->next->back = (*list)->back;
        (*list) = (*list)->back;
    } else if ((*list)->back) {
        (*list)->back->next = NULL;
        (*list) = (*list)->back;
    } if ((*list)->next && !(*list)->back) {
        to_delete = (*list)->next;
        (*list)->entity = (*list)->next->entity;
        if ((*list)->next->next) {
            (*list)->next = (*list)->next->next;
            (*list)->next->next->back = (*list);
        } else {
            (*list)->next = NULL;
        }
    } else if (!(*list)->next && !(*list)->back){
        (*list) = NULL;
    }
    to_delete->next = NULL;
    to_delete->back = NULL;
    to_delete->entity = NULL;
    free(to_delete);
    return to_pop;
}

void remove_entity(entity_t *entity)
{
    entity_t *to_delete = entity;

    if (entity->back && entity->next)
        entity->back->next = entity->next;
    if (!entity->back) {
        entity = entity->next;
        entity->back = NULL;
    }
    if (!entity->next)
        entity = entity->back;
    if (to_delete->children)
        free_entity_list(entity->children);
    free_entity(to_delete);
}