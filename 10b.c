#include<stdio.h>

#include<sys/stat.h>

#include<sys/types.h>

#include<sys/wait.h>

#include<stdlib.h>

#include <string.h>

#include <unistd.h>

#include <sys/shm.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <sys/mman.h>

int main(int argc,char *argv[])

{

 int i;

 pid_t pid;

 int k;

 int n1,n2,n3;

 const int SIZE = 4096;

 int shm_fd;

 void *ptr;

 if (argc > 1)

 {

 sscanf(argv[1], "%d", &i);

 if (i < 1)

 {

 printf("Error input: %d\n", i);

 return 0;

 }

 }

 else

 {

 printf("Error: not passing N in command line\n");

 exit(0);

 }

 pid = fork();

 if (pid == 0)// CHILD

 { 

 execlp("./prime","prime",argv[1],NULL);

 }

 else if (pid > 0)

 {

 wait(NULL);

 printf("\nPARENT: child completed\n");

 shm_fd = shm_open("HK", O_RDONLY, 0666);

 ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

 printf("Parent printing:\n");

 printf("%s ", (char *)ptr);
shm_unlink("HK");

 }

 return 0;

}
//child process

#include <sys/wait.h>

#include <stdio.h>

#include <string.h>

#include <unistd.h>

#include <sys/shm.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <sys/mman.h>

#include<stdlib.h>

int checkPrime(int N)

{

 // initially, flag is set to true or 1

 int flag = 1;

 // loop to iterate through 2 to N/2

 for (int i = 2; i <= N / 2; i++) {

 // if N is perfectly divisible by i

 // flag is set to 0 i.e false

 if (N % i == 0) {

 flag = 0;

 break;

 }

 }

 if (flag==1) {

 return N;

 

 }

 return 0;

}

int main(int argc,char *argv[])

{

 printf("Enter the start value for range:");

 int k,p;

 scanf("%d",&k);

 void *ptr;

 int shm_fd = shm_open("HK", O_CREAT | O_RDWR, 0666);

 ftruncate(shm_fd,4096);

 ptr = mmap(0,4096,PROT_WRITE, MAP_SHARED, shm_fd, 0);

 printf("CHILD:\n");

 int i=atoi(argv[1]);

 /* sprintf(ptr,"%d ",n1);
ptr+=strlen(ptr);

 printf("%d ",n1);

 sprintf(ptr,"%d ",n2);

 ptr+=strlen(ptr);

 printf("%d ",n2);*/

 while (k!=i)

 {

 p= checkPrime(k++);

 if(p!=0){

 sprintf(ptr,"%d ", p);

 printf("%d ", p);

 ptr += strlen(ptr);

 }

 } 

//child process
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>

int checkPrime(int M)
{
    int flag = 1;
    for (int i = 2; i <= M / 2; i++) {
        if (M % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag == 1 ? M : 0;
}

int main(int argc, char *argv[])
{
    
    int k,p;
    k=atoi(argv[1]);
    void *ptr;
    int shm_fd = shm_open("HK", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, 4096);
    ptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    printf("CHILD:\n");
    int i = atoi(argv[2]);

    while (k != i)
    {
        p = checkPrime(k++);
        if (p != 0) {
            sprintf(ptr, "%d ", p);
            printf("%d ", p);
            ptr += strlen(ptr);
        }
    }
    return 0;
}
