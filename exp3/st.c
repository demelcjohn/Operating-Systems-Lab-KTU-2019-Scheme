#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
void main(){
	struct stat s;
	stat("st.c",&s);
	printf("Total size of program:%ld \n",s.st_size);
	printf("Device id :%ld \n",s.st_ino);
}

