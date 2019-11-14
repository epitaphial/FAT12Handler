/*struct and operation for FAT table*/
#ifndef FATMANAGE_H
#define FATMANAGE_H

#pragma pack(push)
#pragma pack(1)

//9*512 = 4608

typedef struct FAT12_FAT
{
    //the first two byte cant be used!
    char FAT_cluster[4608];

    //a bitset,tell if a cluster is unused. 4608/1.5/32 = 96
    int FAT_bit[96];
}FAT12TABLE,*PFAT12TABLE;

//read FATtable from img
int ReadFATtable(FILE *fp,PFAT12TABLE pfat12table);

//write structure to img
int WriteFATtable(FILE *fp,PFAT12TABLE pfat12table);

//get a free cluster
int getFreeOffset(PFAT12TABLE pfat12table);

//flag a free cluster to be used
void setUsedbit(int offset);

#pragma pack(pop)

#endif