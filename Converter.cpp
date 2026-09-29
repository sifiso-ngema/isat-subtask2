#include <iostream>
#include <string>
using namespace std;

string decimalToBinary(int decimalValue)
{
    if (decimalValue == 0)
        return "0";
    string binary = "";
    int value = decimalValue;
    while (value > 0)
    {
        int remainder = value % 2;
        binary = to_string(remainder) + binary;
        value = value / 2;
    }
    return binary;
}

int binaryToDecimal(string binaryValue)
{
    int decimal = 0;
    int power = 0;
    for (int i = binaryValue.length() - 1; i >= 0; i--)
    {
        if (binaryValue[i] == '1')
        {
            int placeValue = 1;
            for (int p = 0; p < power; p++)
                placeValue *= 2;
            decimal += placeValue;
        }
        power++;
    }
    return decimal;
}

string decimalToHexadecimal(int decimalValue)
{
    if (decimalValue == 0)
        return "0";
    string hexDigits = "0123456789ABCDEF";
    string hexResult = "";
    int value = decimalValue;
    while (value > 0)
    {
        int remainder = value % 16;
        hexResult = hexDigits[remainder] + hexResult;
        value = value / 16;
    }
    return hexResult;
}

int hexadecimalToDecimal(string hexValue)
{
    string hexDigits = "0123456789ABCDEF";
    int decimal = 0;
    int power = 0;
    for (int i = hexValue.length() - 1; i >= 0; i--)
    {
        char c = toupper(hexValue[i]);
        int digitValue = hexDigits.find(c);
        int placeValue = 1;
        for (int p = 0; p < power; p++)
            placeValue *= 16;
        decimal += digitValue * placeValue;
        power++;
    }
    return decimal;
}

void displayMenu()
{
    cout << "Conversion Menu:" << endl;
    cout << "1. Convert Decimal to Binary" << endl;
    cout << "2. Convert Binary to Decimal" << endl;
    cout << "3. Convert Hexadecimal to Decimal" << endl;
    cout << "4. Convert Decimal to Hexadecimal" << endl;
    cout << "5. Exit" << endl;
}

int main()
{
    int choice;
    bool running = true;

    while (running)
    {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int decimalNum;
                cout << "Enter a decimal number: ";
                cin >> decimalNum;
                cout << "Binary representation: " << decimalToBinary(decimalNum) << endl;
                break;
            }
            case 2:
            {
                string binaryNum;
                cout << "Enter a binary number: ";
                cin >> binaryNum;
                cout << "Decimal representation: " << binaryToDecimal(binaryNum) << endl;
                break;
            }
            case 3:
            {
                string hexNum;
                cout << "Enter a hexadecimal number: ";
                cin >> hexNum;
                cout << "Decimal representation: " << hexadecimalToDecimal(hexNum) << endl;
                break;
            }
            case 4:
            {
                int decimalNum;
                cout << "Enter a decimal number: ";
                cin >> decimalNum;
                cout << "Hexadecimal representation: " << decimalToHexadecimal(decimalNum) << endl;
                break;
            }
            case 5:
            {
                cout << "Exiting the program." << endl;
                running = false;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
        cout << endl;
    }
    return 0;
}
