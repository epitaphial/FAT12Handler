SOURCE = fileopr.o bootsec.o

CC = gcc

CFLAGS = -Wall

test : $(SOURCE) test.c
	$(CC) -o test test.c $(SOURCE)
	.\test.exe

fileopr.o : fileopr.h fileopr.c
	$(CC) -c fileopr.c

bootsec.o : bootsec.h bootsec.c
	$(CC) -c bootsec.c

.PHONY : clean
clean :
	rm *.o *.exe *.img