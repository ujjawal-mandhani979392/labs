#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pipefds[2];
    int returnstatus;
    int pid;
    char writemessage[2][20] = {"Ujjawal", "Mandhani"};
    char readmessage[20];
    returnstatus = pipe(pipefds);
    if (returnstatus == -1)
    {
        printf("Unable to create pipe\n");
        return 1;
    }
    pid = fork();
    if (pid == 0)
    {
        read(pipefds[0], readmessage, sizeof(readmessage));
        printf("Child process - Reading from pipe - Message 1 is %s\n", readmessage);
        read(pipefds[1], readmessage, sizeof(readmessage));
        printf("Child process - Reading from pipe - Message 2 is %s\n", readmessage);
    }
    else
    {
        printf("Parent process - Reading from pipe - Message 1 is %s\n", writemessage[0]);
        write(pipefds[0], writemessage[0], sizeof(readmessage));
        printf("Parent process - Reading from pipe - Message 2 is %s\n", writemessage[1]);
        write(pipefds[1], writemessage[1], sizeof(readmessage));
    }
    return 0;
}