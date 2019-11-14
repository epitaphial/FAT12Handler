#ifndef FATSHELL_H
#define FATSHELL_H


void start_shell();
void manage_shell(char *floppy_name);

//-ls
void command_ls(FILE *fp);

//-help
void command_help();

//-info
void command_info(FILE *fp);

#endif