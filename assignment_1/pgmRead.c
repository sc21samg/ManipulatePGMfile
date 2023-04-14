/***********************************/
/* Read file Routine               */
/***********************************/

/* library for I/O routines        */
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>

#include <string.h>

#include "pgmErrors.h"
#include "pgmImage.h"


/***********************************/
/* PGM Read Routine                */
/*                                 */
/* CLI parameters:                 */
/* argv[1]:input file name         */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

//1st read function to read in only the header
//(parameters, 1st: image struct pointer, 
//2nd: filename, 3rd: access to the open file)
int pgmReadHeader(pgmImage *theImage, char *filename, FILE* inputFile)
{
	/* if it fails, return error code        */
	if (inputFile == NULL)
	{
		return EXIT_BAD_INPUT_FILE;
	}

	/* read in the magic number              */
	theImage->magic_number[0] = getc(inputFile);
	theImage->magic_number[1] = getc(inputFile);

	/* the magic number		         */
	/* stored as two bytes to avoid	         */
	/* problems with endianness	         */
	/* Raw:    0x5035 or P5		         */
	/* ASCII:  0x5032 or P2		         */
	theImage->magic_Number = (unsigned short *) theImage->magic_number;


		/* check on bad magic number      */
		if (
		(theImage->magic_number[0] != 'P') ||
		((theImage->magic_number[1] != '2') &&
		(theImage->magic_number[1] != '5')))
		{ /* failed magic number check   */
		/* be tidy: close the file       */
		fclose(inputFile);
		//printf("%u", theImage->magic_number[1]);

		/* print an error message */
		printf("ERROR: Bad Magic Number (%s)\n", filename);

		/* and return                    */
		return EXIT_BAD_MAGIC_NUMBER;                                                        
		} /* failed magic number check   */


	/* scan whitespace if present            */
	int scanCount = fscanf(inputFile, " ");
	/* check for a comment line              */
	char nextChar = fgetc(inputFile);
	if (nextChar == '#')
		{ /* comment line                */
		/* allocate buffer               */
		theImage->commentLine = (char *) malloc(MAX_COMMENT_LINE_LENGTH);
		/* fgets() reads a line          */
		/* capture return value          */
		char *commentString = fgets(theImage->commentLine, MAX_COMMENT_LINE_LENGTH, inputFile);
		/* NULL means failure            */
		if (commentString == NULL)
			{ /* NULL comment read   */
			/* free memory           */
			free(theImage->commentLine);
			/* close file            */
			fclose(inputFile);

			/* print an error message */
			printf("Error: Failed to read pgm image from file %s\n", filename);

			/* and return            */
			return EXIT_BAD_INPUT_FILE;
			} /* NULL comment read   */
		} /* comment line */
	else
		{ /* not a comment line */
		/* put character back            */
		ungetc(nextChar, inputFile);
		} /* not a comment line */


	/* read in width, height, grays          */
	/* whitespace to skip blanks             */
	scanCount = fscanf(inputFile, " %u %u %u", &(theImage->width), &(theImage->height), &(theImage->maxGray));


	/* sanity checks on size & grays         */
	/* must read exactly three values        */
	if 	(scanCount != 3)	
		{
		/* free up the memory            */
		free(theImage->commentLine);
		/* be tidy: close file pointer   */
		fclose(inputFile);

		/* print an error message */
		printf("ERROR: Bad Comment Line (%s)\n", filename); 

		/* and return                    */
		return EXIT_BAD_COMMENT_LINE;


		} /* failed size sanity check    */

		/* sanity checks on width & height         */
		if(
		(theImage->width < MIN_IMAGE_DIMENSION	) 	||
		(theImage->width >= MAX_IMAGE_DIMENSION	) 	||
		(theImage->height < MIN_IMAGE_DIMENSION	) 	||
		(theImage->height >= MAX_IMAGE_DIMENSION	) )
		{
			/* free up the memory            */
			free(theImage->commentLine);
			/* be tidy: close file pointer   */
			fclose(inputFile);

			/* print an error message */
			printf("ERROR: Bad Dimensions (%s)\n", filename); 

			/* and return                    */
			return EXIT_BAD_DIMENSIONS;
		}/* failed size sanity check    */

		/* sanity checks on max gray value         */
		if(		        
		(theImage->maxGray	< 0		    )   ||               
		(theImage->maxGray	> 255		))
		{
			/* free up the memory            */
			free(theImage->commentLine);
			/* be tidy: close file pointer   */
			fclose(inputFile);

			/* print an error message */
			printf("ERROR: Bad Max Gray Value (%s)\n", filename); 

			/* and return                    */
			return EXIT_BAD_MAXGRAY;	
		}/* failed size sanity check    */


		/* allocate the memmory for the data pointer  */
		theImage->imageData = (unsigned char **) malloc(theImage->height * sizeof(unsigned char *));
		/*allocating data with a 2D array*/
		for(int i = 0; i < theImage->height; i++)
		{
			theImage->imageData[i] = (unsigned char *) malloc(theImage->width * sizeof(unsigned char));
			/* sanity checks on malloc allocation */
			if(theImage->imageData[i] == NULL)
			{
				/* free up the memory            */
				free(theImage->commentLine);
				/* be tidy: close file pointer   */
				fclose(inputFile);

				/* print an error message */
				printf("ERROR: Image Malloc Failed\n"); 

				/* and return                    */
				return EXIT_FAILED_MALLOC;	
				/* failed malloc sanity check    */
			}

		}

		/* sanity check for memory allocation    */
		if (theImage->imageData == NULL)
			{ /* malloc failed */
			/* free up memory                */
			free(theImage->commentLine);

			/* close file pointer            */
			fclose(inputFile);

			/* print an error message */
			printf("Error: Failed to read pgm image from file %s\n", filename);

			/* return error code             */
			return EXIT_BAD_INPUT_FILE;
			} /* malloc failed */
	
	 return EXIT_NO_ERRORS;
	}

		//2nd read function to read in the binary data
		int pgmReadBinaryData(pgmImage *theImage, char *filename, FILE* inputFile)
	{
		//counter checks if fread reads in the data
		size_t scanCount = -1;
		scanCount = fscanf(inputFile, " ");
		//using a 2d array to read in each pixel with image data
		for(int i = 0; i < theImage->height; i++)
		{
			for(int j = 0; j < theImage->width; j++)
			{
				unsigned char variable = -1;
				//reading in each pixel
				scanCount = fread(&variable, 1, 1, inputFile);
				theImage->imageData[i][j] = (unsigned char) variable;

			/* sanity check	                 */
			if ((scanCount != 1) || (theImage->imageData[i][j] < 0) || (theImage->imageData[i][j] > 255))
			{ /* fread failed */
				/* free memory           */
				free(theImage->commentLine);
				free(theImage->imageData);

				/* close file            */
				fclose(inputFile);

				/* print error message   */
				printf("ERROR: Bad Data (%s)\n", filename); 

				/* and return            */
				return EXIT_BAD_DATA;
			} /* fread failed */
			}
		}
		//sanity check for too large data
		unsigned char **extraData = NULL;  
		//if fread still reads in pixels 
		//than the image data is too large
		scanCount = fread(&extraData, 1, 1, inputFile);

		/* sanity check	              */
		if (scanCount == 1)
		{ /* fread failed */
			/* free memory           */
			free(theImage->commentLine);
			free(theImage->imageData);

			/* close file            */
			fclose(inputFile);

			/* print error message   */
			printf("ERROR: Bad Data (%s)\n", filename); 

			/* and return            */
			return EXIT_BAD_DATA;
		} /* fread failed */

	return EXIT_NO_ERRORS;
	}
	

		//3rd read function to read in the ASCII data
	int pgmReadAsciiData(pgmImage *theImage, char *filename, FILE* inputFile)
	{
		//counter checks if fscanf reads in the data	
		int scanCount = -1;
		//using a 2d array to read in each pixel with image data
		for(int i = 0; i < theImage->height; i++)
		{
			for(int j = 0; j < theImage->width; j++)
			{
				//reading in each pixel
				scanCount = fscanf( inputFile, " %u", &theImage->imageData[i][j]);
		
			/* sanity check	                 */
			if ((scanCount != 1) || (theImage->imageData[i][j] < 0) || (theImage->imageData[i][j] > 255))
			{ /* fscanf failed */
				/* free memory           */
				free(theImage->commentLine);
				free(theImage->imageData);

				/* close file            */
				fclose(inputFile);

				/* print error message   */
				printf("ERROR: Bad Data (%s)\n", filename); 

				/* and return            */
				return EXIT_BAD_DATA;
			} /* fscanf failed */
				
			}
		}
		//sanity check for too large data
		unsigned char **extraData = NULL;  
		//if fread still reads in pixels 
		//than the image data is too large
		scanCount = fscanf( inputFile, " %u", &extraData);

		/* sanity check	                 */
		if (scanCount == 1)
		{ /* fscanf failed */
			/* free memory           */
			free(theImage->commentLine);
			free(theImage->imageData);

			/* close file            */
			fclose(inputFile);

			/* print error message   */
			printf("ERROR: Bad Data (%s)\n", filename); 

			/* and return            */
			return EXIT_BAD_DATA;
		} /* fscanf failed */

	
		return EXIT_NO_ERRORS;
		}



