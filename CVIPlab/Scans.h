#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"
#include <stdio.h>

Image *threshold_Setup(Image *inputImage);
Image *input();

Image	  *cvipImage; 	/* pointer to the CVIP Image structure */
Image	  *cvipImage1; 
Image	  *cvipImage2;
double mean;
double sd;
double base_mean;
int rows;
int cols;
int pixel_count;
double *result;
int i, k;
int pn;



const char *Brain_Scan(){
	char *temp;
	pixel_count=0;
	//should know mean/standard deviation of a normal brain
	base_mean = 128.916;//includes the highest point
	cvipImage = input();

	cvipImage1 = duplicate_Image(cvipImage);
	cvipImage2 = label( threshold_segment(cvipImage,128,CVIP_NO));

	rows = getNoOfRows_Image(cvipImage2);
	cols = getNoOfCols_Image(cvipImage2);

	mean = 0;
	sd=0;
								
	for ( i =0; i < cols; i+=5){
	  for ( k =0; k < rows; k+=5){
		  result =   hist_feature(cvipImage1, cvipImage2, k, i);
		  sd+= result[1];
		  mean += result[0];
		  pixel_count++;
		  }
	}
	//find average
	sd = sd/pixel_count;
	mean = mean/pixel_count;
	mean = mean+sd;

	 printf("%f",mean);
			   
	//compare base to input
									  
	if(mean > base_mean)
	  temp = "abnormal";
	else 
	  temp = "normal";

	return temp;
}



const char *Chest_Scan(){
	char *temp;
	pixel_count=0;
	//should know mean/standard deviation of a normal brain
	base_mean = 133.0;//includes the highest point
	cvipImage = input();

	cvipImage1 = duplicate_Image(cvipImage);
	cvipImage2 = label( threshold_segment(cvipImage,128,CVIP_NO));

	rows = getNoOfRows_Image(cvipImage2);
	cols = getNoOfCols_Image(cvipImage2);

	mean = 0;
	sd=0;
								
	for ( i =0; i < cols; i+=5){
	  for ( k =0; k < rows; k+=5){
		  result =   hist_feature(cvipImage1, cvipImage2, k, i);
		  sd+= result[1];
		  mean += result[0];
		  pixel_count++;
		  }
	}
	//find average
	sd = sd/pixel_count;
	mean = mean/pixel_count;
	mean = mean+sd;
	
	 printf("%f",mean);
	//compare base to input
									  
	if(mean > base_mean)
	  temp = "abnormal";
	else 
	  temp = "normal";

	return temp;
}

const char *Lung_Scan(){
	char *temp;
	pixel_count=0;
	//should know mean/standard deviation of a normal brain
	base_mean = 148.1;//includes the highest point
	cvipImage = input();

	cvipImage1 = duplicate_Image(cvipImage);
	cvipImage2 = label( threshold_segment(cvipImage,128,CVIP_NO));

	rows = getNoOfRows_Image(cvipImage2);
	cols = getNoOfCols_Image(cvipImage2);

	mean = 0;
	sd=0;
								
	for ( i =0; i < cols; i+=5){
	  for ( k =0; k < rows; k+=5){
		  result =   hist_feature(cvipImage1, cvipImage2, k, i);
		  sd+= result[1];
		  mean += result[0];
		  pixel_count++;
		  }
	}
	//find average
	sd = sd/pixel_count;
	mean = mean/pixel_count;
	mean = mean+sd;
	
	 printf("%f",mean);
	//compare base to input
									  
	if(mean > base_mean)
	  temp = "abnormal";
	else 
	  temp = "normal";

	return temp;
}

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