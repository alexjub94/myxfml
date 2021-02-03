/*
** EPITECH PROJECT, 2020
** base_components.h
** File description:
** header for base_components.c
*/

#ifndef LIBCSFML_BASE_COMPONENTS_H
#define LIBCSFML_BASE_COMPONENTS_H

#include "my_csfml.h"

        ////////////////////////////////
        //      BASE COMPONENTS       //
        ////////////////////////////////


//
//  Action_trigger_component
//
struct action_trigger_s{
    toggle_t toggle;
    char *action_name;
    id type;
    int trigger;
    int actual;
};
struct trigger_s{
    action_trigger_t *trigger;
    int count;
    int actual;
};


//
//  tag_components
//
struct tag_s{
    toggle_t toggle;
    char *tag;
    id type;
    void *action;
    struct tag_s *next;
};

struct tag_list_s{
    toggle_t toggle;
    tag_t *list;
    tag_t *(*get_tag)(struct tag_list_s *tags, char *tag);
    void (*add_tag)(struct tag_list_s *tags, char *tag);
    sfBool (*remove_tag)(struct tag_list_s *tags, char *tag);
    sfBool (*is_tag)(struct tag_list_s *tags, char *tag);
    int count;
};



//
//  Collider_Component
//
struct collider_s{
    toggle_t toggle;
    toggle_t is_rs_linked;
    sfVector2f position;
    sfVector2f dimensions;
    void (* on_collison)(entity_t *self, entity_t *collider,
            game_data_t *data, entity_list_t *list);
};



//
//  RenderSprite_Component
//
struct render_sprite_s {
    toggle_t toggle;
    sfSprite *sprite;
    sfTexture *texture;
};



//
//  Transform_Component
//
struct transform_s {
    sfVector2f position;
    sfVector2f scale;
    sfVector2f velocity;
};



//
// Sound_component
//
struct sound_s{
    char *name;
    anim type;
    sfSound *sfx;
    sfSoundBuffer *buff;
    int actual;
    int trigger;
};

struct sfx_list_s{
    toggle_t toggle;
    sound_t *sfx;
    int sfx_count;
};



//
// Text_component
//
struct text_s{
    toggle_t toggle;
    sfText *text;
    sfFont *font;
    char *string;
    int size;
    sfVector2f pos;
};

struct texts_s{
    toggle_t toggle;
    text_t *text;
    int count;
};



//
//  Interact_component
//
struct interact_s{
    toggle_t toggle;
    toggle_t click;
    toggle_t hoover;
    toggle_t key;
    void (* click_action)(entity_t *entity, game_data_t *data);
    void (* hoover_action)(entity_t *entity, game_data_t *data);
    void (* key_action)(entity_t *entity, game_data_t *data);
};



//
//  Animation_component
//
struct animation_s{
    toggle_t toggle;
    int actual_frame;
    anim_type type;
    anim_t *list;
    anim_t *actual;
};

struct anim_s{
    toggle_t toggle;
    int frames_count;
    anim name;
    frame_t *anim;
    void (* frame_action)(game_data_t *data, entity_t *entity, animation_t *a);
    anim_t *next;
};

struct frame_s{
    sfIntRect crop;
    int trigger;
    int actual;
};

//
//  Script Component
//
struct script_s{
    toggle_t toggle;
    toggle_t time_dependent;
    int trigger;
    int actual;
    char *name;
    void *data;
    void *(*update)(void *data, game_data_t *game, entity_t *entity);
    script_t *next;
};




//
//  Script Initialization Exemple
//

/*
typedef struct attack_stats attact_stats_t;
typedef struct defense_stats defense_stats_t;
typedef struct support_stats support_stats_t;
typedef struct crowd_control_control crowd_control_t;

typedef struct ability_s ability_t;
typedef enum ability_typ {MAGIC_ATTACK}ability_type;
// donnee type
struct ability_s{
    ability_type type;
    attact_stats_t *attack;
    defense_stats_t *defense;
    support_stats_t *support;
    crowd_control_t *cc_stats;
};
*/


#endif //LIBCSFML_BASE_COMPONENTS_H