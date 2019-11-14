#ifndef ROOTDIR_H
#define ROOTDIR_H

#pragma pack(push)
#pragma pack(1)

//part for FAT12

struct FAT12RootDir_entry
{
    char DIR_Name[11];
    char DIR_Attr;
    char DIR_Rsvd[10];
    short DIR_WrtTime;
    short DIR_WrtDate;
    short DIR_FstClus;
    int DIR_FileSize;
};

#pragma pack(pop)

#endif