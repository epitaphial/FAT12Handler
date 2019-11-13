#ifndef FATMANAGE_H
#define FATMANAGE_H

#pragma pack(push)
#pragma pack(1)

//9*512/3=1536

struct FAT12_FAT
{
    //the first two byte cant be used!
    char FAT_cluster[1536];
};

#pragma pack(pop)

#endif