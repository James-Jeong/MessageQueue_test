#pragma once

#ifndef _JMP_H_
#define _JMP_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SERVER 1
#define CLIENT 2
#define KEY_MSG 1234
#define MAX_LEN 50
#define FLG_MSG_CREAT ( IPC_CREAT | 0666)

typedef struct jmp_hd_s jmp_hd_t;
struct jmp_hd_s{
	long mtype;
	uint32_t len;
	uint32_t cmd;
	uint32_t id;
};

typedef struct jmp_s jmp_t;
struct jmp_s{
	jmp_hd_t hd;
	char data[ MAX_LEN];
};

jmp_t* jmp_init();
void jmp_destroy( jmp_t *msg);
int jmp_get_msg_len( jmp_t *msg);
int jmp_get_msg_size();
char* jmp_get_msg( jmp_t *msg);
int jmp_set_msg( jmp_t *msg, int type, char *data, int len, int cmd, int id);
int jmp_send_msg( int type, int id, char *data);
int jmp_recv_msg( char *rcv_data, int pid);
int jmp_check_msgq( int msq_id);
int jmp_get_msgqid( key_t msg_key, int msg_flg);
int jmp_get_hd_mtype( jmp_t *msg);

#endif

