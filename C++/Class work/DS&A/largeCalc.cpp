#include <iostream>
#include <iomanip>

using namespace std;

void addCommas(string[]);

int main(){
    int numbers;
    string numberHold;
    int arrNums[13];
    string nums[13];
    int sumTotal = 0, productTotal = 1;
    string commaSum = "", commaProduct = "";
    int k = 1;

    cout << "This program adds 2 and up to 13 very large numbers accurately."
    "\nIt multiplies the first 2 number and shows the intermediate steps of the product.";

    cout << endl << "How many numbers? -> ";
    cin >> numbers;
    while(1)
    {
        if (numbers < 2 || numbers > 13 || cin.fail()){
            cout << "Error the number must be between 2-13" << endl;
            cin >> numbers;
        }
        if (numbers >= 2 && numbers <= 13 && !cin.fail())
        {
            break;
        }
    }
    // Getting values
    // for (int i = 0; i < 13; i++)
    // {
    //     nums[i] = "             ";
    // }
    for (int i = 0; i < numbers; i++)
    {
        cout << "Input number #" << i + 1 << " ->";
        cin >> arrNums[i];
        nums[i] = to_string(arrNums[i]);
        while(k == 1)
        {
            if (cin.fail()){
                cin >> arrNums[i];
            }
            if (!cin.fail()){
                k++;
            }
        }
        cout << endl;
        sumTotal += arrNums[i];
        productTotal *= arrNums[i]; 
    }
    // Setting spaces and adding commas
    cout << "The sum of:" << endl << endl;
    for (int i = 0; i < numbers; i++)
    {
        string commaNum = " ";
        numberHold = nums[i];
        int counter = 0, holder = arrNums[i];
        while(holder > 0){
            holder = holder / 10;
            counter++;
        }
        for (int j = 0; j < numberHold.size(); j++)
        {
            // 123,456,789 
            // 12,345,678
            // 1,234,567
            // 12,345
            // 1234
            
            // comma first 
            if (numberHold.size() > 3 
            && j != numberHold.size() - 1
            && numberHold.size() % 3 == 0
            && j % 3 == 0)
            {
                commaNum += numberHold[j];
                commaNum += ',';
            }   
            // comma second
            else if (numberHold.size() > 3 
            && ((j) % 3 == 0) 
            && j != numberHold.size() - 1)
            {
                commaNum += numberHold[j];
                commaNum += ',';
            }
            // comma third
            else if (numberHold.size() > 3 
            && ((j) % 3 == 0) 
            && j != numberHold.size() - 1)
            {
                commaNum += numberHold[j];
                commaNum += ',';
            }
            // every other number
            else if (numberHold.size() < 3 
            || ((j) % 3 != 0) 
            || j == (numberHold.size() - 1) 
            || j == 0)
            {
                commaNum += numberHold[j];
            }
        }
        for (int j = 0; j < 13 - commaNum.size(); j++)
        {
            cout << ' ';
        } 
        cout << commaNum << endl;
        if(i == numbers - 1)
        {
            cout << "+)" << endl << "-------------" << endl;
        }
    }
    
    string sumHold = to_string(sumTotal);
    int counter = 0, counter2 = 0, holder = sumTotal, holder2 = productTotal;
    while(holder > 0){
        holder = holder / 10;
        counter++;
    }
    
    for (int i = 0; i < sumHold.size(); i++)
    {
        if (sumHold.size() > 3 && (i % 3 == 0) && i != sumHold.size() - 1)
        {
            commaSum += sumHold.at(i);
            commaSum += ',';
        }   
        else if (sumHold.size() < 3 || (i % 3 != 0) || i == (sumHold.size() - 1) || i == 0)
        {
            commaSum += sumHold.at(i);
        }
    }
    for (int i = 0; i < 13 - commaSum.size(); i++)
    {
        cout << ' ';
    } 
    cout << commaSum;
    // while(holder2 > 0){
    //     holder2 = holder2 / 10;
    //     counter2++;
    // }
    // cout << endl;
    // for (int j = 0; j < 13 - counter2; j++)
    // {
    //     cout << ' ';
    // } 
    // cout << productTotal;
}

void addCommas(string nums[]){
    int holder;
}