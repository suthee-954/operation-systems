One way communication

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int fd[2];
	char buffer[100], as[100];
	pid_t p;

   
	pipe(fd);

   
	p = fork();
   
	if (p > 0) {  
    	printf("Parent pass value to child\n");
    	printf("Enter data: ");
    	fgets(as, 100, stdin);
    	close(fd[0]);  
    	write(fd[1], as, 100);  
    	close(fd[1]);  
    	wait(NULL);  
	}
	else if (p == 0) {  
  	 
    	close(fd[1]);  
    	read(fd[0], buffer, 100);  
    	printf("Child receives data\n");
    	printf("Buffer: %s", buffer);  
    	close(fd[0]);  
	}

	return 0;
}
