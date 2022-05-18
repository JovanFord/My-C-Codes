#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void coinToss();

int main()
{
	int times, i = 0;

    srand(static_cast<size_t>(time(nullptr)));  // <--- Noved and changed.
    
	cout << "How many times should the coin be tossed? ";  // <--- Removed the "end;". Puts input on the same line.
	cin >> times;

        cout << '\n';

	while (i < times)      //It shows the same answer 'x' times :(
	{
		coinToss();
		i++;
	}
}

void coinToss(){
	int num;

        rand();
    
	num = rand() % 2;

	if (num)
		cout << "Heads" << endl;
	else
		cout << "Tails" << endl;
}