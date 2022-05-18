#include <iostream>
using namespace std;

class grades
{

private:
float *array;
int numofgrades;

public:
~grades(){
	delete[] array;
}
void setarraynum(int n){
	numofgrades = n;
	array = new float[numofgrades];
}
void setgrade(float g, int i){
	*(array + i) = g;
}
void printall(){
	float sum, avg;
	for(int i = 0; i < numofgrades; i++){
		cout << *(array + i) << endl;
		sum += *(array + i);
	}
	avg = sum/numofgrades;
	cout << "AVG: " << avg << endl;
}
};