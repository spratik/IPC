#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	mkfifo("f1", 0666);
	perror("mkfifo");
	
	int fd = open("f1", O_RDONLY);
	if(fd == -1){
		perror("open");
		return 0;
	}
	char receiver[100];
	read(fd, &receiver, sizeof(receiver));
	printf("RECEIVER : %s\n", receiver);
	close(fd);
	return 0;
}	
