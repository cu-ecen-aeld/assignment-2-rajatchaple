INCLUDE_DIRS = 
LIB_DIRS = 
CROSS_COMPILE=gcc
CC=gcc

CDEFS= 
CFLAGS= -O0 -g $(INCLUDE_DIRS) $(CDEFS)
LDFLAGS= 
LIBS= 

PRODUCT=writer

HFILES=
CFILES= writer.c

SRCS= ${HFILES} ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	${PRODUCT}

clean:
	-rm -f *.o *.NEW *~ *.d
	-rm -f ${PRODUCT} ${GARBAGE}

writer:	writer.o
	$(CROSS_COMPILE) $(LDFLAGS) $(CFLAGS) -o $@ writer.o $(LIBS)
   
#temp: writer.o
#	$(CROSS_COMPILE) $(LDFLAGS) $(CFLAGS) -o $@ writer.o $(LIBS)


depend:

.c.o:
	$(CROSS_COMPILE) -MD $(CFLAGS) -c $<
