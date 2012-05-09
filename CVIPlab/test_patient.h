
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Patient{
public:
	/*!
	* @brief	Patient constructor
	*
	* sets it to patient name: John Doe, with symptoms: none
	*/
	Patient();
	
	/*!
	* @brief	Set Patient function
	*
	* orders input to set patientid as int, firstName as string, and lastName as string.
	*/
	void setPatient();
	
	/*!
	* @brief	Print Patient Function
	*
	* cout of patient info in the form of: "patientID firstName lastName"
	*/
	void printPatient();
	
	/*!
	* @brief	setAllergies Function
	*
	* cin order for allergies of patient as string
	*/
	void setAllergies();
	
	/*!
	* @brief	setSymptoms function
	*
	* asks for three different symptoms of the patient to be taken through getline
	*/
	void setSymptoms();
	
	/*!
	* @brief	getSymptom1 function
	*
	* @return symptom1 as a string
	*/
	string getSymptom1();
	
	/*!
	* @brief	getSymptom2 function
	*
	* @return symptom2 as a string
	*/
	string getSymptom2();	
	
	/*!
	* @brief	getSymptom3 function
	*
	* @return symptom3 as a string
	*/
	string getSymptom3();		
	
	/*!
	* @brief	getStatus function
	*
	* @return scan status as a string
	*/
	string getStatus();
	
private:
	int patientID;
	string firstName;
	string lastName;
	string allergies;
	string symptom1;
	string symptom2;
	string symptom3;
	string status;	
	
};

Patient::Patient()
{
	patientID = 0;
	firstName = "John";
	lastName = "Doe";
	allergies = "None";
	symptom1 = "None";
	symptom2 = "None";
	symptom3 = "None";
	status = "abnormal";	
	
}

void Patient::setPatient()
{
	cout << "Enter patient ID: ";
	cin >> patientID;
	cout << "Enter patient first name: ";
	cin >> firstName;
	cout << "Enter patient last name: ";
	cin >> lastName;
}

void Patient::printPatient()
{
	cout << patientID << " " << firstName << " " << lastName;
}	

void Patient::setAllergies()
{
	cout << "Enter patient allergies: ";
	cin >> allergies;
}

void Patient::setSymptoms()
{
string junk;
	cout << "Enter patient symptom 1: ";
	getline(cin, junk);
	getline(cin, symptom1);
	cout << "Enter patient symptom 2: ";
	getline(cin, symptom2);
	cout << "Enter patient symptom 3: ";
	getline(cin, symptom3);
}

string Patient::getSymptom1()
{
return symptom1;
}

string Patient::getSymptom2()
{
return symptom2;
}

string Patient::getSymptom3()
{
return symptom3;
}
	
string Patient::getStatus()
{
	return status;
}
