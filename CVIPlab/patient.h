#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *p[9];
char *d[9];

int PatientID();
const char * PatientName();
void NewPatient();
void DeletePatient();
void AllPatient();


void NewPatient()
	{
		FILE *ptr_file;
		int x;
		
		char name[50];
		fgets( name, 50, stdin );
		ptr_file =fopen("input.txt", "a");

		for( x=0; x < strlen(name)-1; x++)
			fputc(name[x], ptr_file);
		fputs(".",ptr_file);
		fclose(ptr_file);
	}

void NewDiagnosis(int pn, int diag)
	{
		FILE *ptr_file;
		int x;
		int n = pn-1;
		char *d= "Diagnosis 1";
		char *name;
		char buf[200];
		int i = 0;
		int j = 1;


		ptr_file =fopen("input.txt","r");
			while (fgets(buf,1000, ptr_file)!=NULL){i++;}
			p[0] = strtok(buf, ".");
			for (j = 1; j < 10; j++)
				p[j]= strtok(NULL, ".");


		name = p[n];
		ptr_file =fopen("diagnosis.txt", "a");
		fputs(name, ptr_file);
		fputs(" ",ptr_file);
		fputs(d, ptr_file);
		fputs(".",ptr_file);
		fclose(ptr_file);
	}

void DeletePatient(int n)
	{
		FILE *ptr_file;
		int m = n-1;
		int x;
		char buf[200];
		int i = 0;
		int j = 1;
			
    		ptr_file =fopen("input.txt","r");
			while (fgets(buf,1000, ptr_file)!=NULL){i++;}
			p[0] = strtok(buf, ".");
			for (j = 1; j < 10; j++)
				p[j]= strtok(NULL, ".");



		
		ptr_file =fopen("input.txt", "w");
		for( x=0; x < 10; x++){
			if (p[x] != NULL && x !=m){
				fprintf(ptr_file,"%s", p[x]);
				fputs(".",ptr_file);
			}
		}
		fclose(ptr_file);
	}


void AllPatient(){

FILE *ptr_file;
    		char buf[200];
			int i = 0;
			int j = 1;
			
    		ptr_file =fopen("input.txt","r");
    		
			while (fgets(buf,1000, ptr_file)!=NULL){i++;}
			
			p[0] = strtok(buf, ".");
			
			for (j = 1; j < 10; j++)
				p[j]= strtok(NULL, ".");

			for (j = 0; j < 10; j++){
				if(p[j] != NULL)
					printf("%i. %s\n", j+1, p[j]);
			}	

		fclose(ptr_file);
}

void DiagnosisPatient(){

FILE *ptr_file;
    		char buf[200];
			int i = 0;
			int j = 1;
			
    		ptr_file =fopen("diagnosis.txt","r");
    		
			while (fgets(buf,1000, ptr_file)!=NULL){i++;}
			
			p[0] = strtok(buf, ".");
			
			for (j = 1; j < 10; j++)
				p[j]= strtok(NULL, ".");

			for (j = 0; j < 10; j++){
				if(p[j] != NULL)
					printf("%i. %s\n", j+1, p[j]);
			}	

		fclose(ptr_file);
}

const char *PatientName(){
	char *temp = "Austin";
	return temp;
	
}

