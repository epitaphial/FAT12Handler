CC = gcc
CFLAGS = -Wall -I $(HDPATH)

ROOTPATH = .
HDPATH = $(ROOTPATH)/include/
SRCPATH = $(ROOTPATH)/src/
BDPATH = $(ROOTPATH)/build/
TSTFILE = $(ROOTPATH)/testsrc/test.c
OBJPATH = $(ROOTPATH)/obj/
OBJSOURCE = $(wildcard $(ROOTPATH)/obj/*.o)
SRCPAT = $(wildcard $(SRCPATH)*.c)
OBJPAT = $(patsubst %.c,$(OBJPATH)%.o,$(notdir $(SRCPAT)))

test : $(OBJPAT) $(TSTFILE)
	$(CC) $(CFLAGS) -o $(BDPATH)test $(OBJPAT) $(TSTFILE)

$(OBJPATH)fileopr.o : $(HDPATH)fileopr.h $(SRCPATH)fileopr.c
	$(CC) $(CFLAGS) -c $(SRCPATH)fileopr.c -o $@

$(OBJPATH)bootsec.o : $(HDPATH)bootsec.h $(SRCPATH)bootsec.c
	$(CC) $(CFLAGS) -c $(SRCPATH)bootsec.c -o $@

$(OBJPATH)FATshell.o : $(HDPATH)FATshell.h $(SRCPATH)FATshell.c
	$(CC) $(CFLAGS) -c $(SRCPATH)FATshell.c -o $@

$(OBJPATH)FATio.o : $(HDPATH)FATio.h $(SRCPATH)FATio.c
	$(CC) $(CFLAGS) -c $(SRCPATH)FATio.c -o $@

$(OBJPATH)rootdir.o : $(HDPATH)rootdir.h $(SRCPATH)rootdir.c
	$(CC) $(CFLAGS) -c $(SRCPATH)rootdir.c -o $@

.PHONY : clean
clean :
	rm build/*
	rm obj/*