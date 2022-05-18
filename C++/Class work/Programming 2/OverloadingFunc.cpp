#include <iostream>
#include <iomanip>
using namespace std;

/*
Write a program that computes and displays the charges for a patient’s hospital stay. First, the program should ask if the patient was admitted as an inpatient or an outpatient. If the patient was an inpatient, the following data should be entered:
	The number of days spent in the hospital
	The daily rate
	Hospital medication charges
	Charges for hospital services (lab tests, etc)
The program should ask for the following data if the patient was an outpatient:	
	Charges for hospital services (lab tests, etc.)
	Hospital medication charges
The program should use two overloaded functions to calculate the total charges. One of the functions should accept arguments for the inpatient data, while the other function accepts arguments for outpatient information. Both functions should return the total charges. ** Do not accept negative numbers for any data.
*/

double patient(double hospCharge, double medCharge);

double patient(double hospCharge, double medCharge, double dailyRate, int numDays);

int main() {
	double hospCharge;
	double medCharge;
	double dailyRate;
	int numDays;
	int inOrOut;
	cout << "Welcome to the payment portal! Was your patient an\nInpatient (1)\nor an\nOutpatient? (2)\n";
	cin >> inOrOut;
	if (inOrOut == 1){
		do{
		cout << "Please enter in your hospital charges: ";
		cin >> hospCharge;
		}while(hospCharge < 0);
		do{
		cout << "Please enter in your medicine charges: ";
		cin >> medCharge;
		}while(medCharge < 0);
		do{
		cout << "Please enter in your daily rate: ";
		cin >> dailyRate;
		}while(dailyRate < 0);
		do{
		cout << "Please enter in your number of days stayed with us: ";
		cin >> numDays;
		}while(numDays < 0);
		cout << setprecision(9) << "Total payment: $" << patient(hospCharge, medCharge, dailyRate, numDays);
		}
	if (inOrOut == 2){
		do{
		cout << "Please enter in your hospital charges: ";
		cin >> hospCharge;
		}while(hospCharge < 0);
		do{
		cout << "Please enter in your medicine charges: ";
		cin >> medCharge;
		}while(medCharge < 0);
		cout << setprecision(9) << "Total payment: $" << patient(hospCharge, medCharge);
		}
}

double patient(double hospCharge, double medCharge){
	double total = hospCharge + medCharge;
	return total;
}

double patient(double hospCharge, double medCharge, double dailyRate, int numDays){
	double totalCharge = hospCharge + medCharge;
	totalCharge += (dailyRate * numDays);
	return totalCharge;
}