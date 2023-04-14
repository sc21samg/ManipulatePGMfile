/***********************************/
/* pgmReduce Routine                 */
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
/* argv[2]: n factor               */
/* argv[3]: output file name       */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

int main(int argc, char **argv)
{
	//no file exists/expected
	if(argv[1] == NULL)
	{
		printf("Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm\n");
		/* and return no error code      */
		return EXIT_NO_ERRORS;
	}
	else
	{
	/* check for correct number of arguments */
		if (argc != 4)
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
	if (inputFile == NULL)
	{
		printf("ERROR: Bad File Name (%s)\n", argv[1]);

		return EXIT_BAD_INPUT_FILE;
	}



	char *n = argv[2];
	int factorN;
	factorN = atoi(n);

	if(factorN <= 0)
	{
		printf("ERROR: Miscellaneous\n");
		/* and return an error code      */
		return EXIT_BAD_FACTOR_N;
	} /* wrong arg count */


	/* open a file for writing               */
	FILE *outputFile = fopen(argv[3], "w");
	//check for bad filename
	if (outputFile == NULL)
	{
		printf("ERROR: Bad File Name (%s)\n", argv[3]);

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

	//use the Image struct and give it a 
	//parameter only for this main
	//we use this to store the reduced data
	pgmImage image2;
	pgmImage *imageReduce;
	imageReduce = &image2;
	Image(imageReduce);

	//reduce the height and width
	imageReduce->height = theImage->height / factorN;
	imageReduce->width = theImage->width / factorN;
	//making another struct to reduce
	imageReduce->maxGray = theImage->maxGray;
	imageReduce->magic_Number = theImage->magic_Number;

	
	//write out the header
	 pgmWriteHeader(imageReduce, argv[3], outputFile);

	//another struct to reduce
	//reducedImage -> imageData; 
	//allocating memmory for the new imageData
	imageReduce->imageData = (unsigned char **) malloc (imageReduce->height * sizeof(unsigned char *));

		for(int i = 0; i < imageReduce->height; i++)
		{
			imageReduce->imageData[i] = (unsigned char *) malloc(imageReduce->width * sizeof(unsigned char));

		}
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
			//different row/column for the reduced image
			int row = -1;
			int column = -1;
			//taking the 0 modulo factorN rows/columns 
			//from the original image
			for(int i = 0; i < theImage->height; i++)
			{
				if(i % factorN == 0)
				{
					row++;
				}
				column = -1;
				for(int j = 0; j < theImage->width; j++)
				{
					if((i % factorN == 0) && (j % factorN == 0))
					{
						column++;
						imageReduce->imageData[row][column] = theImage->imageData[i + 1][j + 1];
						fscanf( inputFile, " %u", &imageReduce->imageData[row][column]);
					}
				}
			}
			//write out the ascii data
			pgmWriteAsciiData(imageReduce, argv[3], outputFile);
			//print message for successful reduced file
			printf("REDUCED\n");

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
			//different row/column for the reduced image
			int row = -1;
			int column = -1;
			//taking the 0 modulo factorN rows/columns 
			//from the original image
			for(int i = 0; i < theImage->height; i++)
			{
				if(i % factorN == 0)
				{
					row++;
				}
				column = -1;
				for(int j = 0; j < theImage->width; j++)
				{
					if((i % factorN == 0) && (j % factorN == 0))
					{
						column++;
						imageReduce->imageData[row][column] = theImage->imageData[i + 1][j + 1];
						fwrite(&imageReduce->imageData[row][column], 1, 1, outputFile);
					}
				}
			}
			//write out the binary data
			pgmWriteBinaryData(imageReduce, argv[3], outputFile);
			//print message for successful reduced file
			printf("REDUCED\n");
		}
	}

	return EXIT_NO_ERRORS;
} /* main() */
