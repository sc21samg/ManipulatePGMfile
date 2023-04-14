CC=gcc
CCFLAGS = -g -std=c99 
#-fmax-errors=1 -Wall -Werror

MODULES=pgmErrors.h pgmRead.c pgmWrite.c pgmImage.c pgmImage.h 

MAINS=pgmEcho.o pgmComp.o pgma2b.o pgmb2a.o pgmReduce.o pgmTile.o pgmAssemble.o

TARGETS=pgmEcho pgmComp pgma2b pgmb2a pgmReduce pgmTile pgmAssemble

all: ${TARGETS}

clean:
	rm ${TARGETS} ${MAINS} *.o


pgmEcho:	pgmEcho.c pgmErrors.h pgmRead.c pgmWrite.c pgmImage.c pgmImage.h
	${CC} ${CCFLAGS} -o $@ $^
# $@ means the name writen before the colon, $^ means all the files after the colon

pgmComp:	pgmComp.c pgmErrors.h pgmRead.c pgmWrite.c pgmImage.c pgmImage.h
	${CC} ${CCFLAGS} -o $@ $^

pgma2b:	pgma2b.c pgmErrors.h pgmRead.c pgmWrite.c pgmImage.c pgmImage.h
	${CC} ${CCFLAGS} -o $@ $^

pgmb2a:	pgmb2a.c pgmErrors.h pgmRead.c pgmWrite.c pgmImage.c pgmImage.h
	${CC} ${CCFLAGS} -o $@ $^

pgmReduce:	pgmReduce.c pgmErrors.h pgmRead.c pgmWrite.c pgmImage.c pgmImage.h
	${CC} ${CCFLAGS} -o $@ $^

pgmTile:	pgmTile.c pgmErrors.h pgmRead.c pgmWrite.c pgmImage.c pgmImage.h
	${CC} ${CCFLAGS} -o $@ $^

pgmAssemble:	pgmAssemble.c pgmErrors.h pgmRead.c pgmWrite.c pgmImage.c pgmImage.h
	${CC} ${CCFLAGS} -o $@ $^

