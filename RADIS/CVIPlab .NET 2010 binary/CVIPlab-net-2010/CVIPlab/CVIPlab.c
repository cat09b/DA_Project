/* =========================================================================
*
*   Computer Vision and Image Processing Lab - Dr. Scott Umbaugh SIUE
* 
* =========================================================================
*
*             File Name: CVIPlab.c 
*           Description: This  is the skeleton program for the Computer Vision
*			 and Image Processing Labs
*   Initial Coding Date: April 23, 1996
*   Last update Date: June 26, 2004
*   .NET version:     September 21, 2006
*           Portability: Standard (ANSI) C
*             Credit(s): Scott Umbaugh, Zhen Li, Kun Luo,Dejun Zhang,Wenjun(Evan) Bian
*                        Southern Illinois University Edwardsville
*  Copyright (C) 2004 Scott Umbaugh and SIUE
* 
*  Permission to use, copy, modify, and distribute this software and its
*  documentation for any non-commercial purpose and without fee is hereby
*  granted, provided that the above copyright notice appear in all copies
*  and that both that copyright notice and this permission notice appear
*  in supporting documentation.  This software is provided "as is"
*  without express or implied warranty.
* 
****************************************************************************/

/*
** include header files
*/
#include <math.h>
#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"
#include "CVIPobject.h"
#include "ObjectContour.h"
#include "CVIPhisto.h" 
#include  "CVIPmap.h"  
#include  "CVIPview.h"
#include "CVIPobject.h" 
#include "stdio.h"
 #include "threshold.h"


#define CASE_MAX 20

/* Put the command here, as VIDEO_APP, to run your image acquisition 
application program */

#define VIDEO_APP "explorer.exe"

/*
** function declarations
*/

Image *threshold_Setup(Image *inputImage);
Image *input();
double *hist_feature(Image *originalImage, Image *labeledImage, int r, int c);
Image * label( const Image *imageP );
void histogram();
/*
** start main funct
*/
void main_cviplab(){
	IMAGE_FORMAT  format;     	/* the input image format */
	Image		  *cvipImage; 	/* pointer to the CVIP Image structure */
	Image		  *cvipImage1; 	/* pointer to the CVIP Image structure */
	char		  *outputfile;	/* output file name */	
	int			  choice;
	CVIP_BOOLEAN  done = CVIP_NO; 
	 

	print_CVIP("\n\n\n\n***************************************");
	print_CVIP("****************************  ");
	print_CVIP("\n*\t\t Computer Vision and Image Processing Lab\t  *");
	print_CVIP("\n*\t\t\t RADIS \t\t\t  *");
	print_CVIP("\n******************************************");
	print_CVIP("*************************\n\n\n");
	
	while(!done) {  
		print_CVIP("\t\t0.\tExit \n");
		print_CVIP("\t\t1.\tGrab and Snap an Image  \n");
		print_CVIP("\t\t2.\tThreshold Operation \n");
		print_CVIP("\t\t3.\tHistogram features \n");
		print_CVIP("\n\nCVIPlab>>"); 

	
		/* 
		** obtain an integer between 0 and CASE_MAX from the user
		*/
		choice = getInt_CVIP(10, 0, CASE_MAX);
		
		switch(choice) {
			
		case 0: 
			done=CVIP_YES;
			break;
			
		case 1: 
			//if ( ShellExecute(NULL,"Open",VIDEO_APP,NULL,NULL, SW_SHOW )<= 32)
			print_CVIP("Error while running Video Program");
			break;
			
		case 2: 
			/*Get the input image */
			cvipImage = input();
			if(cvipImage == NULL) 
			{
				error_CVIP("main", "could not read input image");
				break;
			}
			
			/* calls the threshold function */
			cvipImage = threshold_Setup(cvipImage); 
			if (!cvipImage) 
			{
				error_CVIP("main", "threshold fails");
				break;
			}
			
			/*
			** display the resultant image
			*/
			view_Image(cvipImage,"threshold");

			delete_Image (cvipImage);
			
			break;
		case 3:
            /*Get the input image */
			cvipImage = input();
			if(cvipImage == NULL) 
			{
				error_CVIP("main", "could not read input image");
				break;
			}  
			
			histogram();
			break;


		default:
			print_CVIP("Sorry ! You Entered a wrong choice ");
			break;
		}
	}
}  
/* 
** end of the function main 
*/


/* 
** The following function reads in the image file specified by the user,
** stores the data and other image info. in a CVIPtools Image structure,
** and displays the image.
*/

Image* input(){   
	char  		*inputfile;
	Image		*cvipImage;
	
	/* 
	** get the name of the file and stores it in the string 'inputfile ' 
	*/	
	print_CVIP("\n\t\tEnter the Input File Name:  "); 	
	inputfile = getString_CVIP();
	
	/*  
	** creates the CVIPtools Image structure from the input file 
	*/
	cvipImage = read_Image(inputfile, 1);
	if(cvipImage == NULL) {
		error_CVIP("init_Image", "could not read image file");
		free(inputfile);
		return NULL;
	}
	
	/*
	** display the source image
	*/
	view_Image(cvipImage,inputfile);

	/*
	**IMPORTANT: free the dynamic allocated memory when it is not needed
	*/
	free(inputfile);
	
	return cvipImage;       
}   


/*
** The following setup function asks the threshold value from the user. After
** it gets the threshold value, it will call the threshold_Image() function. 
*/

Image *threshold_Setup(Image *inputImage){
	unsigned int 	threshval;      /* Threshold value */	
	
/* 
** Gets a value between between 0 and 255 for threshsold 
	*/
	print_CVIP("\n\t\tEnter the threshold value:  ");
	threshval = getInt_CVIP(10, 0, 255);
	
	return threshold_lab(inputImage, threshval);
}

void histogram(){
	Image  *inputImage,  *labeledImage, *inputImage_dup;
    int rows, cols, r, c;
    char *inputfile;
    double *result;
 
    //setDisplay_Image("picture", "Default");
    print_CVIP("Enter the Input File Name:  ");
    inputfile = (char *) getString_CVIP();
    inputImage = read_Image( inputfile ,1);
    view_Image(inputImage,inputfile);
	inputImage_dup = duplicate_Image( inputImage );
	labeledImage =  label(  threshold_segment(  inputImage,128, CVIP_NO) );
 
    rows = getNoOfRows_Image(labeledImage);
    cols = getNoOfCols_Image(labeledImage);
 
    print_CVIP("Enter the row coordinate of a point  on the labled image: ");
    r = getInt_CVIP(10, 0, rows);
    print_CVIP("E the col coordinate of a point  on the labled image: ");
    c = getInt_CVIP(10, 0, cols);
 
    result =   hist_feature(inputImage_dup,  labeledImage, r, c);
 
    print_CVIP("Histogram feature:0");
    print_CVIP(" mean = %f00", result[0] );
    print_CVIP(" standard deviation = %f00", result[1] );
    print_CVIP(" skew = %f00", result[2]) ;
    print_CVIP(" energy = %f00", result[3]) ;
    print_CVIP(" entropy = %f00", result[4]) ;
 
    delete_Image ( inputImage );
    delete_Image ( labeledImage );
    delete_Image ( inputImage_dup );

}
