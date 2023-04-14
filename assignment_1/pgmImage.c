#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>


#include <string.h>

#include "pgmErrors.h"
#include "pgmImage.h"

//defining the standard image struct
int Image(pgmImage *image)
{

	//initializing all the image struct variables for easy access
    image->magic_number[0] = '0';
    image->magic_number[1] = '0';
	image->magic_Number = NULL;
	image->commentLine = NULL;
	image->height = 0;
	image->width = 0;
	image->maxGray = 255;
	image->imageData = NULL;
	image->nImageBytes = 0;


    return EXIT_NO_ERRORS;
}
