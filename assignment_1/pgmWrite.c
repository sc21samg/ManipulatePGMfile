/***********************************/
/* Write file Routine              */
/***********************************/

/* library for I/O routines        */
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>


#include <string.h>

#include "pgmErrors.h"
#include "pgmImage.h"

/***********************************/
/* PGM Write Routine               */
/*                                 */
/* CLI parameters:                 */
/* argv[2]: output file name       */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/


int pgmWriteHeader(pgmImage *theImage, char *outFilename, FILE* outputFile)
	{ 

	/* check whether file opening worked     */
	if (outputFile == NULL)
		{ /* NULL output file */
		/* free memory                   */
		free(theImage->commentLine);
		free(theImage->imageData);

		/* print an error message        */
		printf("Error: Failed to write pgm image to file %s\n", outFilename);

		/* return an error code          */
		return EXIT_BAD_OUTPUT_FILE;
		} /* NULL output file */

	/* write magic number, size & gray value */
	size_t nBytesWritten = fprintf(outputFile, "%s\n%d %d\n%d\n", theImage->magic_Number, theImage->width, theImage->height, theImage->maxGray);

	/* check that dimensions wrote correctly */
	if (nBytesWritten < 0)
		{ /* dimensional write failed    */
		/* free memory                   */
		free(theImage->commentLine); 
		free(theImage->imageData);

		/* print an error message        */
		printf("Error: Failed to write pgm image to file %s\n", outFilename);

		/* return an error code          */
		return EXIT_BAD_OUTPUT_FILE;
		} /* dimensional write failed    */

	/* at this point, we are done and can exit with a success code */
	return EXIT_NO_ERRORS;
	} 


	int pgmWriteBinaryData(pgmImage *theImage, char *outFilename, FILE* outputFile)
	{
		//using a 2d array to write out each pixel read in image data
		for(int i = 0; i < theImage->height; i++)
		{
			for(int j = 0; j <  theImage->width; j++)
			{
				fwrite(&theImage->imageData[i][j], 1, 1, outputFile);

				/* sanity check on write         */
				if (theImage->imageData[i][j] < 0)
				{ /* data write failed   */
					/* free memory           */
					free(theImage->commentLine);
					free(theImage->imageData);

					/* print error message   */
					printf("Error: Failed to write pgm image to file %s\n", outFilename);

					/* return an error code  */
					return EXIT_BAD_OUTPUT_FILE;
				} /* data write failed   */
		}
	} 

	/* at this point, we are done and can exit with a success code */
		return EXIT_NO_ERRORS;
	}

	int pgmWriteAsciiData(pgmImage *theImage, char *outFilename, FILE* outputFile)
	{
		//using a 2d array to write out each pixel read in image data
		for(int i = 0; i < theImage->height; i++)
		{
			for(int j = 0; j <  theImage->width; j++)
			{
				fprintf(outputFile,"%u ", theImage->imageData[i][j]);

				/* sanity check on write         */
				if (theImage->imageData[i][j] < 0)
				{ /* data write failed   */
					/* free memory           */
					free(theImage->commentLine);
					free(theImage->imageData);

					/* print error message   */
					printf("Error: Failed to write pgm image to file %s\n", outFilename);

					/* return an error code  */
					return EXIT_BAD_OUTPUT_FILE;
				} /* data write failed   */
			}
			//condition so there isn't a newline at the end of the file
			if(i != theImage->height - 1)
			{
				fprintf(outputFile, "\n");
			}
		} 
	/* at this point, we are done and can exit with a success code */
		return EXIT_NO_ERRORS;
	}