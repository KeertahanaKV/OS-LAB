#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
    int i;
    pid_t pid;
    const int SIZE = 4096;
    int shmid;
    void *ptr;

    if (argc > 1)
    {
        sscanf(argv[1], "%d", &i);
        if (i < 1)
        {
            printf("Error input: %d\n", i);
            return 1;
        }
    }
    else
    {
        printf("Error: not passing N in command line\n");
        return 1;
    }

    // Create shared memory segment
    shmid = shmget((key_t) 1122, SIZE, 0666 | IPC_CREAT);
    ptr = shmat(shmid, NULL, 0666);

    // Fork the child process
    pid = fork();
    if (pid == 0) // Child process
    {
        execlp("./odd_numbers", "odd_numbers", argv[1], NULL);
        perror("execlp failed"); // If exec fails
        exit(1);
    }
    else if (pid > 0) // Parent process
    {
        wait(NULL); // Wait for the child to finish
        printf("\nPARENT: child completed\n");
        printf("Parent printing:\n");
        printf("%s\n", (char *)ptr);

        // Detach and remove shared memory
        shmdt(ptr);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}
//child process
#include<sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, k;
    void *ptr;
    int shmid;

    if (argc < 2)
    {
        printf("Error: not passing N in command line\n");
        exit(1);
    }

    // Attach to the shared memory segment
    shmid = shmget((key_t) 1122, 4096, 0666);
    ptr = shmat(shmid, NULL, 0666);

    printf("CHILD:\n");

    i = atoi(argv[1]); // Convert argument to integer
    k = 1; // Start from the first odd number

    for (int count = 0; count < i; count++)
    {
        sprintf(ptr, "%d ", k);
        ptr += strlen(ptr); // Move the pointer to the end of the string written
        k += 2; // Move to the next odd number
    }

    // Detach from the shared memory segment
    shmdt(ptr);
    return 0;
  }
