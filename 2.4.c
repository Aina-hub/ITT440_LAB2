#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
char name[50];
int pid;

for (int i = 1; i < 5; i++) {
pid_t pid = fork();

if(pid==0) {
printf("Enter your name: ");
scanf("%s",name);
printf("Hello nice to know you %s.\n",name);
printf("Child process => PPID=%d, PID=%d\n",getppid(), getpid());
exit(0);
}

else {
printf("Parent process => PID=%d\n",getpid());
printf("Waiting for child processess to finish...\n");
wait(NULL);
}
}

printf("Job is done.\n");
return EXIT_SUCCESS;
}
