#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "server.h"
#include "client.h"

int main() {
	int status;
	pid_t pid = fork();

	if ( pid == 0) {
		// Client init (pthread)
		client_t *client = client_init();

		// Client processing
		client_process_msg( client, "HI");

		// Client destroy
		client_destroy(client);
	}
	else if ( pid > 0) {
		// Server init
		server_t *server = server_init();

		// Server processing
		server_process_msg( server);

		pid_t wait_pid = wait( &status);
		if( wait_pid == -1) {
			printf("! Fail to wait child process : %d\n", errno);
		}
		else{
			if( WIFEXITED( status)) {
				printf("! Normal termination of the child process : %d\n", WEXITSTATUS( status));
			}
			else if( WIFSIGNALED( status)) {
				printf("! Abnormal termination of the child process : %d\n", WTERMSIG( status));
			}
		}

		// Server destroy
		server_destroy( server);
	}
	else {
		printf("! Fail to fork\n");
		exit(-1);
	}
}
