/*
** EPITECH PROJECT, 2020
** set_entity_properties.c
** File description:
** set_entity_properties.c
*/

#include "../../../../include/my_csfml.h"
#include "../../../../include/types_and_base/entity.h"
#include "../../../../include/utils/init/load_file.h"
#include "../../../../include/my.h"
#include "../../../../include/global_tabs.h"
#include "../../my_puterr.h"
#include "../common_tags.h"

void set_entity_name(char *content, int *i, entity_t *entity)
{
    int name_len = length_of_tag_value(content, *i);
    char *name = my_strndup(content + *i, name_len);
    entity->name = name;
    *i += name_len;
}

void set_entity_type(char *content, int *i, entity_t *entity)
{
    int type_len = length_of_tag_value(content, *i);
    char *type = my_strndup(content + *i, type_len);
    int k = 0;

    while (global_enum_tab[k].str && my_strncmp(global_enum_tab[k].str,
    content + *i, global_enum_tab[k].len))
        k++;
    if (!global_enum_tab[k].str)
        my_puterr("Unknown entity id", __FILE__, __LINE__);
    entity->type = global_enum_tab[k].enum_nb;
    *i += type_len;
}

void set_entity_toggle(char *content, int *i, entity_t *entity)
{
    entity->toggle = fill_toogle(content, i);
}