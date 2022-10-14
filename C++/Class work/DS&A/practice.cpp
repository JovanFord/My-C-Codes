#include <iostream>
#include <iomanip>
using namespace std;

void splitName(string &);

void print_with_commas(int n)
{
    int split = 1000;

    if (n < split)
    {
        cout << n;
    }
    else
    {
        int remainder = n % split;
        print_with_commas(n / split);
        cout << ',' << remainder;
    }
}

int main()
{
    string num = "123456789000";
    string tempNum;
    string finalNum;
    unsigned int lol = num.size() - 3;
    int v = 91000000;
    auto s = std::to_string(v);

    int n = s.length() - 3;
    int end = (v >= 0) ? 0 : 1; // Support for negative numbers
    while (n > 0)
    {
        s.insert(n, ",");
        n -= 3;
    }

    cout << s;
}