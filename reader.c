/*
NAME:
DATE:
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>

#define DRIVER_NAME "bharath"
#define POP_DATA _IOR('a', 'c', struct data *)

struct data {
    int length;
    char *data;
};

int main(void) {
    int fd = open(DRIVER_NAME,O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    struct data*ptr=malloc(sizeof(struct data));
    ptr->length = 11; // Expect to read 3 bytes of data
    ptr->data = malloc(ptr->length);
    if (!ptr->data) {
        perror("Memory allocation failed");
        close(fd);
        return -1;
    }

    int ret=ioctl(fd,POP_DATA,&ptr);
        printf("Data popped: %d\n", ptr->length);
		printf("%s\n",ptr->data);

    free(ptr->data);
    close(fd);
    return 0;
}

