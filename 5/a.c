#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 30

int main() {
    int fd = open("myfile.txt", O_RDWR), n;
    char buffer[BUFFER_SIZE];

    printf("File descriptor is %d\n", fd);
    if (fd == -1) {
        printf("Failed to open file.\n");
        exit(1);
    }

    // i. Reading first 10 characters from file
    printf("Reading first 10 characters from file: \n");
    n = read(fd, buffer, 10);
    write(1, buffer, n);
    printf("\n");

    // ii. Skipping 5 characters from current position in the file
    printf("Skipping 5 characters from current position in the file: \n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);
    printf("\n");

    // iii. Going 10 characters before the current position in the file
    printf("Going 10 characters before the current position in the file: \n");
    lseek(fd, -10, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);
    printf("\n");

    // iv. Going to 5th last character in the file
    printf("Going to 5th last character in the file: \n");
    lseek(fd, -6, SEEK_END);
    n = read(fd, buffer, 5);
    write(1, buffer, n);
    printf("\n");

    // v. Going to the 3rd character in the file
    printf("Going to the 3rd character in the file: \n");
    lseek(fd, 2, SEEK_SET);  // Note: lseek(fd, 3, SEEK_SET) would go to the 4th character
    n = read(fd, buffer, 5);
    write(1, buffer, n);
    printf("\n");

    close(fd);
    return 0;
}

