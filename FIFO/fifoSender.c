#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	mkfifo("f1", 0666);
	perror("mkfifo");
	
	int fd = open("f1", O_WRONLY);
	if(fd == -1){
		perror("open");
		return 0;
	}
	char sender[100] = "pratik";
	write(fd, &sender, sizeof(sender));
	close(fd);
	return 0;
}	
