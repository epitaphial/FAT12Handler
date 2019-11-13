SOURCE = fileopr.o bootsec.o FATshell.o FATio.o

CC = gcc

CFLAGS = -Wall

test : $(SOURCE) test.c
	$(CC) -o test test.c $(SOURCE)
	.\test.exe

fileopr.o : fileopr.h fileopr.c
	$(CC) -c fileopr.c

bootsec.o : bootsec.h bootsec.c
	$(CC) -c bootsec.c

FATshell.o : FATshell.h FATshell.c
	$(CC) -c FATshell.c

FATio.o : FATio.h FATio.c
	$(CC) -c FATio.c

.PHONY : clean
clean :
	rm *.o *.exe *.img