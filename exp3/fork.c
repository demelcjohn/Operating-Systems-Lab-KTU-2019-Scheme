#include<stdio.h> 
#include<stdlib.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<unistd.h> 

void main()
{

pid_t pid;
pid = fork();
printf("pid %d\n",pid);
if(pid==0)
{
printf("It is the child process and pid is %d\n",getpid());

for(int i=0;i<5;i++)
	printf("%d\n",i);

exit(0);

}
else if(pid > 0)
{

printf("It is the parent process and pid is %d\n",getpid());

int status;
wait(&status);
printf("Child is reaped\n");
}

else
{

printf("Error in forking..\n");
exit(EXIT_FAILURE);

}

}
