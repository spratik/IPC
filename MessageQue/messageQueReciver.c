#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct msgBuf
{
	long mtype;
	char data[100];

}Msgbuf;

int main(int argc, char **argv)
{
	if(argc != 2){
		printf("USAGE :: EXE TYPE \n");
		return 0;
	}

	int id = msgget(5, IPC_CREAT| 0644);
	if(id < 0){
		perror("msgget");
		return 0;
	}	
	
	msgrcv(id, &Msgbuf, sizeof(Msgbuf.data),atoi(argv[1]) ,0);
	perror("msgrcv");
	
	printf("DATA ::%s\n", Msgbuf.data);
	return 0;
}
