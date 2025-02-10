//parent wait before child finishes

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int status;
    const int numOfChildren = 3;

    //Array of commands
    char *commands[][3]= {
        {"ls", "-l",NULL},
        {"echo", "hello Anna!",NULL},
        {"ps", NULL},
        {"time", "copyfile.sh",NULL},
        {"history", "5",NULL},
        {"mkdir", "quickdir",NULL},
        {"cd", "quickdir",NULL},
        {"touch", "list.txt",NULL},
        {"cd", "..",NULL},
        {"rmdir", "quickdir",NULL}
        };
    printf("Parent process PID: %d\n" , getpid());

    for (int i=0; i<numOfChildren; i++){
        //System sets the PID
        pid = fork();

        if (pid<0){
            printf("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid==0){
            printf("Child process PID: %d - Executing commands: %s\n", getpid(),commands[i][0]);
            //First is what kind of system call, second is the actual commands
            execvp(commands[i][0],commands[i]);
            printf("execvp failed");
            exit(EXIT_FAILURE);
        }
    }

    printf("Print out history -----\n");

    while((pid=wait(&status))>0){
        printf("Child process with PID %d finished\n",pid);
    }
    return EXIT_SUCCESS;
}
