#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
printf("Shared memory Writing\n");
key_t key = ftok("shm_second.c",0);
void *shm_memory;
char buff[100];
int shmid;
shmid = shmget(key,1024,0666|IPC_CREAT);
printf("Shared memory created at : %d\n",shmid);
shm_memory = shmat(shmid,NULL,0);
printf("Process attached at %p\n",shm_memory);
printf("Enter data to memory location :\n ");
read(0,buff,100);
strcpy(shm_memory,buff);
printf("The contents in memory : %s",(char*)shm_memory);
}
