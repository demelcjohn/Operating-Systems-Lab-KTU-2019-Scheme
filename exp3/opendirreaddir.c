#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
struct dirent *d_ptr;
void main()
{
	char s[10];
	DIR *dirp;
	printf("Opendir and readdir\n");
	printf("Enter Directory Name : ");
	scanf(" %s",s);
	dirp=opendir(s);
	if(dirp==NULL){
		printf("\nDirectory Not exists\n");
		exit(1);
	}
	printf("Contents :\n");
	while(d_ptr=readdir(dirp)){
		printf("%s\n",d_ptr->d_name);
	}
	closedir(dirp);
	
}

