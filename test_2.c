/**
 * @file   testebbchar.c
 * @author Michael Hinton
 * @date   22 February
 * @version 0.1
 * @brief  A Linux user space program that communicates with the my_linux_driver_2.c LKM. It passes a
 * string to the LKM and reads the response from the LKM. For this example to work the device
 * must be called /dev/my_linux_driver_2.
 * @see http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device/
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

// The buffer length (crude but fine)
#define BUFFER_LENGTH 256
#define DEVICE_NAME "/dev/my_linux_driver_2"
// The receive buffer from the LKM
static char receive[BUFFER_LENGTH];

int main(){
    int ret, fd;
    char stringToSend[BUFFER_LENGTH];
    printf("Starting device test code example...\n");
    // Open the device with read/write access
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0){
        perror("Failed to open the device...");
        return errno;
    }
    printf("Type in a short string to send to the kernel module:\n");
    // Read in a string (with spaces)
    scanf("%[^\n]%*c", stringToSend);
    printf("Writing message to the device [%s].\n", stringToSend);
    // Send the string to the LKM
    ret = write(fd, stringToSend, strlen(stringToSend));
    if (ret < 0){
        perror("Failed to write the message to the device.");
        return errno;
    }

    printf("Press ENTER to read back from the device...\n");
    getchar();

    printf("Reading from the device...\n");
    // Read the response from the LKM
    ret = read(fd, receive, BUFFER_LENGTH);
    if (ret < 0){
        perror("Failed to read the message from the device.");
        return errno;
    }
    printf("The received message is: [%s]\n", receive);
    printf("End of the program\n");
    return 0;
}