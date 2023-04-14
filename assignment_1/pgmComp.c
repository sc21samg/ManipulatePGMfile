/***********************************/
/* Compare file Routine              */
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
	//counter if the images are identical 
	//set to not identical
	unsigned int IDENTICAL_HEADERS = 1;
	//no file exists/expected
	if(argv[1] == NULL)
	{
		printf("Usage: ./pgmComp inputImage.pgm inputImage.pgm\n");
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
	pgmImage image2;
	pgmImage *imageA;
	imageA = &image2;
	Image(imageA);

	//use the Image struct and give it a 
	//parameter only for this main
	pgmImage image3;
	pgmImage *imageB;
	imageB = &image3;
	Image(imageB);

	/* open file 1 for reading               */
	FILE *inputFile1 = fopen(argv[1], "r");
	//check for bad filename
	if (inputFile1 == NULL)
	{
		printf("ERROR: Bad File Name (%s)\n", argv[1]);

		return EXIT_BAD_INPUT_FILE;
	}
	//variable to check for possible errors in the int functions
	unsigned int returnError = -1;
	//read in the header
	returnError = pgmReadHeader(imageA, argv[1], inputFile1);

		//check for possible errors
		if(returnError != 0)
		{
			//return any possible errors
			return returnError;
		}
	//check if the image is an ascii file
	if(imageA->magic_number[1] == '2')
	{
		//read in the ascii data
		returnError = pgmReadAsciiData(imageA, argv[1], inputFile1);
		//check for possible errors
		if(returnError != 0)
		{
			//return any possible errors
			return returnError;
		}
	}
	else
	{
		//check if the image is an binary file
		if(imageA->magic_number[1] == '5')
		{
			//read in the binary data
			returnError = pgmReadBinaryData(imageA, argv[1], inputFile1);

			//check for possible errors
			if(returnError != 0)
			{
				//return any possible errors
				return returnError;
			}
		}
	}

	/* open file 2 for reading               */
	FILE *inputFile2 = fopen(argv[2], "r");
	//check for bad filename
	if (inputFile2 == NULL)
	{
		printf("ERROR: Bad File Name (%s)\n", argv[2]);

		return EXIT_BAD_INPUT_FILE;
	}
	//read in the 2nd header
	returnError =  pgmReadHeader(imageB, argv[2], inputFile2);
	//check for possible errors
	if(returnError != 0)
	{
		//return any possible errors
		return returnError;
	}
	//check if the image is an ascii file
	if(imageB->magic_number[1] == '2')
	{
		//read in the 2nd image ascii data
		returnError = pgmReadAsciiData(imageB, argv[2], inputFile2);
		//check for possible errors
		if(returnError != 0)
		{
			//return any possible errors
			return returnError;
		}
	}
	else
	{
		//check if the image is an binary file
		if(imageB->magic_number[1] == '5')
		{
			//read in the binary data
			returnError = pgmReadBinaryData(imageB, argv[2], inputFile2);

			//check for possible errors
			if(returnError != 0)
			{
				//return any possible errors
				return returnError;
			}
		}
	}

	/*Comparing the headers*/
	//check the height, width and maxGray
	if(
		(imageA->height == imageB->height) &&
		(imageA->width == imageB->width) &&
		(imageA->maxGray == imageB->maxGray) )
		{
			//the images are identical
			IDENTICAL_HEADERS = 0;
		}
		else
		{
			//the images are different
			IDENTICAL_HEADERS = 1;
			/* print an error message */
			printf("DIFFERENT\n");

			/* and return                    */
			return EXIT_NO_ERRORS;
		}


		/*Comparing the data for ASCII/Binary files*/
		//take ever pixel from imageData and compare them
		for(int i = 0; i < imageA->height; i++)
		{
			for(int j = 0; j < imageA->width; j++)
			{
				if(strcmp(&imageA->imageData[i][j], &imageB->imageData[i][j])==1)
				{
					//image data is different
					IDENTICAL_HEADERS = 1;
					/* print an error message */
					printf("DIFFERENT\n");

					/* and return                    */
					return EXIT_NO_ERRORS;
				}
				else
				{
					//the image data is identical
					IDENTICAL_HEADERS = 0;
				}

			}
		}

		//final check of teh 2 images
		if(IDENTICAL_HEADERS == 0)
		{
			printf("IDENTICAL\n");
		}
		else
		{
			/* print an error message */
			printf("DIFFERENT\n");

			/* and return                    */
			return EXIT_NO_ERRORS;
		}

	return EXIT_NO_ERRORS;
	} 