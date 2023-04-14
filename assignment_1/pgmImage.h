/***********************************/
/* The Image file Routine              */
/***********************************/

/* library for I/O routines        */
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>


#include <string.h>

#include "pgmErrors.h"



/* variables for storing the image       */
#define MAGIC_NUMBER_RAW_PGM 0x3550
#define MAGIC_NUMBER_ASCII_PGM 0x3250
#define MIN_IMAGE_DIMENSION 1
#define MAX_IMAGE_DIMENSION 65536
#define MAX_COMMENT_LINE_LENGTH 128
	
//defining the standard struct image
typedef struct pgm_image
{
	unsigned char magic_number[2];
	unsigned short *magic_Number;
	char *commentLine;
	unsigned int height;
	unsigned int width;
	unsigned int maxGray;
	unsigned char **imageData;         
	long nImageBytes;
}pgmImage;

//declaring the functions for all the main C files
int Image(pgmImage *image);
int pgmReadHeader(pgmImage *theImage, char *filename, FILE* inputFile);
int pgmReadBinaryData(pgmImage *theImage, char *filename, FILE* inputFile);
int pgmReadAsciiData(pgmImage *theImage, char *filename, FILE* inputFile);


int pgmWriteHeader(pgmImage *theImage, char *outFilename, FILE* outputFile);
int pgmWriteAsciiData(pgmImage *theImage, char *outFilename, FILE* outputFile);
int pgmWriteBinaryData(pgmImage *theImage, char *outFilename, FILE* outputFile);







