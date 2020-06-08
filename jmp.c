#include "jmp.h"

jmp_t* jmp_init(){
	jmp_t* msg = ( jmp_t*)malloc(sizeof( jmp_t));
	memset( msg->data, 0, sizeof( msg->data));
	return msg;
}

void jmp_destroy(jmp_t* msg){
	memset( msg->data, 0, jmp_get_msg_len(msg));
	free(msg);
}

int jmp_get_msg_len(jmp_t* msg){
	return strlen( msg->data);
}

int jmp_get_msg_size(){
	return sizeof( jmp_t) - sizeof( jmp_hd_t);
}

char* jmp_get_msg( jmp_t* msg){
	return msg->data;
}

int jmp_set_msg( jmp_t *msg, int type, char* data, int len, int cmd, int id){
	if( data != NULL){
		memset( msg->data, 0, MAX_LEN);
		memcpy( msg->data, data, len);
		msg->hd.mtype = type;
		msg->hd.len = strlen( msg->data) + sizeof( jmp_hd_t) + 1;
		msg->hd.cmd = cmd;
		msg->hd.id = id;
		return 1;
	}
	return -1;
}

int jmp_send_msg( int type, int id, char *data){
	int rv = 0, msg_size = jmp_get_msg_size();
	jmp_t msg;
	jmp_set_msg( &msg, type, data, strlen( data), 1, id);
	printf("| msg type : %d\n", msg.hd.mtype);
	printf("| msg len : %d\n", msg.hd.len);
	printf("| msg cmd : %d\n", msg.hd.cmd);
	printf("| msg id : %d\n", msg.hd.id);
	printf("| msg data : %s\n", msg.data);

	if (( rv = msgsnd( jmp_get_msgqid( ( key_t)KEY_MSG, FLG_MSG_CREAT), &msg, msg_size, 0)) == -1){
		printf("! Fail to send msg in jmp_send_msg\n");
		return -3;
	}
	else {
		return 1;
	}
}

int jmp_recv_msg( char *rcv_data, int id){
	ssize_t rcv_bytes = 0;
	int msg_size = jmp_get_msg_size();
	jmp_t msg;
	rcv_bytes = msgrcv( jmp_get_msgqid( ( key_t)KEY_MSG, FLG_MSG_CREAT), &msg, msg_size, id, 0);
	if ( rcv_bytes > 0){
		memcpy( rcv_data, msg.data, strlen( msg.data));
		return 1;
	}
	else {
		printf("! Fail to recv msg in jmp_recv_msg\n");
		return -1;
	}
}

int jmp_check_msgq( int msq_id){
	struct msqid_ds msqstat;
	if(msgctl(msq_id, IPC_STAT, &msqstat) < 0){
		perror("! msqctl() / IPC_STAT");
		return -1;
	}
	if(msqstat.msg_qnum > 0){
		return 1;
	}
	else{
		return -1;
	}
}

int jmp_get_msgqid( key_t msg_key, int msg_flg){
	int msqid = 0;
	if((msqid = msgget(msg_key, msg_flg)) < 0){
		perror("! Fail to make a message queue }");
		return -1;
	}
	return msqid;
}

