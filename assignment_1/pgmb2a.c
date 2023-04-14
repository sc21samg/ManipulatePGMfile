/***********************************/
/* pgmb2a Routine                 */
/***********************************/

/* library for I/O routines        */
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include <string.h>
//using the headers
#include "pgmErrors.h"
#include "pgmImage.h"


int main(int argc, char **argv)
{
	//no file exists/expected
	if(argv[1] == NULL)
	{
		printf("Usage: ./pgmb2a inputImage.pgm outputImage.pgm\n");
		/* and return no error code      */
		return EXIT_NO_ERRORS;
	}
	else
	{
	/* check for correct number of arguments */
		if (argc != 3)
		{ /* wrong arg count */
			/* print an error message        */
			printf("ERROR: Bad Argument Count\n");
			/* and return an error code      */
			return EXIT_WRONG_ARG_COUNT;
		} /* wrong arg count */
	}
	//use the Image struct and give it a 
	//parameter only for this main
	pgmImage image1;
	pgmImage *theImage;
	theImage = &image1;
	Image(theImage);


	/* open a file for reading               */
	FILE *inputFile = fopen(argv[1], "r");
	//check for bad filename
	if (inputFile == NULL)
	{
		printf("ERROR: Bad File Name (%s)\n", argv[1]);

		return EXIT_BAD_INPUT_FILE;
	}

	/* open a file for writing               */
	FILE *outputFile = fopen(argv[2], "w");
	//check for bad filename
	if (outputFile == NULL)
	{
		printf("ERROR: Bad File Name (%s)\n", argv[2]);

		return EXIT_BAD_INPUT_FILE;
	}

	//variable to check for possible errors in the int functions
	unsigned int returnError = -1;
	//read in the header
	returnError = pgmReadHeader(theImage, argv[1], inputFile);
	//check for possible errors
	if(returnError != 0)
	{
		//return any possible errors
		return returnError;
	}
	//check if the image is an ascii file
	if (theImage->magic_number[1] == '2')
		{
			/* print an error message */
			printf("ERROR: Bad Magic Number (%s)\n", argv[1]);

			/* and return                    */
			return EXIT_BAD_MAGIC_NUMBER;     
		}
	else
	{
		//change magic number to P5
		unsigned char *magic_no_2 = "P2";
		theImage->magic_Number = (unsigned short *) magic_no_2;
		//write out the header
		pgmWriteHeader(theImage, argv[2], outputFile);
		//read in the binary data
		returnError = pgmReadBinaryData(theImage, argv[1], inputFile);
		//check for possible errors
		if(returnError != 0)
		{
			//return any possible errors
			return returnError;
		}
		//write out the ascii data
		pgmWriteAsciiData(theImage, argv[2], outputFile);
		//print message for successful coverted file
		printf("CONVERTED\n");
	}

	return EXIT_NO_ERRORS;
} /* main() */
