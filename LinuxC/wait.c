#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	char *message;
	int n;
	int exit_code;

	printf("fork program starting\n");
	pid = fork();
	switch(pid) {
		case -1: 
			perror("fork failed");
			exit(1);

		case 0:
			message = "This is the child";
			n = 5;
			exit_code = 37;
			break;

		case 1:
			message = "This is the parent";
			n = 3;
			exit_code = 0;
			break;
	}

	for(; n > 0; n--) { 
		puts(message);
		sleep(1);
	}
}