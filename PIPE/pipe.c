#include <stdio.h>
#include <unistd.h>


int main()
{
	int p[2];
	char str[100];
	char str1[100];
	pipe(p);
	if(fork() == 0){
		read(p[0], str1, sizeof(str1));
		printf("in child :: %s\n", str1);
	}else{
		printf("ENTER STRING :: ");
		scanf(" %s", &str);
		write(p[1], str, sizeof(str));
	}

	return 0;
}
