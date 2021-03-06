/*
** EPITECH PROJECT, 2020
** collison.c
** File description:
** header for collison.c
*/

#include "my_csfml.h"
#include "utils/converter.h"

sfBool circle_and_rectangle( sfCircleShape *circle,
sfRectangleShape *rect_coll, float radius);
sfBool circle_and_circle(sfCircleShape *c1, float r1,
sfCircleShape *c2, float r2);
sfBool rectangle_and_rectangle(sfRectangleShape *r1_coll,
sfRectangleShape *r2_coll);

void get_corners_position(sfFloatRect rect, sfVector2f tab[4])
{
    tab[0] = (sfVector2f){rect.left, rect.top};
    tab[1] = (sfVector2f){rect.left + rect.width, rect.top};
    tab[2] = (sfVector2f){rect.left, rect.top + rect.height};
    tab[3] = (sfVector2f){rect.left + rect.width, rect.top + rect.height};
}

sfBool check_circles(collider_t *entity, collider_t *collider)
{
    sfBool is_collide = sfFalse;

    if (entity->is_circle && !collider->is_circle)
        is_collide = circle_and_rectangle(entity->circ_collider,
        collider->rect_collider, entity->radius);
    else if (!entity->is_circle && collider->is_circle)
        is_collide = circle_and_rectangle(collider->circ_collider,
        entity->rect_collider, collider->radius);
    else
        is_collide = circle_and_circle(entity->circ_collider,
        entity->radius, collider->circ_collider, collider->radius);
    return is_collide;
}

int check_collide_script(entity_list_t *entity, entity_list_t *collider,
game_data_t *data, sfBool is_collide)
{
    int status = 1;

    if (is_collide) {
        if (entity->E_COLLIDER->on_collison && entity->entity->toggle &&
        collider && collider->entity && collider->entity->toggle)
            status = entity->E_COLLIDER->on_collison(entity->entity,
            collider->entity, data);
        if (status && entity->entity && entity->entity->toggle &&
            collider && collider->entity && collider->entity->toggle
            && collider->E_COLLIDER->on_collison)
            status = collider->E_COLLIDER->on_collison(collider->entity,
            entity->entity, data);
    }
    return status;
}

int check_collision(entity_list_t *entity, entity_list_t *collider,
game_data_t *data)
{
    sfBool is_collide = sfFalse;
    int status = 1;

    for (; status && entity->entity->toggle && collider;
    collider = collider->next) {
        if (collider->entity->toggle == OFF ||
            collider->E_COLLIDER->toggle == OFF)
            continue;
        if (entity->E_COLLIDER->is_circle || collider->E_COLLIDER->is_circle)
            is_collide = check_circles(entity->E_COLLIDER,
            collider->E_COLLIDER);
        else
             is_collide = rectangle_and_rectangle(
             entity->E_COLLIDER->rect_collider,
             collider->E_COLLIDER->rect_collider);
        status = check_collide_script(entity, collider, data, is_collide);
    }
    return status;
}

int physics_update(entity_list_t *entity, game_data_t *data)
{
    entity_list_t *list = entity;
    entity_list_t *colliders;

    if (!entity || !entity->next)
        return - 1;
    for (; list; list = list->next) {
        if (list->entity->toggle == OFF || list->E_COLLIDER->toggle == OFF)
            continue;
        if (!list->E_COLLIDER->is_circle && data->game_settings->debug == ON)
            sfRenderWindow_drawRectangleShape(G_WINDOW,
            list->E_COLLIDER->rect_collider, NULL);
        else if (data->game_settings->debug && list->E_COLLIDER->is_circle)
            sfRenderWindow_drawCircleShape(G_WINDOW,
            list->E_COLLIDER->circ_collider, NULL);
        colliders = list->next;
        if (!check_collision(list, colliders, data))
            return 0;
    }
    return 1;
}