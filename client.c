#include "client.h"

client_t* client_init(){
	client_t *client = ( client_t*)malloc( sizeof( client_t));
	client->pid = CLIENT;
	printf("@ Client pid : %d\n", client->pid);
	memset( client->msg, 0, sizeof( client->msg));
	return client;
}

void client_destroy( client_t *client){
	int msqid = 0;
	free( client);
}

int client_process_msg( client_t *client, char *data){
	if ( client){
		int rv = 0;
		rv = jmp_send_msg( SERVER, client_get_id( client), data);
		if ( rv >= 0){
			printf("@ Client send msg : [ %s ]\n", data);
			rv =  jmp_recv_msg( client->msg, client_get_id( client));
			if ( rv > 0) {
				printf("@ Client recv msg : [ %s ]\n", client->msg);
			}
			else {
				printf("! Client fail to recv msg\n");
				return -4;
			}
		}
		return rv;
	}
	else {
		printf("! Fail to get client object in client_send_msg\n");
		return -1;
	}
}

int client_get_id( client_t *client){
	if ( client){
		return client->pid;
	}
	else {
		printf("! Fail to get client object in client_get_id\n");
		return -1;
	}
}

char* client_get_msg( client_t *client){
	if ( client){
		if ( client->msg){
			return client->msg;
		}
		else{
			return NULL;
		}
	}
	else {
		printf("! Fail to get client object in client_get_msg\n");
		return NULL;
	}
}

int client_print_msg( client_t *client){
	if ( client == NULL){
		printf("! Fail to get client object in client_print_msg\n");
		return -1;
	}
	if ( client_get_msg( client)){
		printf("@ Data : %s\n", client_get_msg( client));
		return 1;
	}
	else {
		printf("! Fail to get msg from client object in client_print_msg\n");
		return -2;
	}
}

