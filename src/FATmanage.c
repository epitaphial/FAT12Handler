#include <stdio.h>
#include <string.h>

#include "common.h"
#include "FATmanage.h"

int ReadFATtable(FILE *fp,PFAT12TABLE pfat12table)
{
    memset(pfat12table->FAT_bit,0,sizeof(*(pfat12table->FAT_bit)));
    fseek(fp,FATSIZE/9,SEEK_SET);
    fread(pfat12table->FAT_cluster,FATSIZE,1,fp);
    
    int ClusId = 0;
    for (int i = 0; i < FATSIZE; i+=3)
    {
        int Byte1 = (int)(pfat12table->FAT_cluster[i]);
        int Byte2 = (int)(pfat12table->FAT_cluster[i+1]);
        int Byte3 = (int)(pfat12table->FAT_cluster[i+2]);
        int lowerClusId = Byte1 | (Byte2%0x10<<8);
        int higherClusId = Byte2/0x10 | (Byte3<<4);
        printf("%d,%d\n",lowerClusId,higherClusId);
        if(lowerClusId != 0)
        {
            pfat12table->FAT_bit[ClusId/32] |= (1<<(ClusId%32));
            ClusId++;
        }
        if(higherClusId != 0)
        {
            pfat12table->FAT_bit[ClusId/32] |= (1<<(ClusId%32));
            ClusId++; 
        }
    } 
    return 0;
}

int WriteFATtable(FILE *fp,PFAT12TABLE pfat12table)
{
    return 0;
}