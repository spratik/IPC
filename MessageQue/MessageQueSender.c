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
	if(argc != 3){
		printf("USAGE :: EXE TYPE DATA\n");
		return 0;
	}

	int id = msgget(5, IPC_CREAT| 0644);

	if(id < 0){
		perror("msgget");
		return 0;
	}	
	printf("ID :: %d\n", id);	
	Msgbuf.mtype = atoi(argv[1]);
	strcpy(Msgbuf.data, argv[2]);
	
	msgsnd(id, &Msgbuf, sizeof(Msgbuf.data), 0);
	perror("msgsnd");
	
	return 0;
}
