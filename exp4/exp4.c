#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
void main(){
	int p1,p2;
	char s[20];
	p1=open("file.txt",O_RDWR);
	char data[]="This is the data entered";
	if(p1!=-1){
		printf("File Opened\n");
		write(p1,data,sizeof(data));
		printf("Data added to file:\n");
		close(p1);
		printf("File closed\n");
	}
	p2=open("file.txt",O_RDWR);
	if(p2!=-1){
		printf("File Opened\n");
	
		read(p1,s,sizeof(data));
		printf("Data from file : %s\n",s);
		close(p1);
		printf("File closed\n");
	}
}
