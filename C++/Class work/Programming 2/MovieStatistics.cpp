#include <iostream>
#include <array>

using namespace std;

int main (){

    int students;
    int avg = 0;

    cout << "How many students were surveyed? " << endl;
    cin >> students;

    int movies[students];

    for (int i = 0; i < students; i++){
        cout << "How many movies did student " << i + 1 << " watch?" << endl;
        cin >> movies[i];
        avg = avg + movies[i];
    }

    avg = avg / students;

    cout << "The average number of movies were " << avg;
}