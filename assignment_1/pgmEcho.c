/***********************************/
/* pgmEcho Routine                 */
/***********************************/

/* library for I/O routines        */
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include <string.h>
//using the headers
#include "pgmErrors.h"
#include "pgmImage.h"


/***********************************/
/* main routine                    */
/*                                 */
/* CLI parameters:                 */
/* argv[0]: executable name        */
/* argv[1]: input file name        */
/* argv[2]: output file name       */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

int main(int argc, char **argv)
{
	//no file exists/expected
	if(argv[1] == NULL)
	{
		printf("Usage: ./pgmEcho inputImage.pgm outputImage.pgm\n");
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
	//write out the header
	pgmWriteHeader(theImage, argv[2], outputFile);
	//check if the image is an ascii file
	if (theImage->magic_number[1] == '2')
	{
		//read in the ascii data
		returnError = pgmReadAsciiData(theImage, argv[1], inputFile);
		//check for possible errors
		if(returnError != 0)
		{
			//return any possible errors
			return returnError;
		}
		//write out the ascii data
		pgmWriteAsciiData(theImage, argv[2], outputFile);

	}
	else
	{
		//check if the image is an binary file
		if (theImage->magic_number[1] == '5')
		{
			//read in the binary data
			returnError = pgmReadBinaryData(theImage, argv[1], inputFile);
			//check for possible errors
			if(returnError != 0)
			{
				//return any possible errors
				return returnError;
			}
			//write out the binary data
			pgmWriteBinaryData(theImage, argv[2], outputFile);
		}
	}
	return EXIT_NO_ERRORS;
} /* main() */
