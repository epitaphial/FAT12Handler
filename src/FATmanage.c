#include <stdio.h>

#include "FATmanage.h"

int ReadFATtable(FILE *fp,PFAT12TABLE pfat12table)
{
    fseek(fp,0,SEEK_SET);
    fread(pfat12table->FAT_cluster,4608,1,fp);
    printf("%x,%x",pfat12table->FAT_bit[0],pfat12table->FAT_bit[1]);
    return 0;
}

int WriteFATtable(FILE *fp,PFAT12TABLE pfat12table)
{
    return 0;
}