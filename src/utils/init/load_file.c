/*
** EPITECH PROJECT, 2020
** load_file.c
** File description:
** load_file.c
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include "../../../include/utils/init/load_file.h"
#include "../my_puterr.h"
#include "../../../include/my.h"

int length_of_tag_value(char *content, int i)
{
    int tmp = i;
    int k;

    skip_to_next_tag(content, &i, true);
    k = i;
    return k - tmp;
}

char *extract_value(char *content, int *i)
{
    int value_len = length_of_tag_value(content, *i);
    char *value = my_strndup(content + *i, value_len);
    *i += value_len;

    if (value == NULL)
        my_puterr("Malloc error in strndup", __FILE__, __LINE__);
    return value;
}

void skip_to_next_tag(char const *content, int *i, bool closing_tag)
{
    if (closing_tag) {
        for (; content[*i + 1]; *(i) += 1) {
            if (content[*i] == '<' && content[*i + 1] == '/')
                break;
        }
        if (!content[*i + 1])
            my_puterr("Error with entity config file", __FILE__, __LINE__);
    } else {
        for (; content[*i + 1]; *(i) += 1) {
            if (content[*i] != '<' && content[*i + 1] != '/')
                break;
        }
        if (!content[*i + 1])
            my_puterr("Error with entity config file", __FILE__, __LINE__);
    }
}

char *load_file(char *filepath)
{
    struct stat st;
    char *content = NULL;
    int fd = open(filepath, O_RDONLY);

    if (stat(filepath, &st) == -1 || !S_ISREG(st.st_mode) || fd < 0)
        my_puterr("Filepath is not a file", __FILE__, __LINE__);
    content = malloc(sizeof(char) * (st.st_size + 1));
    if (content == NULL)
        my_puterr("Error mallocing file content", __FILE__, __LINE__);
    if (read(fd, content, st.st_size) == -1)
        my_puterr("Error reading file content", __FILE__, __LINE__);
    close(fd);
    return content;
}