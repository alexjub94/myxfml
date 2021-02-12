/*
** EPITECH PROJECT, 2020
** global_tabs.h
** File description:
** header for global_tabs.c
*/

#ifndef LIB_MYCSFML_GLOBAL_TABS_H
#define LIB_MYCSFML_GLOBAL_TABS_H

#include "types.h"

typedef struct global_enum_tab_s {
    char *str;
    int len;
    int enum_nb;
} global_enum_tab_t;

struct global_func_ptr_tab_s {
    char *str;
    int len;
    void *(*func_ptr)();
};

static const global_enum_tab_t global_enum_tab[] = {
        //
        //  entity_type
        //
        {"MOB", 3, MOB},
        {"PNJ", 3, PNJ},
        {"PLAYER", 6, PLAYER},
        {"WALL", 4, WALL},

        //
        // anim_type
        //
        {"IDLE", 4, IDLE},
        {"ATTACK", 6, ATTACK},
        {"DEFENSE", 7, DEFENSE},
        {"MOVING", 6, MOVING},
        {"HURT", 4, HURT},
        {"DEAD", 4, DEAD},
        {"DYING", 5, DYING},
        {"HOVER", 5, HOVER},
        {"CLICK", 5, CLICK},
        {"CUT_SCENE", 9, CUT_SCENE},

        //
        // anim
        //
        {"DEFAULT", 7, DEFAULT},
        {"ATTACK_SWORD", 12, ATTACK_SWORD},
        {"ATTACK_HAMMER", 13, ATTACK_HAMMER},
        {"ATTACK_BOW", 10, ATTACK_BOW},
        {"ATTACK_MAGIC", 12, ATTACK_MAGIC},
        {"ATTACK_MELEE", 12, ATTACK_MELEE},
        {"ATTACK_DASH", 11, ATTACK_DASH},
        {"ATTACK_CIRCLE", 13, ATTACK_CIRCLE},
        {"ATTACK_BACKSTAB", 15, ATTACK_BACKSTAB},
        {"DEFENSE_SHIELD", 14, DEFENSE_SHIELD},
        {"DEFENSE_BODY", 12, DEFENSE_BODY},
        {"DEFENSE_AVOID_LEFT", 18, DEFENSE_AVOID_LEFT},
        {"DEFENSE_AVOID_RIGHT", 19, DEFENSE_AVOID_RIGHT},
        {"DEFENSE_AVOID_TOP", 17, DEFENSE_AVOID_TOP},
        {"DEFENSE_AVOID_BOTTOM", 20, DEFENSE_AVOID_BOTTOM},
        {"HURT_PHYSIC", 11, HURT_PHYSIC},
        {"HURT_KNOCKBACK", 14, HURT_KNOCKBACK},
        {"IDLE_STATIC", 11, IDLE_STATIC},
        {"IDLE_TALK", 9, IDLE_TALK},
        {"IDLE_BORED", 10, IDLE_BORED},
        {"MOVING_WALK", 11, MOVING_WALK},
        {"MOVING_RUN", 10, MOVING_RUN},
        {"MOVING_DASH", 11, MOVING_DASH},
        {"MOVING_CLIMB", 12, MOVING_CLIMB},
        {"HOVER_ON", 8, HOVER_ON},
        {"HOVER_OFF", 9, HOVER_OFF},
        {"CLICK_ON", 8, CLICK_ON},
        {"CLICK_OFF", 9, CLICK_OFF},
        {"DYING_BURNER", 12, DYING_BURNED},
        {"DYING_FREEZED", 13, DYING_FREEZED},
        {"DYING_EXPLODING", 15, DYING_EXPLODING},
        {"DYING_SLICED", 12, DYING_SLICED},
        {"DYING_MELTED", 12, DYING_MELTED},
        {"SPAWNING", 8, SPAWNING},
        {"TALKING", 7, TALKING},
        {NULL, 0, 0}
};

static const struct global_func_ptr_tab_s scripts_func_ptr_tab[] = {
        {"my_putchar", 10, (void *(*)()) &my_putchar},
        {NULL, 0, NULL}
};

static const struct global_func_ptr_tab_s collider_func_ptr_tab[] = {
        {"my_putchar", 10, (void *(*)()) &my_putchar},
        {NULL, 0, NULL}
};

static const struct global_func_ptr_tab_s anim_func_ptr_tab[] = {
        {"my_putchar", 10, (void *(*)()) &my_putchar},
        {NULL, 0, NULL}
};

static const struct global_func_ptr_tab_s collider_func_ptr_tab2[] = {
        {NULL, 0, NULL}
};

#endif //LIB_MYCSFML_GLOBAL_TABS_H
