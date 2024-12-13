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
#define PUSH_DATA _IOW('a', 'b', struct data *)

struct data {
    int length;
    char *data;
};

int main(void) {
    int fd=open(DRIVER_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    struct data*ptr=malloc(sizeof(struct data));
    ptr->length=10;
    ptr->data = malloc(ptr->length);
    if (!ptr->data) {
        perror("Memory allocation failed");
        close(fd);
        return -1;
    }

    memcpy(ptr->data,"abc",ptr->length);

    int ret=ioctl(fd,PUSH_DATA,&ptr);
        printf("Data pushed: %d %s\n",ptr->length, ptr->data);
    free(ptr->data);
    close(fd);
    return 0;
}

