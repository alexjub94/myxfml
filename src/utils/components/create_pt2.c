/*
** EPITECH PROJECT, 2020
** create_pt2.c
** File description:
** header for create_pt2.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../../include/my_csfml.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/my.h"
#include "../my_puterr.h"

render_sprite_t *malloc_rendersprite(void)
{
    render_sprite_t *render = malloc(sizeof(render_sprite_t));

    if (render == NULL)
        my_puterr("Error : malloc rendersprite structure");
    render->texture = NULL;
    render->sprite = NULL;
    render->toggle = OFF;
    return render;
}

transform_t *malloc_transform(void)
{
    transform_t *transform = malloc(sizeof(transform_t));

    if (transform == NULL)
        my_puterr("Error : malloc transform structure");
    transform->velocity = (sfVector2f){0, 0};
    transform->position = (sfVector2f){0, 0};
    transform->scale = (sfVector2f){0, 0};
    return transform;
}

script_list_t *malloc_script_list(void)
{
    script_list_t *list = malloc(sizeof (script_list_t));

    if (list == NULL)
        my_puterr("Error : malloc script list structure");
    list->toggle = OFF;
    list->count = 0;
    list->list = NULL;
    return list;
}

script_t *malloc_script_node(void)
{
    script_t *script = malloc(sizeof(script_t));

    if (script == NULL)
        my_puterr("Error : malloc script node");
    script->toggle = OFF;
    script->time_dependent = OFF;
    script->data = NULL;
    script->name = NULL;
    script->next = NULL;
    script->actual = 0;
    script->trigger = 0;
    return script;
}

interact_t *malloc_interact(void)
{
    interact_t *new = malloc(sizeof(interact_t));

    if (new == NULL)
        my_puterr("Error : malloc interact structure");
    new->click_action = NULL;
    new->hoover_action = NULL;
    new->key_action = NULL;
    new->click = OFF;
    new->hoover = OFF;
    new->key = OFF;
    return new;
}