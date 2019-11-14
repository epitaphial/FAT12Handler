#include <stdio.h>

#include "FATio.h"

int gets_LR(char *buffer,int size)
{
    int scanf_count;
    for (scanf_count = 0; scanf_count < size; scanf_count++)
    {
        scanf("%c",buffer+scanf_count);
        if(*(buffer+scanf_count) == '\n')
            break;
    }
    buffer[scanf_count] = '\0';
    return scanf_count;
}

void print_Hello()
{
    printf("_________________________________\n");
    printf("         [FAT12 shell]           \n");
    printf("please choose:                   \n");
    printf("1.create a empty FAT12 floppy.   \n");
    printf("2.write in boot.bin(512byte).    \n");
    printf("3.load FAT12 floppy and manage.  \n");
    printf("0.exit.                          \n");
    printf("_________________________________\n");
}

void print_helper()
{
    printf("help             show help info.\n");
    printf("info             show floppy information.\n");
    printf("ls               list the file.\n");
    printf("rm               delete file.\n");
    printf("write            write in file.\n");
    printf("quit             quit shell.\n\n");
    return;
}