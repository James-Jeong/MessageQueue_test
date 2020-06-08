#include "server.h"

server_t* server_init(){
	server_t *server = ( server_t*)malloc( sizeof( server_t));
	server->pid = SERVER;
	printf("@ Server pid : %d\n", server->pid);
	memset( server->msg, 0, sizeof( server->msg));
	return server;
}

void server_destroy( server_t *server){
	int msqid = 0;
	if(( msqid = jmp_get_msgqid(( key_t)( KEY_MSG), FLG_MSG_CREAT)) == -1) {
		return;
	}
	if(jmp_check_msgq( msqid) > 0){
		msgctl( msqid, IPC_RMID, 0);
	}
	free( server);
}

int server_process_msg( server_t *server){
	if ( server){
		int rv = jmp_recv_msg( server->msg, server_get_id( server));
		if ( rv > 0){
			printf("@ Server recv msg : [ %s ]\n", server->msg);
			server_set_msg( server, "OK");
			rv = jmp_send_msg( CLIENT, server_get_id( server), server->msg);
			if( rv > 0) {
				printf("@ Server send msg : [ %s ]\n", server->msg);
			}
		}
		return rv;
	}
	else {
		printf("! Fail to get server object in server_send_msg\n");
		return -1;
	}
}

int server_get_id( server_t *server){
	if ( server){
		return server->pid;
	}
	else {
		printf("! Fail to get server object in server_get_id\n");
		return -1;
	}
}

char* server_get_msg( server_t *server){
	if ( server){
		if ( server->msg){
			return server->msg;
		}
		else{
			return NULL;
		}
	}
	else {
		printf("! Fail to get server object in server_get_msg\n");
		return NULL;
	}
}

int server_set_msg( server_t *server, char *msg){
	if ( server){
		memset( server->msg, 0, sizeof( server->msg));
		memcpy( server->msg, msg, strlen( msg));
		return 1;
	}
	else {
		printf("! Fail to get server object in server_get_msg\n");
		return -1;
	}

}

int server_print_msg( server_t *server){
	if ( server == NULL){
		printf("! Fail to get server object in server_print_msg\n");
		return -1;
	}
	if ( server_get_msg( server)){
		printf("@ Data : %s\n", server_get_msg( server));
		return 1;
	}
	else {
		printf("! Fail to get msg from server object in server_print_msg\n");
		return -2;
	}
}

