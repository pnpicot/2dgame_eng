/*
** EPITECH PROJECT, 2022
** Game_eng
** File description:
** Game_eng
*/

#include "include/main.h"

s_msg *get_msg(app_data *adata, char *id)
{
    linked_node *messages = adata->lists->messages;

    while (messages != NULL && messages->data != NULL) {
        s_msg *cur = (s_msg *) messages->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        messages = messages->next;
    }

    my_printf("Cannot retrieve message with id \"%s\" (unknown id).\n", id);

    return (NULL);
}

void init_messages(app_data *adata)
{
    char *file_content = file_extract("bonus/messages.data");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_split(entries[ite], '=');
        char *id = substr(entry_data[0], 0, my_strlen(entry_data[0]) - 2);
        char *format = substr(entry_data[1], 1, my_strlen(entry_data[1]) - 1);
        s_msg *new_message = malloc(sizeof(s_msg));
        new_message->id = id;
        new_message->format = str_add(format, "\n");
        linked_add(adata->lists->messages, new_message);
        ite++;
    }
}
