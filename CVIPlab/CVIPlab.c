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

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"
#include <stdio.h>
#include "patient.h"
#include "Scans.h"



#define CASE_MAX 20

/* Put the command here, as VIDEO_APP, to run your image acquisition 
application program */

#define VIDEO_APP "explorer.exe"

/*
** function declarations
*/

/*Image *threshold_Setup(Image *inputImage);
Image *input();
int Print_Types();
const char *Brain_Scan();
const char *Brain_Chest();
const char *Brain_Lung();
*/
/*
** start main funct
*/
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


void main_cviplab(){
	IMAGE_FORMAT  format;     	/* the input image format */
	
	char	  *outputfile;	/* output file name */	
	int		  choice;
	char *status;	
	int id;
	char *fname;
	int select;
	int type;
	int diag;



	CVIP_BOOLEAN  done = CVIP_NO; 

	
	
	
	while(!done) {  
		print_CVIP("\t\t0.\tExit \n");
		print_CVIP("\t\t1.\tList Patients without Diagnosis \n");
		print_CVIP("\t\t2.\tAdd Patient \n");
		print_CVIP("\t\t3.\tList Patients with Diagnosis \n");
//	options for image processor.

		
choice = getInt_CVIP(10, 0, CASE_MAX);
	
		
	//	choice = 1;
		switch(choice) {
			
		case 0: 
			done=CVIP_YES;
			break;
		case 1: //List All Patients
			AllPatient();
			printf("Select Patient: ");
			pn = getInt_CVIP(10, 0, CASE_MAX);
			//patient info would be p[pn-1]
			type = Print_Types();
				switch(type){
					case 1: //case brain
						status = Brain_Scan();
						printf("%s", status);
						diag = Print_Diagnosis();
							switch(diag){
								case 1:
								printf("Diagnosis 1");
								NewDiagnosis(pn, diag);
								DeletePatient(pn);
								break; 
								case 2:
								printf("Diagnosis 2");
								NewDiagnosis(pn, diag);
								DeletePatient(pn);
								break; 
								case 3:
								printf("Diagnosis 3");
								NewDiagnosis(pn, diag);
								DeletePatient(pn);
								break; 
								}
					break; // end brain

					case 2: //case chest
						status = Chest_Scan();
						printf("%s", status);
						diag = Print_Diagnosis();
							switch(diag){
								case 1:
								printf("Diagnosis 1");
								NewDiagnosis(pn, diag);
								DeletePatient(pn);
								break; 
								case 2:
								printf("Diagnosis 2");
								NewDiagnosis(pn, diag);
								DeletePatient(pn);
								break; 
								case 3:
								printf("Diagnosis 3");
								NewDiagnosis(pn, diag);
								DeletePatient(pn);
								break; 
								}
					break; // end chest

					case 3: //case lung
						status = Lung_Scan();
						printf("%s", status);
						diag = Print_Diagnosis();
							switch(diag){
								case 1:
								printf("Diagnosis 1");
								NewDiagnosis(pn, diag);
								DeletePatient(pn);
								break; 
								case 2:
								printf("Diagnosis 2");
								NewDiagnosis(pn, diag);
								DeletePatient(pn);
								break; 
								case 3:
								printf("Diagnosis 3");
								NewDiagnosis(pn, diag);
								DeletePatient(pn);
								break; 
								}
					break; // end lung

							}
		break; // end Patients

		case 2: // Add New Patient;
			NewPatient();
			break;
		
		case 3:
			DiagnosisPatient();
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

int Print_Types()
{
	int temp;
	printf("Input type: \n");
	print_CVIP("\t\t1.\tBrain \n");
	print_CVIP("\t\t2.\tChest \n");
	print_CVIP("\t\t3.\tLung \n");
	temp = getInt_CVIP(10, 0, CASE_MAX);

	return temp;
}

int Print_Diagnosis()
{
	int temp;
	printf("Input diagnosis: \n");
	print_CVIP("\t\t1.\tD1 \n");
	print_CVIP("\t\t2.\tD2 \n");
	print_CVIP("\t\t3.\tD3 \n");
	temp = getInt_CVIP(10, 0, CASE_MAX);

	return temp;
}

