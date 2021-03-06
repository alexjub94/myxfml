/*
** EPITECH PROJECT, 2020
** create.c
** File description:
** header for create.c
*/

#include <stdlib.h>
#include "my_csfml.h"
#include "my_puterr.h"

game_data_t *malloc_game_data(void)
{
    game_data_t *new = malloc(sizeof(game_data_t));

    if (new == NULL)
        return (game_data_t *)my_puterr("Error malloc game data",
        __FILE__, __LINE__).ptr;
    new->player = NULL;
    new->global_entity = NULL;
    new->gui = NULL;
    new->game_settings = NULL;
    new->stats = NULL;
    new->scenes = NULL;
    return new;
}

game_stats_t *malloc_game_stats(void)
{
    game_stats_t *new = malloc(sizeof(game_stats_t));

    if (new == NULL)
        return (game_stats_t *)my_puterr("Error malloc game stats",
        __FILE__, __LINE__).ptr;
    new->time = NULL;
    new->event = NULL;
    new->camera = NULL;
    return new;
}

settings_t *malloc_settings(void)
{
    settings_t *new = malloc(sizeof(settings_t));

    if (new == NULL)
        return (settings_t *)my_puterr("Error malloc game settings",
        __FILE__, __LINE__).ptr;
    new->video = NULL;
    new->audio = NULL;
    return new;
}

time_stats_t *malloc_time_stats(void)
{
    time_stats_t *new = malloc(sizeof(time_stats_t));

    if (new == NULL)
        return (time_stats_t *)my_puterr("Error malloc time stats",
        __FILE__, __LINE__).ptr;
    new->time = 0;
    new->game_clock = NULL;
    return new;
}