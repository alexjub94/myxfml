/*
** EPITECH PROJECT, 2020
** set_entity_properties.h
** File description:
** header for set_entity_properties.c
*/

#ifndef LIB_MYCSFML_SET_ENTITY_PROPERTIES_H
#define LIB_MYCSFML_SET_ENTITY_PROPERTIES_H

#include "my_xml.h"
#include "my_csfml.h"

int load_entity_name(xmlnode_t *node, entity_t *entity);
int load_entity_type(xmlnode_t *node, entity_t *entity);
int load_entity_toggle(xmlnode_t *node, entity_t *entity);
int load_entity_children(xmlnode_t *node, entity_t *entity);

#endif //LIB_MYCSFML_SET_ENTITY_PROPERTIES_H