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

#define DRIVER_NAME "bharath"
#define SET_SIZE_OF_QUEUE _IOW('a', 'a', int *)

int main(void) {
    int fd = open(DRIVER_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    int size=181;
    int ret=ioctl(fd, SET_SIZE_OF_QUEUE, &size);
    printf("Queue size set to %d\n", size);
    close(fd);
    return 0;
}

