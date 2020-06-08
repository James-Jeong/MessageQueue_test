#pragma once

#ifndef _CLEINT_H_
#define _CLEINT_H_

#include <stdio.h>
#include <stdlib.h>

#include "jmp.h"

typedef struct client_s client_t;
struct client_s{
	int pid;
	char msg[ MAX_LEN];
};

client_t* client_init();
void client_destroy( client_t *client);
int client_process_msg( client_t *client, char *msg);
char* client_get_msg( client_t *client);
int client_print_msg( client_t *client);

#endif

