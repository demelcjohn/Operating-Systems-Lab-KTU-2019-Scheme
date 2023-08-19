#include <unistd.h>
 
void main(void) {
	char *programName = "ls";
	char *arg1 = "-lh";
	char *arg2 = "/home"; 
	execlp(programName, programName, arg1, arg2, NULL);
 
}
