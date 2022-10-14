#include <iostream>
#include <iomanip>

using namespace std;

void commas(int, string);

int main()
{
    int numbers;
    string currNum = "";
    int arrNums[13];
    string nums[13] = {"", "", "", "", "", "", "", "", "", "", "", "", ""};
    int numberSize[13];
    string tempProduct[13];
    int products[13];
    int sumSize, productSize;
    int sumTotal = 0, productTotal = 1;
    string commaSum = "", commaProduct = "";
    int k = 1;

    cout << "This program adds 2 and up to 13 very large numbers accurately."
            "\nIt multiplies the first 2 number and shows the intermediate steps of the product.";

    cout << endl
         << "How many numbers? -> ";
    cin >> numbers;
    while (1)
    {
        if (numbers < 2 || numbers > 13 || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Error the number must be between 2-13" << endl;
            cin >> numbers;
        }
        if (numbers >= 2 && numbers <= 13 && !cin.fail())
        {
            break;
        }
    }
    // Getting values
    for (int i = 0; i < numbers; i++)
    {
        cout << "Input number #" << i + 1 << " ->";
        cin >> arrNums[i];
        nums[i] = to_string(arrNums[i]);
        while (1)
        {
            if (cin.fail())
            {
                cout << "Invalid input, please try again: ";
                cin.clear();
                cin.ignore();
                cin >> arrNums[i];
            }
            if (!cin.fail())
            {
                break;
            }
        }
        cout << endl;
        sumTotal += arrNums[i];

        if (nums[i].size() >= 4 && nums[i].size() <= 6)
        {
            numberSize[i] = nums[i].size() + 1;
        }
        else if (nums[i].size() >= 7 && nums[i].size() <= 9)
        {
            numberSize[i] = nums[i].size() + 2;
        }
        else if (nums[i].size() >= 10 && nums[i].size() <= 12)
        {
            numberSize[i] = nums[i].size() + 3;
        }
        else
        {
            numberSize[i] = nums[i].size();
        }
    }
    productTotal = arrNums[0] * arrNums[numbers - 1];
    // Setting spaces and adding commas
    cout << "The sum of:" << endl
         << endl;
    for (int i = 0; i < numbers; i++)
    {
        cout << endl;
        for (int j = 0; j < 21 - numberSize[i]; j++)
        {
            cout << ' ';
        }
        commas(arrNums[i], currNum);
        if (i == numbers - 1)
        {
            cout << endl
                 << "+)" << endl
                 << "---------------------" << endl;
        }
    }
    string sumHold = to_string(sumTotal);
    if (sumHold.size() >= 4 && sumHold.size() <= 6)
    {
        sumSize = sumHold.size() + 1;
    }
    else if (sumHold.size() >= 7 && sumHold.size() <= 9)
    {
        sumSize = sumHold.size() + 2;
    }
    else if (sumHold.size() >= 10 && sumHold.size() <= 12)
    {
        sumSize = sumHold.size() + 3;
    }
    else
    {
        sumSize = sumHold.size();
    }
    int counter = 0, counter2 = 0, holder = sumTotal, holder2 = productTotal;
    for (int i = 0; i < 21 - sumSize; i++)
    {
        cout << ' ';
    }
    commas(sumTotal, commaSum);

    // multiplication
    cout << endl
         << endl
         << endl;
    cout << "The product of: " << endl
         << endl;
    while (holder2 > 0)
    {
        holder2 = holder2 / 10;
        counter2++;
    }
    int digits, numDigits = 0, multiple = 1;
    digits = stoi(nums[numbers - 1]);
    while (digits > 0)
    {
        digits = digits / 10;
        numDigits++;
    }
    for (int i = 1; i < numDigits; i++)
    {
        multiple *= 10;
    }
    string lastNum = nums[numbers - 1];
    int oneNum = 0;
    string commaOneNum;
    for (int i = 0; i < lastNum.size(); i++)
    {
        commaOneNum = lastNum[i];
        oneNum = stoi(commaOneNum);
        tempProduct[i] = to_string((oneNum * multiple) * arrNums[0]);
        multiple /= 10;
        counter++;
    }
    for (int i = 0; i < numbers; i++)
    {
        cout << endl;
        for (int j = 0; j < 21 - numberSize[i]; j++)
        {
            cout << ' ';
        }
        commas(arrNums[i], currNum);
        if (i == numbers - 1)
        {
            cout << endl
                 << "*)" << endl
                 << "---------------------" << endl;
        }
    }
    for (int i = 0; i < counter; i++)
    {
        numberSize[i] = tempProduct[i].size();
        if (tempProduct[i].size() >= 4 && tempProduct[i].size() <= 6)
        {
            numberSize[i] = tempProduct[i].size() + 1;
        }
        else if (tempProduct[i].size() >= 7 && tempProduct[i].size() <= 9)
        {
            numberSize[i] = tempProduct[i].size() + 2;
        }
        else if (tempProduct[i].size() >= 10 && tempProduct[i].size() <= 12)
        {
            numberSize[i] = tempProduct[i].size() + 3;
        }
        else if (tempProduct[i].size() >= 13 && tempProduct[i].size() <= 15)
        {
            numberSize[i] = tempProduct[i].size() + 4;
        }
        else
        {
            numberSize[i] = tempProduct[i].size();
        }
    }
    for (int i = 0; i < counter; i++)
    {
        cout << endl;
        for (int j = 0; j < 21 - numberSize[i]; j++)
        {
            cout << ' ';
        }
        commas(stoi(tempProduct[i]), currNum);
        if (i == counter - 1)
        {
            cout << endl
                 << "+)" << endl
                 << "---------------------" << endl;
        }
    }
    if (commaProduct.size() >= 4 && commaProduct.size() <= 6)
    {
        counter2 = commaProduct.size() + 1;
    }
    else if (commaProduct.size() >= 7 && commaProduct.size() <= 9)
    {
        counter2 = commaProduct.size() + 2;
    }
    else if (commaProduct.size() >= 10 && commaProduct.size() <= 12)
    {
        counter2 = commaProduct.size() + 3;
    }
    else
    {
        counter2 = commaProduct.size();
    }
    for (int i = 0; i < 13 - counter2; i++)
    {
        cout << ' ';
    }
    commas(productTotal, currNum);
}

void commas(int n, string currNum)
{
    int split = 1000;
    currNum = "";
    string number = to_string(n);
    // unsigned int offset = num % 3;
    if (n < split)
    {
        currNum += to_string(n);
    }
    else
    {
        int remainder = n % split;
        commas(n / split, currNum);
        currNum += ',';
        currNum += to_string(remainder);
    }
    for (int i = 0; i < number.size(); i++)
    {
        if (i % 3 == 0 && number.size() % 3 != 0 && i != 0)
        {
        }
    }
    cout << currNum;
}
