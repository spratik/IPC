#include <stdio.h>
#include <unistd.h>
#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Obtain O_* constant definitions */



int main()
{
	int p[2];
	char ch = 'a';
	pipe2(p, O_NONBLOCK);
	int count = 0;
	while(write(p[1], &ch, 1) != -1){
		count++;
		//printf("%d\n", count);
	}
		printf("%d\n", count);
	return 0;
}
