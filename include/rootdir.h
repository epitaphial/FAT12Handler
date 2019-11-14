#ifndef ROOTDIR_H
#define ROOTDIR_H

#pragma pack(push)
#pragma pack(1)

//part for FAT12

#define FILETYPE_BIN 0X20
#define FILETYPE_TEXT 0x00
#define FILETYPE_DIR 0X10  

typedef struct FAT12RootDir_entry
{
    char DIR_Name[11];
    UCHAR DIR_Attr;
    char DIR_Rsvd[10];
    USHORT DIR_WrtTime;
    USHORT DIR_WrtDate;
    USHORT DIR_FstClus;
    USHORT DIR_FileSize;
}FAT12DIRENTRY,*PFAT12DIRENTRY;

int getDirInfo(FILE *fp,PFAT12DIRENTRY fat12dir);

int lsDirInfo(PFAT12DIRENTRY fat12dir);

#pragma pack(pop)

#endif