#pragma once

#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>
#include <stdlib.h>

#include "jmp.h"

typedef struct server_s server_t;
struct server_s{
	int pid;
	char msg[ MAX_LEN];
};

server_t* server_init();
void server_destroy( server_t *server);
int server_process_msg( server_t *server);
char* server_get_msg( server_t *server);
int server_set_msg( server_t *server, char *msg);
int server_print_msg( server_t *server);

#endif

